//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//
//
//Above is a 3 x 7 grid. How many possible unique paths are there?
//
//Note: m and n will be at most 100.
//

#include<vector>

using namespace std;

class UniquePaths {
public:
	int uniquePaths(int m, int n) {
		/*int a[m][n];
		for (int i = 0; i<m; ++i)
			a[i][0] = 1;
		for (int i = 0; i<n; ++i)
			a[0][i] = 1;
		for (int i = 1; i<m; ++i)
			for (int j = 1; j<n; ++j)
			{
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		return a[m - 1][n - 1];*/
		vector<int> cur(m, 1);
		for (int j = 1; j < n; j++)
			for (int i = 1; i < m; i++)
				cur[i] += cur[i - 1];
		return cur[m - 1];
	}
};