#include "TextFileHelper.h"

TextFileHelper::TextFileHelper()
{
	defaultDirectory = getCurrentWorkingDir();
	currentDirectory = defaultDirectory;
}

vector<string> TextFileHelper::readDirectory(bool extension = true) const
{
	string pattern(currentDirectory);
	pattern.append("\\*");
	vector<string> dir;
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			string s = data.cFileName;
			if (!extension) 
				s = removeExtension(s);
			dir.push_back(s);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	dir.erase(dir.begin(), dir.begin() + 2);
	return dir;
}

vector<string> TextFileHelper::readDirectory(string file, bool extention) const
{
	string fileName = file;
	return readDirectory(extention);
}

void TextFileHelper::printDirectory(string fileName)
{
	ofstream outfile;
	outfile.open(fileName);
	for (string s : directory)
		outfile << s << endl;
	cout << "finished printing" << endl;
}

void TextFileHelper::combineFiles()
{
	ofstream outfile;
	outfile.open("combined_text.txt");

	if (!outfile.is_open())
		cout << "outfile is not open." << endl;

	ifstream infile;
	for (string s : directory)
	{
		string line;
		infile.open(currentDirectory + "/" + s);
		while (getline(infile, line, ' '))
			outfile << line << " ";
		outfile << endl;
		infile.close();
	}
	outfile.close();
}

string TextFileHelper::removeExtension(string fileName) const
{
	return fileName.substr(0, fileName.find("."));
}

void TextFileHelper::setFolderName(string fn)
{
	currentDirectory = fn;
}

string TextFileHelper::getCurrentWorkingDir()
{
	char buff[FILENAME_MAX];
	_getcwd(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

void TextFileHelper::filterDirectory(string &extension)
{
	vector<string> newDirectory;
	extension = '.' + extension;
	int size = directory.size();
	for (int i = 0; i < size; i++)
	{
		int index = directory[i].find(extension);
		if (index != string::npos)
			newDirectory.push_back(directory[i]);
	}
	directory = newDirectory;
}