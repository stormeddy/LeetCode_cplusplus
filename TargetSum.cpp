//You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//Find out how many ways to assign symbols to make sum of integers equal to target S.
//
//Example 1:
//Input: nums is [1, 1, 1, 1, 1], S is 3. 
//Output: 5
//Explanation: 
//
//-1+1+1+1+1 = 3
//+1-1+1+1+1 = 3
//+1+1-1+1+1 = 3
//+1+1+1-1+1 = 3
//+1+1+1+1-1 = 3
//
//There are 5 ways to assign symbols to make the sum of nums be target 3.
//Note:
//The length of the given array is positive and will not exceed 20.
//The sum of elements in the given array will not exceed 1000.
//Your output answer is guaranteed to be fitted in a 32-bit integer.

#include<vector>
#include<algorithm>

using namespace std;

class TargetSum {
public:

	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		vector<int> dp(2001);
		dp[nums[0] + 1000] = 1;
		dp[-nums[0] + 1000] += 1;
		for (int i = 1; i<n; ++i){
			vector<int> next(2001, 0);
			for (int sum = -1000; sum <= 1000; ++sum){
				if (dp[sum + 1000]>0){
					next[sum + nums[i] + 1000] += dp[sum + 1000];
					next[sum - nums[i] + 1000] += dp[sum + 1000];
				}

			}
			dp = next;
		}
		return S>1000 ? 0 : dp[S + 1000];
	}

	/*int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(2001, 0));
		dp[0][nums[0] + 1000] = 1;
		dp[0][-nums[0] + 1000] += 1;
		for (int i = 1; i<n; ++i){
		for (int sum = -1000; sum <= 1000; ++sum){
		if (dp[i - 1][sum + 1000]>0){
		dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
		dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
		}

		}
		}
		return S>1000 ? 0 : dp[n - 1][S + 1000];
	}*/

	/*int findTargetSumWays(vector<int>& nums, int S) {
		return help(nums, S, nums.size() - 1);
	}

	int help(vector<int>& nums, int t, int end){
		if (end == 0){
			int res = 0;
			if (nums[end] == t) ++res;
			if (nums[end] == -t) ++res;
			return res;
		}
		return help(nums, t - nums[end], end - 1) + help(nums, t + nums[end], end - 1);
	}*/


	
};