//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

#include<vector>
#include<algorithm>

using namespace std;

class PascalTriangle {
public:
	vector<vector<int>> generate(int numRows) {
		int n = numRows;
		vector<vector<int>> res;
		for (int i = 1; i <= n; ++i){
			vector<int> tmp(i, 1);
			for (int j = 1; j<i - 1; ++j){
				tmp[j] = res[i - 2][j - 1] + res[i - 2][j];
			}
			res.push_back(tmp);
		}
		return res;
	}
};