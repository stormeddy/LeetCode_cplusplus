//Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [2, 3, 6, 7] and target 7, 
//A solution set is: 
//[
//  [7],
//  [2, 2, 3]
//]

#include<vector>

using namespace std;

class CombinationSum {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> cur;
		vector<vector<int>> res;
		help(res, candidates, target, cur, 0);
		return res;
	}

	void help(vector<vector<int>>& res, vector<int>& nums, int target, vector<int>& cur, int start){
		if (target<0) return;
		if (target == 0){
			res.push_back(cur);
			return;
		}
		for (int i = start; i<nums.size(); ++i){
			cur.push_back(nums[i]);
			help(res, nums, target - nums[i], cur, i);
			cur.pop_back();
		}
	}
};