/*
Load factor λ of a hash table T is defined as follows:

N = number of elements in T  (“current size”)
M = size of T (“table size”)
λ = N/M ("load factor")
  i.e., λ is the average length of a chain

Unsuccessful search time: O(λ) , Same for insert time
Successful search time: O(λ/2)
Ideally, want λ ≤ 1 (not a function of N)

Note:
  Table size prime
  Table size much larger than number of inputs (to maintain λ closer to 0 or < 0.5)
  Tradeoffs between chaining vs. probing
  Collision chances decrease in this order: linear probing => quadratic probing => {random probing, double hashing}
  Rehashing required to resize hash table at a time when λ exceeds 0.5
  Good for searching. Not good if there is some order implied data
*/

#ifndef hashtable_H_
#define hashtable_H_

#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template<class HashedObj>
class HashTable
{
public:
	//explicit HashTable(int size = 101);
	HashTable() : currentSize(0) {};
	virtual ~HashTable(){};
	bool contains(const HashedObj &x) const;

	void makeEmpty();
	bool insert(const HashedObj &x);
	bool remove(const HashedObj &x);

private:
	std::vector<std::list<HashedObj> > theLists;
	int currentSize;

	void rehash();
	int myhash(const HashedObj &x) const;
};

int hash(const std::string &key);
int hash(int key);

template<class HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj &x) const
{
	using ::hash;           // with using, we still have argument-dependent lookup (ADL)... see above 2 hash functions
	int hashVal = hash(x);

	hashVal %= theLists.size();
	if (hashVal < 0)
		hashVal += theLists.size();

	return hashVal;
}

template<class HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
	//std::cout << "insert" << std::endl;
	//std::cout << "theLists size" << theLists.size() << std::endl;
	std::list<HashedObj> &whichlist = theLists[myhash(x)];
	if (std::find(whichlist.begin(), whichlist.end(), x) != whichlist.end())
		return false;
	whichlist.push_back(x);

	//if (++currentSize > theLists.size())
	//	rehash();

	return true;
}

template<class HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
	std::list<HashedObj> &whichlist = theLists[myhash(x)];
	typename std::list<HashedObj>::iterator it = std::find(whichlist.begin(),
			whichlist.end(), x);

	if (it == whichlist.end())
		return false;

	whichlist.erase(it);
	--currentSize;
	return true;
}

template<class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	for (int i = 0; i < theLists.size(); ++i)
		theLists[i].clear();
}

template<class HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
	const std::list<HashedObj> &whichlist = theLists[myhash(x)];
	return find(whichlist.begin(), whichlist.end(), x) != whichlist.end();
}

#endif
