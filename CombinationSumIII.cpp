//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//[[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//[[1,2,6], [1,3,5], [2,3,4]]

#include<vector>

using namespace std;

class CombinatinoSumIII {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> a = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
		vector<vector<int>> res;
		vector<int> tmp;
		help(res, k, n, a, 0, a.size() - 1, tmp);
		return res;
	}

	void help(vector<vector<int>>& res, int k, int n, vector<int>& a, int start, int end, vector<int>& tmp){
		//if(start>end) return;
		if (n == 0 && k == 0)
		{
			res.push_back(tmp);
			return;
		}
		else if (n != 0 && k != 0)
		{
			for (int i = start; i <= end && a[i] <= n; ++i)
			{
				tmp.push_back(a[i]);
				help(res, k - 1, n - a[i], a, i + 1, end, tmp);
				tmp.pop_back();
			}

		}
	}
};