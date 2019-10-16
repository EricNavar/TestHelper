#pragma once
#include <random>
#include <algorithm>
#include <random>
#include <conio.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct NumberListGenerator
{
    void createAscending(vector<int> &v);
    void createDescending(vector<int> &v);
    void createRandom(vector<int> &v);
    void printList(vector<int> &v, string &fileName);
};