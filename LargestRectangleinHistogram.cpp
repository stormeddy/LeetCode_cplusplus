//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given heights = [2,1,5,6,2,3],
//return 10.
//

#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class LargestRectangleinHistogram {
public:
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


		/*stack<int> s;
		heights.push_back(0);
		int maxSize = 0;
		for (int i = 0; i < heights.size(); i++){
			if (s.empty() || heights[i] >= heights[s.top()]){
				s.push(i);
			}
			else{
				int temp = heights[s.top()];
				s.pop();
				maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
				i--;
			}
		}
		return maxSize;*/
	}



		/*stack<int> s;
		heights.push_back(0);
		int maxSize = 0;
		for (int i = 0; i < heights.size(); i++){
			if (s.empty() || heights[i] >= heights[s.top()]){
				s.push(i);
			}
			else{
				int temp = heights[s.top()];
				s.pop();
				maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
				i--;
			}
		}
		return maxSize;*/

};