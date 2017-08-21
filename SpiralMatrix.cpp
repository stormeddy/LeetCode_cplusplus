//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].

#include<vector>
#include<algorithm>

using namespace std;

class MaximumSubarray {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (m == 0) return res;
		int n = matrix[0].size();
		int num = 1, rowbegin = 0, rowend = m - 1, colbegin = 0, colend = n - 1;
		while (rowbegin <= rowend && colbegin <= colend) {
			for (int i = colbegin; i <= colend; ++i) res.push_back(matrix[rowbegin][i]);
			++rowbegin;

			for (int i = rowbegin; i <= rowend; ++i) res.push_back(matrix[i][colend]);
			--colend;

			if (rowbegin <= rowend){
				for (int i = colend; i >= colbegin; --i) res.push_back(matrix[rowend][i]);
			}

			--rowend;

			if (colbegin <= colend){
				for (int i = rowend; i >= rowbegin; --i) res.push_back(matrix[i][colbegin]);
			}

			++colbegin;
		}
		return res;
	}
};