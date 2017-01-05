/*




 */

#include "Fibonacci.h"
#include <cmath>

void Fibonacci::dummy()
{
}

// F(1) = 1; F(2) = 1; F(n) = F(n-1) + F(n-2);

unsigned long long Fibonacci::getNthFibs(int n)
{
//	vector<unsigned long> fibs(n+1, 0);
//	fibs[1] = 1;
//	fibs[2] = 1;

	int a = 1;
	int b = 1;
	int c = 0;

	for (int i = 3; i <= n; ++i) {
//		fibs[i] = fibs[i-1] + fibs[i-2];
		c = a + b;
		b = a;
		a = c;
	}

	return c;

//	return fibs[n];
}

// http://stackoverflow.com/questions/7843048/finding-the-closest-fibonacci-numbers#7843192
// F(n) = ( phi^n - (1-phi)^n ) / \sqrt{5}
// phi = (1 + \sqrt{5}) / 2
unsigned long Fibonacci::getNthFibs_Binet(int n)
{
	double phi = (1+std::sqrt(5))/2;
	//unsigned long ans = (unsigned long)round((phi**n - (1-phi)**n) / 5**0.5);

}

#include <iostream>
#include <algorithm>
#include <map>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;

void addBI(BI & a, BI & b, BI& c)
{
	for (int i = 0; i < 110; i++)
		c.Digits[i] = 0;
	int carry = 0;
	c.LastDigit = max(a.LastDigit, b.LastDigit);
	for (int i = 0; i <= c.LastDigit; i++) {
		c.Digits[i] = (a.Digits[i] + b.Digits[i] + carry) % 10;
		carry = (a.Digits[i] + b.Digits[i] + carry) / 10;
	}
	if (carry)
		c.Digits[++c.LastDigit] = carry;
	return;
}
int compBI(BI &a, BI&b)
{
	if (a.LastDigit != b.LastDigit)
		return a.LastDigit > b.LastDigit;

	for (int i = a.LastDigit; i >= 0; i--)
		if (a.Digits[i] != b.Digits[i])
			return a.Digits[i] > b.Digits[i];

	return -1;
}

int Fibonacci::howManyFibs(BI &small, BI &big)
{
	BI *a, *b, *c;
	a = new BI;
	b = new BI;
	c = new BI;

	for (int i = 0; i < 110; i++)
		a->Digits[i] = b->Digits[i] = 0;
	a->Digits[0] = 1;
	b->Digits[0] = 1;
	a->LastDigit = 0;
	b->LastDigit = 0;

	int nFibs = 0;
	bool reached = false;
	while (1) {
		if (compBI(*b, small) && compBI(*b, big) < 1)
			nFibs++;
		else if (compBI(*b, big) == 1)
			break;
		addBI(*a, *b, *c);
		//swap(b, c);
		//swap(a, c);
	}
	return nFibs;
}

/*

 int main()
 {
 string a, b;
 BI large, small;
 while (1) {
 cin >> a >> b;

 if (a == "0" && b == "0")
 return 0;
 small.LastDigit = a.size() - 1;
 for (int i = small.LastDigit, j = 0; i >= 0; i--, j++)
 small.Digits[i] = a[j] - '0';
 large.LastDigit = b.size() - 1;
 for (int i = large.LastDigit, j = 0; i >= 0; i--, j++)
 large.Digits[i] = b[j] - '0';
 cout << howManyFibs(small, large) << endl;

 }
 return 0;
 }
 */

