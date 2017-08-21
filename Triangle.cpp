//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include<vector>
#include<algorithm>

using namespace std;

class Triangle {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 0) return 0;
		vector<int> dp(n);
		dp[0] = triangle[0][0];
		for (size_t i = 1; i<n; ++i)
		{

			dp[i] = dp[i - 1] + triangle[i][i];
			for (size_t j = i - 1; j >= 1; --j)
			{
				dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
			}
			dp[0] += triangle[i][0];
		}


		int res = INT_MAX;
		for (size_t i = 0; i<n; ++i)
		{
			//cout << dp[i] << endl;
			res = min(res, dp[i]);
		}
		return res;
	}
};