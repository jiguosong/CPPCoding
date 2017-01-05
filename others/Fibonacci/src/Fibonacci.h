#ifndef Fibonacci_H_
#define Fibonacci_H_

#include <vector>
#include <string>
using std::vector;
using std::string;

struct BI
{
	char Digits[110];
	int LastDigit;
};

class Fibonacci
{
public:
	void dummy();
	unsigned long long getNthFibs(int n);
	int howManyFibs(BI &small, BI &big);

	unsigned long getNthFibs_Binet(int n);
private:

};

#endif
