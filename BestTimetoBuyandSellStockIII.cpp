//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

#include<vector>
#include<algorithm>

using namespace std;

class Subsets {
public:
	int maxProfit(vector<int>& prices) {
		int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
		for (int i = 0; i<prices.size(); ++i){
			b1 = max(b1, -prices[i]);
			s1 = max(s1, b1 + prices[i]);
			b2 = max(b2, s1 - prices[i]);
			s2 = max(s2, b2 + prices[i]);
		}
		//return max(s1,s2);
		return s2;
	}
};