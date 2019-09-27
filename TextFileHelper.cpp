#include "TextFileHelper.h"

vector<string> TextFileHelper::readDirectory(bool extention) const
{
	string pattern(folderName);
	pattern.append("\\*");
	vector<string> dir;
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			string s = data.cFileName;
			if (!extention) 
				s = removeExtention(s);
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

void TextFileHelper::printDirectory()
{
	ofstream outfile;
	outfile.open("file_names.txt");
	for (string s : directory)
		outfile << s << endl;
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
		infile.open(folderName + "/" + s);
		while (getline(infile, line, ' '))
			outfile << line << " ";
		outfile << endl;
		infile.close();
	}
	outfile.close();
}

string TextFileHelper::removeExtention(string fileName) const
{
	return fileName.substr(0, fileName.find("."));
}