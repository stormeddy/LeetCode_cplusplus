//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers (including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
//A solution set is: 
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]

#include<vector>
#include<algorithm>

using namespace std;

class CombinationSumII {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
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
			help(res, nums, target - nums[i], cur, i + 1);
			cur.pop_back();
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;

			/*if (i == start || nums[i] != nums[i - 1]){
				cur.push_back(nums[i]);
				help(res, nums, target - nums[i], cur, i + 1);
				cur.pop_back();
			}*/

		}
	}
};