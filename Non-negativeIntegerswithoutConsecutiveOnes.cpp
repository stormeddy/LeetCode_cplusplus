//Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.
//
//Example 1:
//Input: 5
//Output: 5
//Explanation: 
//Here are the non-negative integers <= 5 with their corresponding binary representations:
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
//Note: 1 <= n <= 10^9

#include<vector>
#include<algorithm>

using namespace std;

class Non_negativeIntegerswithoutConsecutiveOnes{
public:
	int findIntegers(int num) {
		vector<int> f(32);
		f[0] = 1;
		f[1] = 2;
		for (int i = 2; i<32; ++i){
			f[i] = f[i - 1] + f[i - 2];
		}

		int k = 30, pre = 0;
		int res = 0;
		while (k >= 0){
			if (num&(1 << k)){
				res += f[k];
				if (pre){
					--res;
					break;
				}
				pre = 1;
			}
			else{
				pre = 0;
			}
			--k;
		}
		return res + 1;
	}
};