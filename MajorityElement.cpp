//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.

#include<vector>
#include<algorithm>

using namespace std;

class MajorityElement {
public:
	int majorityElement(vector<int>& nums) {
		nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
		return nums[nums.size() / 2];
	}
};