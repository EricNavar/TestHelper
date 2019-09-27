#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "TextFileHelper.h"
using namespace std;

struct TestHelper
{
	void(*user_test)(string);
	TestHelper();
	TestHelper(void(user_test)(string));
	void SetTestFunction(void(user_test)(string));
	void TestAllFiles(bool singleLine);
	void TestFileByLine(string fileName);
	void TestFile(string fileName);
	vector<string> tokenize(const string infixExp) const;
	bool verifyFiles() const;
};