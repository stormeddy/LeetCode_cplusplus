//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//Note: Given n will be a positive integer.

#include<vector>
#include<algorithm>

using namespace std;

class ClimbingStairs {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int f1 = 1, f2 = 2;
		int res = 0;
		for (int i = 3; i <= n; ++i){
			res = f1 + f2;
			f1 = f2;
			f2 = res;
		}
		return res;
	}
};