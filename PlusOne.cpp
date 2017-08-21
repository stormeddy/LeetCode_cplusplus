//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include<vector>

using namespace std;

class RotateImage {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res;
		int cin = 0;
		int tmp = 0;
		int cur = 0;
		for (int i = digits.size() - 1; i >= 0; --i){
			tmp = cin + digits[i];
			if (i == digits.size() - 1){
				++tmp;
			}
			cur = tmp % 10;
			cin = tmp / 10;
			res.push_back(cur);
		}
		if (cin) res.push_back(cin);
		reverse(res.begin(), res.end());
		return res;
	}
};