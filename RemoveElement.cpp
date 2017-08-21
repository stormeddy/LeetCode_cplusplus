//Given an array and a value, remove all instances of that value in place and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//Example:
//Given input array nums = [3,2,2,3], val = 3
//
//Your function should return length = 2, with the first two elements of nums being 2.

#include<vector>
#include<algorithm>

using namespace std;

class RemoveElement {
public:
	int removeElement(vector<int>& nums, int val) {
		int l = 0, r = nums.size() - 1;
		int res = 0;
		while (l <= r){
			while (l <= r&&nums[l] != val) ++l;
			while (l <= r&&nums[r] == val) { --r; ++res; }
			if (l <= r){
				swap(nums[l], nums[r]);
				++res;
				++l;
				--r;
			}
		}
		return nums.size() - res;

		/*int cnt = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == val)
				cnt++;
			else
				nums[i - cnt] = nums[i];
		}
		return nums.size() - cnt;*/
	}
};