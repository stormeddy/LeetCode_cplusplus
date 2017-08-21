//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note: 
//(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100
//
//Example:
//
//Given [3, 1, 5, 8]
//
//Return 167
//
//    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

#include<vector>
#include<algorithm>

using namespace std;

class BurstBoloons {


public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
		for (int len = 1; len <= n; ++len){
			for (int i = 1; i <= n - len + 1; ++i){
				int j = i + len - 1;
				int res = 0;
				for (int cur = i; cur <= j; ++cur){
					int tmp = dp[i][cur - 1] + dp[cur + 1][j];
					tmp += nums[i - 1] * nums[cur] * nums[j + 1];
					if (tmp>res) res = tmp;
				}
				dp[i][j] = res;
			}

		}
		return dp[1][n];
	}

};