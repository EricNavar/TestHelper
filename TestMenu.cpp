#include "TestMenu.h"

void TestMenu::showMenu() const
{
	bool extention;
	string folderName;
	int option = 1;
	TextFileHelper t;
	TestHelper TS;
	vector<string> v;
	while (option != 0)
	{
		printOptions();
		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			if (t.directory.size() == 0) 
				t.directory = t.readDirectory(extention);
			t.printDirectory();
			break;
		case 2:
			if (t.directory.size() == 0)
				t.directory = t.readDirectory(extention);
			t.combineFiles();
			break;
		case 3:
			TS.verifyFiles();
			break;
		case 4:
			TS.printConfig();
			break;
		case 5:
			changeFolderNameMenu(&t);
			break;
		}
	}
}

void TestMenu::printOptions() const
{
	cout << "1: printDirectory" << endl;
	cout << "2: combineFiles" << endl;
	cout << "3: verify files" << endl;
	cout << "4: print config" << endl;
	cout << "5: set folder name of workspace" << endl;
	cout << "0: Exit" << endl;
}

void TestMenu::changeFolderNameMenu(TextFileHelper *t) const
{
	string menu = "1: set absolute directory\n2: set relative working directory\n";
	cout << menu;
	int option;
	cin >> option;
	cout << "enter working folder name:" << endl;
	bool inValidInput = true;
	string folderName;
	while (inValidInput)
	{
		cin >> folderName;
		if (option == 1)
		{
			inValidInput = false;
		}
		else if (option == 2)
		{
			folderName = t->getCurrentWorkingDir() + "\\" + folderName;
			inValidInput = false;
		}
		else
		{
			cout << "invalid input";
			cout << menu;
		}
	}
	t->setFolderName(folderName);
	cout << "The current working directory has been set to " << folderName << endl;
}