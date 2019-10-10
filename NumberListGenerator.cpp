#include "NumberListGenerator.h"

void NumberListGenerator::menu()
{
    unsigned int option = 1;
    string fileName;
    string menu = "Which order should the list be created in?\n1) ascending\n2) descending\n3) random\n4)print list\n0) quit\n";
    while (option)
    {
        cout << "enter number of values: ";
        cin >> option;
        vector<int> v(option);
        cout << menu;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            createAscending(v);
            break;
        case 2:
            createDescending(v);
            break;
        case 3:
            createRandom(v);
            break;
        case 4:
            cout << "enter name of output file: ";
            cin >> fileName;
            printList(v, fileName);
            break;
        }
    }
}

void NumberListGenerator::createAscending(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        v[i]=i;
}

void NumberListGenerator::createDescending(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        v[i]=n-i;
}

//not the best function to create random list but it will do
void NumberListGenerator::createRandom(vector<int> &v)
{
    createAscending(v);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	auto rng = default_random_engine(seed);
	shuffle(begin(v), end(v), rng);
}

void NumberListGenerator::printList(vector<int> &v, string &fileName)
{
    ofstream out;
    out.open(fileName);
    int n = v.size();
    for (int i : v)
        out << i << " ";
    out.close();
    cout << "done printing" << endl;
}