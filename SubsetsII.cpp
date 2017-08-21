//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,2], a solution is:
//
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//]

#include<vector>
#include<algorithm>

using namespace std;

class SubsetsII {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> tmp;
		help(res, tmp, 0, nums);
		return res;

	}

	void help(vector<vector<int>>& res, vector<int>& tmp, int start, vector<int>& nums){
		res.push_back(tmp);
		for (int i = start; i < nums.size(); ++i){
			tmp.push_back(nums[i]);
			help(res, tmp, i + 1, nums);
			tmp.pop_back();
			while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;

			/*if (i == start || nums[i] != nums[i - 1]){
				tmp.push_back(nums[i]);
				help(res, tmp, i + 1, nums);
				tmp.pop_back();
			}*/

		}
	}
};