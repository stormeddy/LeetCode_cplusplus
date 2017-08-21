//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

#include<vector>
#include<algorithm>

using namespace std;

class MaximumSubarray {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int p = 0, q = 0;
		bool f = true;//can go right first
		for (int i = 1; i <= n*n;)
		{
			res[p][q] = i;
			if (f&&q + 1<n&&!res[p][q + 1]){
				++q;
				++i;
			}
			else if (p + 1<n&&!res[p + 1][q]){
				++p;
				++i;
			}
			else if (q - 1 >= 0 && !res[p][q - 1]){
				--q;
				++i;
			}
			else if (p - 1 >= 0 && !res[p - 1][q]){
				f = false;
				--p;
				++i;
			}
			else{
				f = true;
				if (i == n*n) break;
			}
		}
		return res;


		/*vector<vector<int>> matrix(n, vector<int>(n, 0));
		int num = 1, rowbegin = 0, rowend = n - 1, colbegin = 0, colend = n - 1;
		while (rowbegin <= rowend && colbegin <= colend) {
			for (int i = colbegin; i <= colend; ++i) matrix[rowbegin][i] = num++;
			++rowbegin;

			for (int i = rowbegin; i <= rowend; ++i) matrix[i][colend] = num++;
			--colend;

			for (int i = colend; i >= colbegin; --i) matrix[rowend][i] = num++;
			--rowend;

			for (int i = rowend; i >= rowbegin; --i) matrix[i][colbegin] = num++;
			++colbegin;
		}
		return matrix;*/
	}
};