#include "AddMul.h"

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