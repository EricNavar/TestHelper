#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct TextFileHelper
{
	vector<string> directory;
	string folderName;
	void readDirectory(bool extension);
	void printDirectory();
	void combineFiles();
	string removeExtention(string fileName);
};

void TextFileHelper::readDirectory(bool extention)
{
	string pattern(folderName);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			string s = data.cFileName;
			if (extention) s = removeExtention(s);
			directory.push_back(s);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	directory.erase(directory.begin(), directory.begin() + 2);
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

string TextFileHelper::removeExtention(string fileName)
{
	return fileName.substr(0, fileName.find("."));
}

int main()
{
	cout << "1: printDirectory" << endl;
	cout << "2: combineFiles" << endl;
	cout << "0: Exit" << endl;
	bool extention;
	string folderName;
	int option = 1;
	TextFileHelper t;
	while (option != 0)
	{
		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Folder name: ";
			cin >> folderName;
			cout << "include extention? 0:no 1:yes ";
			cin >> extention;
			cout << "debug: extention: " << extention;
			if (t.directory.size() == 0) t.readDirectory(extention);
			t.printDirectory();
			break;
		case 2:
			cout << "Folder name: ";
			cin >> folderName;
			cout << "include extention? 0:no 1:yes ";
			cin >> extention;
			cout << "debug: extention: " << extention;
			if (t.directory.size() == 0) t.readDirectory(extention);
			t.combineFiles();
			break;
		}
	}

	return 0;
}