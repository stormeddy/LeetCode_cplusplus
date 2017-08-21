//Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
//
//You need to find the shortest such subarray and output its length.
//
//Example 1:
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//Note:
//Then length of the input array is in range [1, 10,000].
//The input array may contain duplicates, so ascending order here means <=.

#include<vector>
#include<algorithm>

using namespace std;

class ShortestUnsortedContinuousSubarray {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		int start = n, end = 0;
		for (int i = 0; i<n - 1; ++i){
			if (nums[i]>nums[i + 1]){
				start = i;
				break;
			}
		}
		for (int i = n - 1; i >= 1; --i){
			if (nums[i]<nums[i - 1]){
				end = i;
				break;
			}
		}
		if (start>end) return 0;
		int lo = nums[start], hi = nums[end];
		for (int i = start; i <= end; ++i){
			lo = min(lo, nums[i]);
			hi = max(hi, nums[i]);
		}
		while (start >= 0 && nums[start]>lo) --start;
		++start;
		while (end<n && nums[end]<hi) ++end;
		--end;
		//cout<<start<<endl;
		//cout<<end<<endl;
		return end - start + 1;
	}
};