//Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//Input:
//
//"bbbab"
//Output:
//4
//One possible longest palindromic subsequence is "bbbb".
//Example 2:
//Input:
//
//"cbbd"
//Output:
//2
//One possible longest palindromic subsequence is "bb".

#include<vector>
#include<algorithm>

using namespace std;

class LongestPalindromicSubsequence {
public:
	int longestPalindromeSubseq(string s) {
		int n = s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int i = 1; i <= n - 1; ++i){
			dp[i][i] = 1;
			if (s[i - 1] == s[i]) dp[i][i + 1] = 2;
			else dp[i][i + 1] = 1;
		}
		dp[n][n] = 1;
		for (int i = n - 2; i >= 1; --i){
			for (int j = i + 1; j <= n; ++j){
				if (s[i - 1] == s[j - 1]){
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else if (dp[i + 1][j]>dp[i][j - 1]){
					dp[i][j] = dp[i + 1][j];
				}
				else{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[1][n];
	}
};