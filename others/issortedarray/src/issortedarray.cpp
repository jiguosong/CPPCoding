/*




 */

#include "issortedarray.h"
#include <algorithm>

void issortedarray::dummy()
{
}

std::string issortedarray::is_sorted_and_how(std::vector<int> &array)
{
	if (std::is_sorted(array.begin(), array.end()))
		return "yes, ascending";
	else if (std::is_sorted(array.begin(), array.end(),
			[](int l, int r) {return l > r;}))
		return "yes, descending";
	else
		return "no";
}
