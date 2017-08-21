//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,3], a solution is:
//
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]

#include<vector>
#include<algorithm>

using namespace std;

class Subsets {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> tmp;
		help(res, tmp, 0, nums);
		return res;

	}

	void help(vector<vector<int>>& res, vector<int>& tmp, int start, vector<int>& nums){
		res.push_back(tmp);
		for (int i = start; i<nums.size(); ++i){
			tmp.push_back(nums[i]);
			help(res, tmp, i + 1, nums);
			tmp.pop_back();
		}
	}
};