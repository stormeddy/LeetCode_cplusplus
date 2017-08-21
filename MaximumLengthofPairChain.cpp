//You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
//
//Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
//
//Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
//
//Example 1:
//Input: [[1,2], [2,3], [3,4]]
//Output: 2
//Explanation: The longest chain is [1,2] -> [3,4]
//Note:
//The number of given pairs will be in the range [1, 1000].

#include<vector>
#include<algorithm>

using namespace std;

class MaximumLengthofPairChain {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return a[1]<b[1];});
		int res = 1;
		vector<int>& p = pairs[0];
		for (int i = 1; i<pairs.size(); ++i){
			if (pairs[i][0]>p[1]){
				p[1] = pairs[i][1];
				++res;
			}
		}
		return res;
	}




//public:
//	int findLongestChain(vector<vector<int>>& pairs) {
//		sort(pairs.begin(), pairs.end(), cmp);
//		int cnt = 0;
//		vector<int>& pair = pairs[0];
//		for (int i = 0; i < pairs.size(); i++) {
//			if (i == 0 || pairs[i][0] > pair[1]) {
//				pair = pairs[i];
//				++cnt;
//			}
//		}
//		return cnt;
//	}
//
//private:
//	static bool cmp(vector<int>& a, vector<int>&b) {
//		return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
//	}


	//java dp version
	//Arrays.sort(pairs, (a, b) -> (a[0] - b[0]));

	//int i, j, max = 0, n = pairs.length;
	//int dp[] = new int[n];

	//for (i = 0; i < n; i++) dp[i] = 1;

	//for (i = 1; i < n; i++)
	//	for (j = 0; j < i; j++)
	//		if (pairs[i][0] > pairs[j][1] && dp[i] < dp[j] + 1)
	//			dp[i] = dp[j] + 1;

	//for (i = 0; i < n; i++) if (max < dp[i]) max = dp[i];

	//return max;
//	}


	//java dp version
	//Arrays.sort(pairs, (a, b) -> (a[0] - b[0]));

	//int i, j, max = 0, n = pairs.length;
	//int dp[] = new int[n];

	//for (i = 0; i < n; i++) dp[i] = 1;

	//for (i = 1; i < n; i++)
	//	for (j = 0; j < i; j++)
	//		if (pairs[i][0] > pairs[j][1] && dp[i] < dp[j] + 1)
	//			dp[i] = dp[j] + 1;

	//for (i = 0; i < n; i++) if (max < dp[i]) max = dp[i];

	//return max;
};