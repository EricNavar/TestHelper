#include "NumberListGenerator.h"

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