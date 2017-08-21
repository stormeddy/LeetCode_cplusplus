//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//Each of the array element will not exceed 100.
//The array size will not exceed 200.
//Example 1:
//
//Input: [1, 5, 11, 5]
//
//Output: true
//
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//
//Input: [1, 2, 3, 5]
//
//Output: false
//
//Explanation: The array cannot be partitioned into equal sum subsets.

#include<vector>
#include<algorithm>

using namespace std;

class PartitionEqualSubsetSum {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int s = 0;
		for (int i : nums) s += i;
		if (s % 2 != 0) return false;
		int t = s / 2;
		vector<vector<int>> m(n + 1, vector<int>(t + 1, -1));
		return help(nums, 0, t, m) == 1;
	}

	int help(vector<int>& nums, int start, int t, vector<vector<int>>& m){
		if (t<0 || start>nums.size()) return 0;
		if (t == 0){
			m[start][t] = 1;
			return 1;
		}
		if (m[start][t] != -1) return m[start][t];
		for (int i = start; i<nums.size(); ++i){
			if (help(nums, i + 1, t - nums[i], m) == 1){
				m[start][t] = 1;
				return 1;
			}
		}
		m[start][t] = 0;
		return 0;
	}
};