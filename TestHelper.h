#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
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
};