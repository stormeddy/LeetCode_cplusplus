//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 ¡ú 2
//[1,3,5,6], 2 ¡ú 1
//[1,3,5,6], 7 ¡ú 4
//[1,3,5,6], 0 ¡ú 0

#include<vector>

using namespace std;

class SearchInsertPosition {
public:
	int searchInsert(vector<int>& nums, int target) {
		int le = 0, ri = nums.size() - 1;
		int mid = 0;
		while (le<ri)
		{
			mid = le + (ri - le) / 2;
			if (nums[mid]<target)
			{
				le = mid + 1;
			}
			else if (nums[mid]>target)
			{
				ri = mid;
			}
			else
			{
				return mid;
			}
		}
		if (le == nums.size() - 1 && nums[le]<target) ++le;
		return le;
	}
};