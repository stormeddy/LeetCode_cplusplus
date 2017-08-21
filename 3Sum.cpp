
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]

#include<vector>
#include<algorithm>

using namespace std;

class _3Sum {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty()) return res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i<n - 2; ++i){
			int t = -nums[i];
			int lo = i + 1, hi = n - 1;
			while (lo<hi){
				int cur = nums[lo] + nums[hi];
				if (cur>t){
					--hi;
				}
				else if (cur<t){
					++lo;
				}
				else{
					vector<int> tmp(3);
					tmp[0] = nums[i];
					tmp[1] = nums[lo];
					tmp[2] = nums[hi];
					res.push_back(tmp);
					while (lo<hi && nums[lo] == tmp[1]) ++lo;
					while (lo<hi && nums[hi] == tmp[2]) --hi;
				}
			}
			while (i<n - 2 && nums[i] == nums[i + 1]) ++i;
		}
		return res;
	}

};