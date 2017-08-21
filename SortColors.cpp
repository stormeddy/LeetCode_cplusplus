//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.
//
//click to show follow up.
//
//Follow up:
//A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one-pass algorithm using only constant space?

#include<vector>

using namespace std;

class SortColors {
public:
	void sortColors(vector<int>& nums) {
		int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;

		while (mid <= high)
		{
			if (nums[mid] == 0)
			{
				tmp = nums[low];
				nums[low] = nums[mid];
				nums[mid] = tmp;
				low++;
				mid++;
			}
			else if (nums[mid] == 1)
			{
				mid++;
			}
			else if (nums[mid] == 2)
			{
				tmp = nums[high];
				nums[high] = nums[mid];
				nums[mid] = tmp;
				high--;
			}
		}

		//int r = 0, w = 0, b = 0; // label the end of different colors;
		//for (int num : nums){
		//	if (num == 0) { nums[b++] = 2; nums[w++] = 1; nums[r++] = 0; }
		//	else if (num == 1) { nums[b++] = 2; nums[w++] = 1; }
		//	else if (num == 2) b++;
		//}
	}
};