/*
 * 3sum.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

// singleton practice
class solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for(int i = 0; (size_t)i < nums.size(); i++) {
			if(nums[i] > 0) break;
			if(i > 0 && nums[i] == nums[i-1]) continue;
			int target = 0 - nums[i];
			int left = i+1;
			int right = nums.size()-1;
			while(left < right) {
				if(nums[left] + nums[right] == target) {
					res.push_back({nums[i], nums[left], nums[right]});
					while(left < right && nums[left] == nums[left+1]) left++;
					while(left < right && nums[right] == nums[right-1]) right--;
					left++;
					right--;
				} else if(nums[left] + nums[right] < target) {
					left++;
				} else {
					right--;
				}
			}
		}

		return res;
	}

	static solution& instance(){static solution *instance = new solution; return *instance;}

private:
	solution(){};
	~solution(){};
	solution(const solution& other);
	const solution &operator=(const solution& other);
};

int main()
{
	// some initilization practice
	/*char a[10] = "abcdefg";
	// DC RV LA
	string s1("hello world");
	string s2 = "hello world";
	char &s3 = a[0];
	string s4{};
	string s5{'a', 'b', 'c'};
	char b[3] = {'a','b'};

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s5 << std::endl;
	std::cout << b << std::endl;*/

	// solution *p = &(solution::instance());  a pointer to the reference
	solution &test = solution::instance();

	solution &test2 = solution::instance();
	cout << &test << endl;
	cout << &test2 << endl;

	vector<int> nums = {1,2,-3,4,5};
	vector<vector<int>> ans = test.threeSum(nums);

	for(auto e : ans) {
		for (auto k : e) {
			cout << k << ' ';
		}
	}
}

