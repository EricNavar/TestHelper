#include "TestHelper.h"

TestHelper::TestHelper()
{
}

TestHelper::TestHelper(void(user_test)(string))
{
	this->user_test = user_test;
}

void TestHelper::SetTestFunction(void(user_test)(string))
{
	this->user_test = user_test;
}

void TestHelper::TestAllFiles(bool singleLine)
{	
	ifstream inputFiles("fileNames.txt");
	string fileName;
	
	while (getline(inputFiles, fileName))
	{
		cout << fileName << endl;
		if (singleLine)
			TestFileByLine(fileName);
		else
			TestFile(fileName);
		cout << endl;
	}
}

//test each line individually because each test case is 1 line
void TestHelper::TestFileByLine(string fileName)
{
	ifstream inputfile("testCaseInput/" + fileName + ".in");
	ifstream answerfile("testCaseAnswers/" + fileName + ".ans");
	string line;
	while (std::getline(inputfile, line))
	{
		cout << "mine:   ";
		user_test(line);
		getline(answerfile, line);
		cout << "answer: " << line << endl;
	}
}

void TestHelper::TestFile(string fileName)
{
	ifstream inputfile("testCaseInput/" + fileName + ".in");
	ifstream answerfile("testCaseAnswers/" + fileName + ".ans");
	string line;
	cout << "mine:   ";
	user_test(line);
	getline(answerfile, line);
	cout << "answer: " << line << endl;
}

bool verifyFiles()
{
	TextHelper TH;
	vector<string> inputFiles = TH.readDirectory("testCaseInput");
	vector<string> answerFiles = TH.readDirectory("testCaseAnswers");
	if (inputFiles.size() != answerFiles.size())
		return false;
	int size == inputFiles.size();
	for (int i = 0; i < size; i++)
		if (inputFiles[i] != answerFiles[i])
			return false;
	return true;
}