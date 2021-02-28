#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
using namespace std;

class HashTable
{
public:
	HashTable();
	HashTable(int n);
	void Test();
	HashTable(const HashTable &copy);
	~HashTable();
	void insert(string obj);
	bool find(string target) const;
	int size() const;
	int maxSize() const;
	float loadFactor() const;

private:
	string* obj;
	int max;
	int key;
	int count;
	int Hash_func(string send) const;
	bool ISprime(int n) const;
	int Hash_func_2(int val) const;
	int nextPrime(int n);
};