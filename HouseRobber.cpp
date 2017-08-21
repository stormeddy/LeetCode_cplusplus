//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include<vector>
#include<algorithm>

using namespace std;

class HouseRobber {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		if (n == 1) return nums[0];
		if (n == 2) return max(nums[0], nums[1]);
		vector<int> dp(n, 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i<n; ++i){
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return dp[n - 1];
	}
};