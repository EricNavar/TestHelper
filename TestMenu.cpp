#include "TestMenu.h"

TestMenu::TestMenu(void(*test)(string))
{
	showMenu(test);
}

void TestMenu::showMenu(void(*test)(string)) const
{
	bool extension;
	TestHelper th(test);
	string folderName, temp;
	int option = 1;
	TextFileHelper t;
	TestHelper TS;
	vector<string> v;
	while (option != 0)
	{
		printOptions();
		cout << "Enter an option: ";
		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			printDirectoryMenu(&t);
			break;
		case 2:
			cout << "include extension? 1:no, 2:yes ";
			cin >> extension;
			if (t.directory.size() == 0)
				t.directory = t.readDirectory(extension);
			t.combineFiles();
			break;
		case 3:
			if (TS.verifyFiles())
				cout << "input and output file names match" << endl;
			else
				cout << "input and output file names match" << endl;
			break;
		case 4:
			TS.printConfig();
			break;
		case 5:
			changeFolderNameMenu(&t);
			break;
		case 6:
			numberListGeneratorMenu();
			break;
		case 7:
			th.TestAllFiles();
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
	cout << "6: generate number list" << endl;
	cout << "7: run test cases" << endl;
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
			cout << "invalid input" << endl;
			cout << menu;
		}
		cin.clear();
	}
	t->setFolderName(folderName);
	t->directory.clear();
	cout << "The current working directory has been set to " << folderName << endl;
}

void TestMenu::printDirectoryMenu(TextFileHelper *t) const
{
	int option;
	bool extension;
	string temp;
	cout << "include extension? 1:no, 2:yes ";
	cin >> option;
	extension = option - 1;
	if (t->directory.size() == 0) 
		t->directory = t->readDirectory(extension);
	if (extension)
	{
		cout << "include only specific extension? 1:no, 2:yes ";
		cin >> option;
		if (option - 1)
		{
			cout << "Enter extension: .";
			cin >> temp;
			cout << "DEBUG: extension is " << temp;
			t->filterDirectory(temp);
		}
	}
	cout << "Enter name of file where names will be printed: ";
	cin >> temp;
	t->printDirectory(temp);
}

void TestMenu::numberListGeneratorMenu() const
{
    NumberListGenerator nlg;
	int option = 1;
    string fileName;
	vector<int> v;
	while (option)
	{
		if (!v.size())
		{
			generatorOptionsMenu(&nlg, v);
		}
		else
		{
			cout << "Enter an option:" << endl;
			cout << "1) generate numbers" << endl;
			cout << "2) print list" << endl;
			cout << "0) quit" << endl;
			cin >> option;
			if (option == 1)
			{
				generatorOptionsMenu(&nlg, v);
			}
			else if (option == 2)
			{
				cout << "Enter name of output file: ";
				cin >> fileName;
				nlg.printList(v,fileName);
			}
		}
	}
}

void TestMenu::generatorOptionsMenu(NumberListGenerator *nlg, vector<int> &v) const
{
	cout << "enter number of values: ";
	int option;
	cin >> option;
	v.resize(option);
	cout << "Which order should the list be created in?\n1) ascending\n2) descending\n3) random\n";;
	cin >> option;
	switch (option)
	{
	case 0:
		break;
	case 1:
		nlg->createAscending(v);
		break;
	case 2:
		nlg->createDescending(v);
		break;
	case 3:
		nlg->createRandom(v);
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}
}