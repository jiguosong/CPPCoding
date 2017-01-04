#ifndef rangesum_H_
#define rangesum_H_

#include <vector>
using std::vector;

class rangesum {
public:
	int countRangeSum(vector<int> &nums, int lower, int upper);
};

#endif


// https://discuss.leetcode.com/topic/48052/segment-tree-binary-indexed-tree-and-the-simple-way-using-buffer-to-accelerate-in-c-all-quite-efficient/2

/*
class NumArray {
private:
    vector<long> sums;
    vector<int> nums;
    vector<pair<int,int>> buffer;
public:
    NumArray(vector<int> &nums) : sums(nums.size()+1, 0), nums(nums)
    {
        partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
    }
    void update(int i, int val)
    {
        buffer.emplace_back(i,  val - nums[i]); //buffer.push_back(make_pair(i, val-nums[i]));
        nums[i] = val;
        if(buffer.size() > 300)
        {
            partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
            buffer.clear();
        }
    }

    //AC - 80ms - just using a buffer, dramatically reduce the time cost;
    int sumRange(int i, int j)
    {
        long result =  sums[j+1] - sums[i];
        for(const auto& p : buffer)
            if(p.first <=j && p.first >= i) result += p.second;
        return result;
    }
};*/
