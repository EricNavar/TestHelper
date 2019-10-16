#include "AddMul.h"
#include "TestHelper.h"
#include <sstream>
using namespace std;

void useTestHelper();
void addTest(string fileName);
vector<int> tokenize(string input);

void useTestHelper()
{
	void (*ptr)(string) = &addTest;

	TestHelper th;
	th.SetTestFunction(ptr);
	th.TestAllFiles();
}

void addTest(string input)
{
	vector<int> tokens = tokenize(input);
	AddMul am;
	int sum = am.add(tokens);
	int i, size = tokens.size();
	for (i = 0; i < size - 1; i++)
		cout << tokens[i] << "+";
	cout << tokens[i] << "=" << sum << endl;
}

vector<int> tokenize(string input)
{
	vector<int> tokens;
	stringstream check1(input);
	string intermediate;
	while (getline(check1, intermediate, ' '))
		tokens.push_back(stoi(intermediate));
	return tokens;
}

int main()
{
	TestMenu tm(addTest);
	return 0;
}