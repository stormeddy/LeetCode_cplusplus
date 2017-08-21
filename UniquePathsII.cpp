//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//The total number of unique paths is 2.

#include<vector>

using namespace std;

class UniquePathsII {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0) return 0;
		int n = obstacleGrid[0].size();
		vector<int> cur(m, 1);

		int st = 0;
		for (; st<m; ++st) if (obstacleGrid[st][0]) break;
		if (st<m){
			for (int i = st; i<m; ++i) cur[i] = 0;
		}
		for (int j = 1; j < n; j++)
			for (int i = 0; i < m; i++)
				if (obstacleGrid[i][j]){
					cur[i] = 0;
				}
				else{
					if (i>0)
						//cout<<i<<" "<<cur[i-1]<<endl;
						cur[i] += cur[i - 1];
				}

				return cur[m - 1];
	}
};