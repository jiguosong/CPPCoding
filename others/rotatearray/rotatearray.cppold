/*
 * rotatearray.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
/*container lib*/
#include <vector>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

class rotatearray {
public:
	void rotate(vector<int> &nums, int k);
	void reverse(vector<int> &nums, int l, int r);
};


void reverse(vector<int> &nums, int l, int r){
	int tmp;
	while (l < r) {
		tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
		l++;
		r--;
	}
}

void rotate(vector<int> &nums, int k) {
		if (nums.empty()|| k <= 0) return;

		int n = nums.size();
		if (k > n) k = k%n;

		reverse(nums, 0, n-k-1);
		reverse(nums, n-k, n-1);
		reverse(nums, 0, n-1);
}


int main(){
	cout << "rotate array" << endl;

	vector<int> aaa {1,2,3,4,5,6,7};
	int k = 3;
	rotate(aaa, k);

	for (int i = 0; (unsigned)i < aaa.size(); i++)
		cout << aaa[i] ;
	cout << endl;
}


