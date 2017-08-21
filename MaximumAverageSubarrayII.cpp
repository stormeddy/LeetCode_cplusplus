//Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.
//
//Example 1:
//Input: [1,12,-5,-6,50,3], k = 4
//Output: 12.75
//Explanation:
//when length is 5, maximum average value is 10.8,
//when length is 6, maximum average value is 9.16667.
//Thus return 12.75.
//Note:
//1 <= k <= n <= 10,000.
//Elements of the given array will be in range [-10,000, 10,000].
//The answer with the calculation error less than 10-5 will be accepted.

#include<vector>
#include<algorithm>

using namespace std;

class MaximuAverageSubarrayII {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double lo = INT_MAX, hi = INT_MIN;
		for (int i : nums){
			lo = min(lo, (double)i);
			hi = max(hi, (double)i);
		}
		double err = INT_MAX, pre = hi;
		while (err>0.00001){
			double mid = (lo + hi)*0.5;
			if (help(nums, mid, k)){
				lo = mid;
			}
			else{
				hi = mid;
			}
			err = abs(mid - pre);
			pre = mid;
			//cout<<lo<<endl;
		}
		return lo;
	}

	bool help(vector<int>& nums, double mid, int k){
		double sum = 0;
		for (int i = 0; i<k; ++i){
			sum += nums[i] - mid;
		}
		if (sum >= 0) return true;
		double pre_sum = 0, pre_min = 0;
		for (int i = k; i<nums.size(); ++i){
			sum += nums[i] - mid;
			pre_sum += nums[i - k] - mid;
			pre_min = min(pre_min, pre_sum);
			if (sum - pre_min >= 0) return true;
		}
		return false;
	}
};