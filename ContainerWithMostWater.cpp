//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include<vector>
#include<algorithm>

using namespace std;

class RemoveDuplicatesfromSortedArray {
public:
	int maxArea(vector<int>& h) {
		int l = 0, r = h.size() - 1;
		int res = 0;
		while (l<r){
			if (h[l]<h[r]){

				res = max(res, (r - l)*h[l]);
				++l;
			}
			else{
				res = max(res, (r - l)*h[r]);
				--r;
			}

		}
		return res;
	}
};