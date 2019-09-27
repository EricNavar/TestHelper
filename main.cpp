#include "TextFileHelper.h"
#include "TestHelper.h"
#include <windows.h>
using namespace std;

int main()
{
	bool extention;
	string folderName;
	int option = 1;
	TextFileHelper t;
	TestHelper TS;
	while (option != 0)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Folder name: ";
			cin >> folderName;
			cout << "include extention? 0:no 1:yes ";
			cin >> extention;
			cout << "debug: extention: " << extention;
			if (t.directory.size() == 0) 
				t.directory = t.readDirectory(extention);
			t.printDirectory();
			break;
		case 2:
			cout << "Folder name: ";
			cin >> folderName;
			cout << "include extention? 0:no 1:yes ";
			cin >> extention;
			cout << "debug: extention: " << extention;
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
		}
	}
	return 0;
}

void printMenu()
{
	cout << "1: printDirectory" << endl;
	cout << "2: combineFiles" << endl;
	cout << "3: verify files" << endl;
	cout << "4: print config" << endl;
	cout << "0: Exit" << endl;
}