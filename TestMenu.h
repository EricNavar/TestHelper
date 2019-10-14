#include "TextFileHelper.h"
#include "TestHelper.h"
#include "NumberListGenerator.h"
//#include <windows.h>
//#include <filesystem>
using namespace std;

class TestMenu
{
public:
	void showMenu() const;
	void printOptions() const;
	void changeFolderNameMenu(TextFileHelper *t) const;
	void printDirectoryMenu(TextFileHelper *t) const;
	void numberListGeneratorMenu() const;
	void generatorOptionsMenu(NumberListGenerator *nlg, vector<int> &v) const;
};