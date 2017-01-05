/*




 */

#include "longestbinarygap.h"
#include <algorithm>

void longestbinarygap::dummy()
{
}

#include <iostream>
using namespace std;

int longestbinarygap::longestBinGap(int x)
{
	int start, end, max;
	start = end = 0;
	max = 0;


	int p = x;
	while (p && ((p & 1) == 0)) p = p >> 1;

	int prev = 1;
	while (p) {
		int curr = p & 1;
		if (curr == 1 && prev == 0) {
			max = std::max(start - end + 1, max);
		} else if (curr == 0 && prev == 1) {
			start = 0;
			end = 0;
		} else if (curr == 0 && prev == 0) {
			++start;
		}
		prev = curr;
		p = p >> 1;
	}

	return max;
}
