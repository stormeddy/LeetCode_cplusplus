//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?

#include<vector>
#include<unordered_map>

using namespace std;

class CombinationSumIV {
public:
	int combinationSum4(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		return help(nums, target, m);
	}

	int help(vector<int>& nums, int t, unordered_map<int, int>& m){
		if (t <= 0) return 0;
		if (m.find(t) != m.end()) return m[t];
		int res = 0;
		for (int i = 0; i<nums.size(); ++i){
			int cur = nums[i];
			if (cur == t){
				++res;
			}
			else if (cur<t){
				res += help(nums, t - cur, m);
			}
		}
		m[t] = res;
		return res;
	}
};