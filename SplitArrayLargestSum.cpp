//Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//If n is the length of array, assume the following constraints are satisfied:
//
//1 ¡Ü n ¡Ü 1000
//1 ¡Ü m ¡Ü min(50, n)
//Examples:
//
//Input:
//nums = [7,2,5,10,8]
//m = 2
//
//Output:
//18
//
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8],
//where the largest sum among the two subarrays is only 18.

#include<vector>
#include<algorithm>

using namespace std;

class SplitArrayLargestSum {
public:
	int splitArray(vector<int>& nums, int m) {
		vector<vector<int>> t(m + 1, vector<int>(nums.size(), -1));
		vector<int> acc(nums.size());
		for (int i = 0; i<nums.size(); ++i){
			acc[i] = (i>0 ? acc[i - 1] : 0) + nums[i];
		}
		return help(nums, m, 0, t, acc);
	}

	int help(vector<int>& a, int m, int start, vector<vector<int>>& t, vector<int>& acc){
		if (start>a.size()) return 0;
		if (t[m][start] != -1) return t[m][start];
		if (m == 1){
			int s = 0;
			for (int i = start; i<a.size(); ++i){
				s += a[i];
			}
			t[m][start] = s;
			return s;
		}
		int res = INT_MAX;
		for (int i = start; i<a.size() - 1; ++i){

			int pre_sum = acc[i] - (start == 0 ? 0 : acc[start - 1]);
			int tmp = max(pre_sum, help(a, m - 1, i + 1, t, acc));
			res = min(tmp, res);
		}
		t[m][start] = res;
		return res;
	}

	//brilliant code below!
	//int splitArray(vector<int>& nums, int m) {
	//	long long left = 0, right = 0;
	//	for (int num : nums) {
	//		left = max(left, (long long)num);
	//		right += num;
	//	}

	//	while (left < right) {
	//		long long mid = left + (right - left) / 2;
	//		if (doable(nums, m - 1, mid)) right = mid;
	//		else left = mid + 1;
	//	}
	//	return left;
	//}

	//bool doable(const vector<int>& nums, int cuts, long long max) {
	//	int acc = 0;
	//	for (int num : nums) {
	//		// This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
	//		if (num > max) return false;
	//		else if (acc + num <= max) acc += num;
	//		else {
	//			--cuts;
	//			acc = num;
	//			if (cuts < 0) return false;
	//		}
	//	}
	//	return true;
	//}
};