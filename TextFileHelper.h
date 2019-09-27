#pragma once
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
	vector<string> readDirectory(bool extension) const;
	vector<string> readDirectory(string file, bool extention) const;
	void printDirectory();
	void combineFiles();
	string removeExtention(string fileName) const;
};