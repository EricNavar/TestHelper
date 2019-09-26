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