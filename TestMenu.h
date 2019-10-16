#pragma once
#include "TextFileHelper.h"
#include "TestHelper.h"
#include "NumberListGenerator.h"

using namespace std;

class TestMenu
{
public:
	TestMenu(void(*test)(string));
	void showMenu(void(*test)(string)) const;
	void printOptions() const;
	void changeFolderNameMenu(TextFileHelper *t) const;
	void printDirectoryMenu(TextFileHelper *t) const;
	void numberListGeneratorMenu() const;
	void generatorOptionsMenu(NumberListGenerator *nlg, vector<int> &v) const;
};