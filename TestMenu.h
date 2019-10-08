#include "TextFileHelper.h"
#include "TestHelper.h"
#include <windows.h>
#include <filesystem>
using namespace std;

class TestMenu
{
public:
	void showMenu() const;
	void printOptions() const;
	void changeFolderNameMenu(TextFileHelper *t) const;
	void printDirectoryMenu(TextFileHelper *t) const;
};