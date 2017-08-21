//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Write a function to determine if a given target is in the array.
//
//The array may contain duplicates.

#include<vector>

using namespace std;

class SearchinRotatedSortedArrayII {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return false;
		int lo = 0, hi = n - 1;
		while (lo<hi){
			if (nums[lo]<nums[hi]){
				return help(nums, target, lo, hi);
			}
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid] == nums[hi]){
				--hi; continue;
			}
			if ((nums[mid]>nums[lo] && target<nums[mid] && target >= nums[lo])
				|| (nums[mid]<nums[hi] && (target<nums[mid] || target >= nums[lo]))){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		if (nums[lo] == target) return true;
		return false;
	}

	int help(vector<int>& nums, int target, int lo, int hi) {

		while (lo<hi){
			int mid = lo + (hi - lo) / 2;
			if (target == nums[mid]) return true;
			if (target<nums[mid]){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		if (nums[lo] == target) return true;
		return false;
	}


	/*bool search(vector<int>& A, int target) {
		int n = A.size();
		if (n == 0) return false;
		int lo = 0, hi = n - 1;
		int mid = 0;
		while (lo<hi){
			mid = (lo + hi) / 2;
			if (A[mid] == target) return true;
			if (A[mid]>A[hi]){
				if (A[mid]>target && A[lo] <= target) hi = mid;
				else lo = mid + 1;
			}
			else if (A[mid] < A[hi]){
				if (A[mid]<target && A[hi] >= target) lo = mid + 1;
				else hi = mid;
			}
			else{
				hi--;
			}

		}
		return A[lo] == target ? true : false;
	}*/
};