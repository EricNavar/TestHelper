#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <direct.h>
using namespace std;

struct TextFileHelper
{
	string currentDirectory;
	string defaultDirectory;
	vector<string> directory;
	TextFileHelper();
	void setFolderName(string fn);
	vector<string> readDirectory(bool extension) const;
	vector<string> readDirectory(string file, bool extention) const;
	void printDirectory();
	void combineFiles();
	string removeExtention(string fileName) const;
	string getCurrentWorkingDir();
};