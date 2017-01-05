/*
 * twosum.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class sum {
public:
	virtual void run() = 0;
	virtual ~sum(){};
};

class twosum : public sum {
public:
	void run() override
	{
		cout << "2sum" << endl;
		vector<int> input {0, 1 , 2, 3, 4, 5, 6};
		vector<int> res(2);
		res = twoSum(input, 9);
		cout << res[0] << endl;
		cout << res[1] << endl;
	}

	static twosum &instance()
	{
		static twosum *p = new twosum;
		return *p;
	};

	virtual ~twosum(){};

private:
	twosum(){};
	twosum(const twosum &other);
	const twosum &operator=(const twosum &other);

	vector<int> twoSum(vector<int> &nums, int target);
};

vector<int> twosum::twoSum(vector<int> &nums, int target)
{
	std::unordered_map<int, int> map;
	for (int i = 0; (size_t)i < nums.size(); ++i) {
		int t = target - nums[i];
		if (map.count(t) && map[t] != i){
			return {i, map[t]};
			break;
		}
		map[nums[i]] = i;
	}
	return {};
}

class solution_factory {
public:
	static sum *sum_solution(const string &name)
	{
		if(name == "2sum") {
			sum &p = twosum::instance();
			return &p;
		}

		return NULL;
	}
};

int main()
{
	solution_factory sumproblem;
	sumproblem.sum_solution("2sum")->run();
}
