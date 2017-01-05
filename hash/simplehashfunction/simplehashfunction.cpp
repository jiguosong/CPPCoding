#include "simplehashfunction.h"

void simplehashfunction::dummy()
{
}

unsigned int simplehashfunction::SimpleHash_Fn(const std::string &str,
		unsigned int table_sz)
{
	unsigned int hash_val = 0;
	for(auto a : str) {
		hash_val = 37*hash_val + a;
	}

	hash_val = hash_val%table_sz;
	if(hash_val < 0) hash_val += table_sz;

	return hash_val;
}
