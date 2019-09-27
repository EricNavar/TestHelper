#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "TextFileHelper.h"
using namespace std;

class TestHelper
{
public:
	TestHelper();
	TestHelper(void(user_test)(string));
	void SetTestFunction(void(user_test)(string));
	void TestAllFiles();
	void TestFileByLine(string fileName);
	void TestFile(string fileName);
	vector<string> tokenize(const string infixExp) const;
	bool verifyFiles() const;
	void printConfig() const;
private:
	void(*user_test)(string);
	string extractValue(string &line) const;
	void readConfig();
	string inputFolderName;
	string inputFileExtension;
	string answerFolderName;
	string answerFileExtension;
	bool singleLine;
	bool filePrinting;
};