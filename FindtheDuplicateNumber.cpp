//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
//Note:
//You must not modify the array (assume the array is read only).
//You must use only constant, O(1) extra space.
//Your runtime complexity should be less than O(n2).
//There is only one duplicate number in the array, but it could be repeated more than once.

#include<vector>

using namespace std;

class FindtheDuplicateNumber {
public:
	int findDuplicate(vector<int>& nums) {
		//O(nlogn)
		/*int n = nums.size() - 1;
		int low = 1;
		int high = n;
		int mid;
		while (low<high){
			mid = (low + high) / 2;
			int count = 0;
			for (int num : nums){
				if (num <= mid) count++;
			}
			if (count>mid) high = mid;
			else low = mid + 1;
		}
		return low;*/

		//O(n)

		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
		
	}
};