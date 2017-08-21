//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 6.

#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class MaximalRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		vector<int> h(n);
		int res = 0;
		for (int i = 0; i<m; ++i){
			for (int j = 0; j<n; ++j){
				if (matrix[i][j] == '0'){
					h[j] = 0;
				}
				else{
					++h[j];
				}
			}
			res = max(res, largestRectangleArea(h));
		}
		return res;
	}

	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int n = heights.size();
		stack<int> s;
		int res = 0;
		for (int i = 0; i<n; ++i){
			while (!s.empty() && heights[i] <= heights[s.top()]){
				int h = heights[s.top()];
				s.pop();
				int start = s.empty() ? -1 : s.top();
				int area = (i - start - 1)*h;
				if (area>res) res = area;
			}
			s.push(i);
		}
		return res;
	}


};