#pragma once
#include "primitives.hpp"
#include "Slist_plus_sorts.hpp"
#include <list>
#define HASH_SIZE 997
#define HASH_CHAINED_SIZE 17
template <class Key>
class hashTable_probing {
public:
	hashTable_probing() {
		table = vector<Key>(HASH_SIZE, Key{});
	}
	void clear() {

	}
	~hashTable_probing() {

	}
	bool insert(const Key& item) {
		int probe = hash(item);
		int probe_count = 0;
		int inc = 1;
		while (table[probe] != empty && \
			table[probe] != item && \
			probe_count < (HASH_SIZE + 1) / 2)
		{
			probe = (probe + inc) % HASH_SIZE;
			inc += 2;
			probe_count++;
		}
		if (table[probe] == empty)
		{
			table[probe] = item;
			return true;
		}
		return false;
	}
	bool retrive(const Key& key) {
		int probe = hash(key);
		int probe_count = 0;
		int inc = 1;
		while (table[probe] != key && \
			probe_count < (HASH_SIZE + 1) / 2)
		{
			probe = (probe + inc) % HASH_SIZE;
			inc += 2;
			probe_count++;
		}
		if (table[probe] == empty)
		{
			return false;
		}
		else if (table[probe] == key)
		{
			return true;
		}
		return false;
	}
private:
	vector<Key> table;
	Key empty{};
	int hash(const int& a)
	{
		return a % HASH_SIZE;
	}
	int hash(const string& a)
	{
		int val = 0;
		for (int i = 0; i < a.size(); i++)
		{
			val = val * 4 + a[i];
		}
		return val % HASH_SIZE;
	}
};



template <class Key>
class hashTable_chaining {
public:
	hashTable_chaining() {
		table = vector< Slist<Key> >(HASH_CHAINED_SIZE);
	}
	void clear() {
		for (auto it = table.begin(); it != table.end(); it++)
		{
			(*it).clear();
		}
	}
	~hashTable_chaining() {

	}
	bool insert(const Key& item) {
		int probe = hash(item);
		table[probe].push_back(item);
		return true;
	}
	bool retrive(const Key& key) {
		int probe = hash(key);
		Slist<Key> s = this->table[probe];
		while (!s.empty())
		{
			Key tmp;
			s.front(tmp);
			if (tmp == key)
				return true;
			s.pop_front();
		}
		return false;
	}
	bool remove(const Key& key)
	{
		int probe = hash(key);
		Slist<Key> s = this->table[probe];
		int i = 0;
		while (!s.empty())
		{
			Key tmp;
			s.front(tmp);
			if (tmp == key)
			{
				this->table[probe].remove(i);
				return true;
			}
			i++;
			s.pop_front();
		}
		return false;
	}
private:
	vector<Slist<Key> > table;
	Key empty{};
	int hash(const int& a)
	{
		return a % HASH_CHAINED_SIZE;
	}
	int hash(const string& a)
	{
		int val = 0;
		for (int i = 0; i < a.size(); i++)
		{
			val = val * 4 + a[i];
		}
		return val % 17;
	}
};