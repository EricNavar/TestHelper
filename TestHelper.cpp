#include "TestHelper.h"

TestHelper::TestHelper()
{
	readConfig();
	user_test = nullptr;
}

void TestHelper::readConfig()
{
	ifstream infile("Testing/config.txt");
	string line;
	getline(infile, line);
	inputFolderName = extractValue(line);
	getline(infile, line);
	inputFileExtension = extractValue(line);
	getline(infile, line);
	answerFolderName = extractValue(line);
	getline(infile, line);
	answerFileExtension = extractValue(line);
	getline(infile, line);
	singleLine = "true" == extractValue(line);
	getline(infile, line);
	filePrinting = "true" == extractValue(line);
	getline(infile, line);
}

//helper function readConfig()
string TestHelper::extractValue(string &line) const
{
	int i = line.find(":") + 1;
	return line.substr(i, line.size() - i);
}

TestHelper::TestHelper(void(user_test)(string))
{
	this->user_test = user_test;
	readConfig();
}

void TestHelper::SetTestFunction(void(user_test)(string))
{
	this->user_test = user_test;
}

void TestHelper::TestAllFiles()
{	
	//std::stringstream ss;

	if (user_test == nullptr)
		throw runtime_error("user_test not set!");

	ifstream inputFiles("Testing/fileNames.txt");
	if (!inputFiles.is_open())
	{
		cout << "could not open fileNames.txt open" << endl;
		return;
	}
	string fileName;
	
	while (getline(inputFiles, fileName))
	{
		cout << "testing " << fileName << "..." << endl;
		if (singleLine)
			TestFileByLine(fileName);
		else
			TestFile(fileName);
		cout << endl;
	}
}

//test each line individually because each test case is 1 line
//reads each line from input file who names is passed in
//the line is fed to the user test then executed and the time
//to execute is taken
void TestHelper::TestFileByLine(string fileName)
{
	string inputDirectory = inputFolderName + "/" + fileName + inputFileExtension;
	string answerDirectory = answerFolderName + "/" + fileName + answerFileExtension;
	ifstream inputfile(inputDirectory);
	ifstream answerfile(answerDirectory);
	if (!inputfile.is_open())
		cout << inputDirectory << " is not open!" << endl;
	if (!answerfile.is_open())
		cout << answerDirectory << " is not open!" << endl;
	string line;
	while (getline(inputfile, line))
	{
		cout << "mine:   ";
		auto time = timeFunction(line, user_test);
		getline(answerfile, line);
		cout << "answer: " << line << endl;
		cout << "Time to execute: " << time << endl;
	}
}

void TestHelper::TestFile(string fileName)
{
	ifstream inputfile(inputFolderName + "/" + fileName + inputFileExtension);
	ifstream answerfile(answerFolderName + "/" + fileName + answerFileExtension);
	string line;
	cout << "mine:   ";
	user_test(line);
	getline(answerfile, line);
	cout << "answer: " << line << endl;
	inputfile.close();
	answerfile.close();
}

bool TestHelper::verifyFiles() const
{
	TextFileHelper TH;
	vector<string> inputFiles = TH.readDirectory(inputFolderName, false);
	vector<string> answerFiles = TH.readDirectory(answerFolderName, false);
	if (inputFiles.size() != answerFiles.size())
		return false;
	int size = inputFiles.size();
	for (int i = 0; i < size; i++)
		if (inputFiles[i] != answerFiles[i])
			return false;
	return true;
}

void TestHelper::printConfig() const
{
	cout << "Configuration:" << endl;
	cout << inputFolderName << endl;
	cout << inputFileExtension << endl;
	cout << answerFolderName << endl;
	cout << answerFileExtension << endl;
	cout << singleLine << endl;
	cout << filePrinting << endl;
}