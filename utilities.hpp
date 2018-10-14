#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <limits>
#include "Slist_plus_sorts.hpp"
using namespace std;
/*
	this package includes:
	random;
	generating permutations;
	print an array;
	print an list;
	convert a list to an array;
*/
class Random {
public:
	Random(bool pseudo = false);
	double random_real();
	int random_int(int low, int high);
private:
	int reseed();
	int seed;
	int multiplier;
	int add_on;
};
int Random::reseed() {
	seed = seed * multiplier + add_on;
	return seed;
}
Random::Random(bool pseudo) {
	if (pseudo)
		seed = 1;
	else
		seed = time(NULL) % INT_MAX;
	multiplier = 2743;
	add_on = 5923;
}

double Random::random_real() {
	double max = INT_MAX + 1.0;
	double temp = reseed();
	if (temp < 0)
		temp = temp + max;
	return temp / max;
}
//from 0 to 1,[0,1)
int Random::random_int(int low, int high) {
	if (low > high)
	{
		return random_int(high, low);
	}
	else
	{
		return ((int)(high - low + 1)*random_real()) + low;
	}
}
Random random;
vector<int> random_data(int size, int low, int high)
{
	vector<int> res;
	for (int i = 0; i < size; i++)
	{
		res.push_back(random.random_int(low, high));
	}
	return res;
}
//---------------------------------------------------------------------
//print list
void print_list(Slist<int>& s, int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp;
		s.front(temp);
		cout << temp << " ";
		s.pop_front();
	}
	cout << endl;
}
//---------------------------------------------------------------------
//print list into arrays
vector<int> print_list_to_vec(Slist<int>& s,int n)
{
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		int temp;
		s.front(temp);
		res.push_back(temp);
		s.pop_front();
	}
	return res;
}
//---------------------------------------------------------------------
//print arrays
void print_arr(vector<int>& data) {
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
//---------------------------------------------------------------------
//generate permutations
void print_permus(vector<int>& data) {
	int i = 0;
	while(data[i]!=0)
	{
		cout << data[i] << " ";
		i = data[i];
	}
	cout << endl;
}
void permutation(int new_ele, int degree, vector<int>& perm)
{
	int current = 0;
	do {
		perm[new_ele] = perm[current];
		perm[current] = new_ele;
		if (new_ele == degree)
			print_permus(perm);
		else
			permutation(new_ele + 1, degree, perm);
		perm[current] = perm[new_ele];
		current = perm[current];
	} while (current != 0);
}