//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

#include<vector>

using namespace std;

class SearchinRotatedSortedArray {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return -1;
		int lo = 0, hi = n - 1;
		while (lo<hi){
			if (nums[lo]<nums[hi]){
				return help(nums, target, lo, hi);
			}
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			if ((nums[mid]>nums[lo] && target<nums[mid] && target >= nums[lo])
				|| (nums[mid]<nums[hi] && (target<nums[mid] || target >= nums[lo]))){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		if (nums[lo] == target) return lo;
		return -1;
	}

	int help(vector<int>& nums, int target, int lo, int hi) {

		while (lo<hi){
			int mid = lo + (hi - lo) / 2;
			if (target == nums[mid]) return mid;
			if (target<nums[mid]){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		if (nums[lo] == target) return lo;
		return -1;
	}


	/*int search(vector<int>& A, int target) {
		int n = A.size();
		if (n == 0) return -1;
		int lo = 0, hi = n - 1;
		int mid = 0;
		while (lo<hi){
			mid = (lo + hi) / 2;
			if (A[mid] == target) return mid;
			if (A[mid]>A[hi]){
				if (A[mid]>target && A[lo] <= target) hi = mid;
				else lo = mid + 1;
			}
			else if (A[mid] < A[hi]){
				if (A[mid]<target && A[hi] >= target) lo = mid + 1;
				else hi = mid;
			}

		}
		return A[lo] == target ? lo : -1;
	}*/
};