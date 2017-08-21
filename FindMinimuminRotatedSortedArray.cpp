//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

#include<vector>
#include<algorithm>

using namespace std;

class FindMinimuminRotatedSortedArray {
public:
	int findMin(vector<int>& nums) {
		int le = 0, ri = nums.size() - 1;
		int mid = 0;
		while (le<ri - 1)
		{
			mid = le + (ri - le) / 2;
			if (nums[mid]>nums[ri])
			{
				le = mid;
			}
			else if (nums[mid]<nums[le])
			{
				ri = mid;
			}
			else
				break;
		}
		return min(nums[le], nums[ri]);


		/*int start = 0, end = nums.size() - 1;

		while (start<end) {
			if (nums[start]<nums[end])
				return nums[start];

			int mid = (start + end) / 2;

			if (nums[mid] >= nums[start]) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}

		return nums[start];*/
	}
};