//
//We are playing the Guess Game. The game is as follows:
//
//I pick a number from 1 to n. You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
//However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
//
//Example:
//
//n = 10, I pick 8.
//
//First round:  You guess 5, I tell you that it's higher. You pay $5.
//Second round: You guess 7, I tell you that it's higher. You pay $7.
//Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
//Game over. 8 is the number I picked.
//
//You end up paying $5 + $7 + $9 = $21.
//Given a particular n ¡Ý 1, find out how much money you need to have to guarantee a win.

#include<vector>
#include<algorithm>

using namespace std;

class GuessNumbeerHigherorLowerII {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		return help(dp, 1, n);
	}

	int help(vector<vector<int>>& dp, int i, int j){
		if (i >= j) return 0;
		if (dp[i][j] != 0) return dp[i][j];
		int res = INT_MAX;
		for (int k = i; k <= j; ++k){
			int tmp = k + max(help(dp, i, k - 1), help(dp, k + 1, j));
			res = min(res, tmp);
		}
		dp[i][j] = res;
		return res;
	}
};