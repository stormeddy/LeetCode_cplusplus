//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]

#include<vector>
#include<algorithm>

using namespace std;

class _4Sum {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; ++i){
			int tar3 = target - nums[i];
			for (int j = i + 1; j < n - 2; ++j){
				int tar2 = tar3 - nums[j];
				int start = j + 1, end = n - 1;
				while (start < end){
					//cout<<start<<end<<endl;
					int cur = nums[start] + nums[end];
					if (cur<tar2){
						++start;
					}
					else if (cur>tar2){
						--end;
					}
					else{
						vector<int> tmp(4);
						tmp[0] = nums[i];
						tmp[1] = nums[j];
						tmp[2] = nums[start];
						tmp[3] = nums[end];
						res.push_back(tmp);
						while (start < end && nums[start] == tmp[2]) ++start;
						while (start < end && nums[end] == tmp[3]) --end;

					}
				}
				while (j < n - 2 && nums[j] == nums[j + 1]) ++j;
			}
			while (i < n - 3 && nums[i] == nums[i + 1]) ++i;
		}
		return res;
	}
};