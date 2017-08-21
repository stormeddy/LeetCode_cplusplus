//Given a non-negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.
//
//Example:
//Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ¡Ü x < 100, excluding [11,22,33,44,55,66,77,88,99])

#include<vector>
#include<algorithm>

using namespace std;

class CountNumberswithUniqueDigits {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 1;
		if (n == 1) return 10;
		if (n>10) n = 10;
		int res = 10;
		int pre = 9;
		for (int i = 2; i <= n; ++i){
			res += pre*(11 - i);
			pre *= (11 - i);
		}
		return res;
	}
};