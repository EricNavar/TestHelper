#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

void read_directory(const string& name, vector<string>& fileNames)
{
	string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			fileNames.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data)!=0);
		FindClose(hFind);
	}
}

int main()
{
	ofstream outfile;
	outfile.open("output.txt");
	vector<string> fileNames;
	read_directory("input/", fileNames);
	fileNames.erase(fileNames.begin(), fileNames.begin() + 2);

	if (!outfile.is_open())
		cout << "outfile is not open." << endl;

	ifstream infile;
	for (string s : fileNames)
	{
		outfile << s << endl;
		string line;
		infile.open("input/" + s);
		while (getline(infile, line, ' '))
			outfile << line << " ";
		outfile << endl;
		infile.close();
	}

	return 0;
}