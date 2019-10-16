#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "TextFileHelper.h"
#include "Timer.h"
#include "TestMenu.h"
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
	void printOptions() const;
private:
	string inputFolderName;
	string inputFileExtension;
	string answerFileExtension;
	string answerFolderName;
	bool singleLine;
	bool filePrinting;
	void(*user_test)(string);
	string extractValue(string &line) const;
	void readConfig();
};