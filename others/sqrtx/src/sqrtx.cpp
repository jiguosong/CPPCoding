

#include "sqrtx.h"

void sqrtx::dummy() 
{
}

unsigned int sqrtx::sqrt(unsigned int x)
{
	int left = 0;
	int right = x;

	while(left < right) {
		int mid = left + (right-left)/2;
		long long sqrt = mid*mid;
		if(sqrt == x) return mid;
		else if (sqrt < x) left = mid + 1;
		else right = mid-1;
	}

	return right;
}
