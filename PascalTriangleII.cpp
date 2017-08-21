//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

#include<vector>

using namespace std;

class PascalTriangleII {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		for (int i = 0; i <= rowIndex; ++i){
			int pre = 1;
			for (int j = 1; j<res.size(); ++j){
				int t = res[j];
				res[j] = res[j] + pre;
				pre = t;
			}
			res.push_back(1);
		}
		return res;
	}
};