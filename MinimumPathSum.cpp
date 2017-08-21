//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

#include<vector>
#include<algorithm>

using namespace std;

class MinimumPathSum {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		vector<int> res(n, grid[0][0]);
		for (int i = 1; i<n; ++i){
			res[i] = res[i - 1] + grid[0][i];
		}

		for (int j = 1; j<m; ++j)
			for (int i = 0; i<n; ++i){
				if (i == 0){
					res[0] += grid[j][0];
				}
				else{
					res[i] = min(res[i - 1] + grid[j][i], res[i] + grid[j][i]);
				}

			}
		//for(int i:res) cout<<i<<endl;
		return res[n - 1];
	}
};