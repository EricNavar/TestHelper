#include "TestHelper.h"
#include "Combine.h"
#include <windows.h>
using namespace std;

int main()
{
	cout << "1: printDirectory" << endl;
	cout << "2: combineFiles" << endl;
	cout << "0: Exit" << endl;
	bool extention;
	string folderName;
	int option = 1;
	TextFileHelper t;
	while (option != 0)
	{
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
			if (t.directory.size() == 0) t.readDirectory(extention);
			t.printDirectory();
			break;
		case 2:
			cout << "Folder name: ";
			cin >> folderName;
			cout << "include extention? 0:no 1:yes ";
			cin >> extention;
			cout << "debug: extention: " << extention;
			if (t.directory.size() == 0) t.readDirectory(extention);
			t.combineFiles();
			break;
		}
	}

	return 0;
}