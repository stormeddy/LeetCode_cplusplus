//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?

#include<vector>

using namespace std;

class SetMatrixZeroes {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return;
		int n = matrix[0].size();
		vector<int> p;
		vector<int> q;
		for (int i = 0; i<m; ++i)
			for (int j = 0; j<n; ++j){
				if (!matrix[i][j]){
					p.push_back(i);
					q.push_back(j);
				}
			}
		for (int k = 0; k<p.size(); ++k){
			int i = p[k], j = q[k];
			for (int x = 0; x<m; ++x){
				matrix[x][j] = 0;
			}
			for (int y = 0; y<n; ++y){
				matrix[i][y] = 0;
			}
		}



		//O(1) space
		//int H = matrix.size();
		//int W = matrix[0].size();

		//// find the last 0 row
		//int last_0_row = -1;
		//for (int y = H - 1; y >= 0 && last_0_row == -1; y--)
		//	for (int x = 0; x < W; x++)
		//		if (matrix[y][x] == 0)
		//		{
		//			last_0_row = y;
		//			break;
		//		}
		//if (last_0_row == -1)
		//	return;

		//// go row by row
		//for (int y = 0; y < last_0_row; y++)
		//{
		//	bool this_is_a_0_row = false;

		//	for (int x = 0; x < W; x++)
		//	{
		//		if (matrix[y][x] == 0)
		//		{
		//			this_is_a_0_row = true;
		//			matrix[last_0_row][x] = 0;
		//		}
		//	}

		//	if (this_is_a_0_row)
		//		for (int x = 0; x < W; x++)
		//		{
		//			matrix[y][x] = 0;
		//		}
		//}

		//// set collums to 0
		//for (int y = 0; y < H; y++)
		//	for (int x = 0; x < W; x++)
		//	{
		//		if (matrix[last_0_row][x] == 0)
		//			matrix[y][x] = 0;
		//	}

		//// set the last 0 row 
		//for (int x = 0; x < W; x++)
		//{
		//	matrix[last_0_row][x] = 0;
		//}
	}
};