//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.

#include<vector>
#include<algorithm>

using namespace std;

class MaximumProductSubarray {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		int hi = nums[0], lo = nums[0], res = nums[0];
		for (int i = 1; i<n; ++i){
			int t = hi;
			hi = max(hi*nums[i], max(lo*nums[i], nums[i]));
			lo = min(t*nums[i], min(lo*nums[i], nums[i]));
			res = max(res, hi);
		}
		return res;
	}
};