#include "AddMult.h"

int AddMul::add(vector<int> numbers)
{
    int result = 0;
    for (int i : numbers)
        result += i;
    return result;
}

int AddMul::multiply(vector<int> numbers)
{
    int result = 1;
    for (int i : numbers)
        result *= i;
    return result;
}

void addTest(string fileName)
{
    ifstream infile(filename);
    vector<int> tokens;
    int token;
    while (cin >> token)
        tokens.push_back(token);
    for (int i: tokens)
        cout << "token: " << i << endl;
    cout << add(numbers);
}