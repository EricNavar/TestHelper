#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

void read_directory(const string& name, vector<string>& fileNames)
{
	ofstream outfile;
	outfile.open("file_names.txt");
	string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			string s = data.cFileName;
			fileNames.push_back(s);
			outfile << s << endl;
		} while (FindNextFile(hFind, &data)!=0);
		FindClose(hFind);
	}
	outfile.close();
}

int main()
{
	string folderName;
	cin >> folderName;
	ofstream outfile;
	outfile.open("combined_text.txt");
	vector<string> fileNames;
	read_directory(folderName + "/", fileNames);
	fileNames.erase(fileNames.begin(), fileNames.begin() + 2);

	if (!outfile.is_open())
		cout << "outfile is not open." << endl;

	ifstream infile;
	for (string s : fileNames)
	{
		string line;
		infile.open(folderName + "/" + s);
		while (getline(infile, line, ' '))
			outfile << line << " ";
		outfile << endl;
		infile.close();
	}
	outfile.close();

	return 0;
}