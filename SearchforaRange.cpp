//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].

#include<vector>

using namespace std;

class UniquePathsII {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int l = 0, h = nums.size() - 1;
		vector<int> res(2, -1);
		if (nums.size() == 0) return res;
		int mid = 0;
		while (l<h){
			mid = l + (h - l) / 2;
			if (nums[mid] == target) break;
			if (nums[mid]<target){
				l = mid + 1;
			}
			else{
				h = mid;
			}
		}
		if (l<h || nums[l] == target){
			mid = l + (h - l) / 2;
			//cout << mid << endl;
			while (mid>0 && nums[mid] == nums[mid - 1]){
				int lo = l, hi = mid - 1;
				mid = help(nums, lo, hi, target);
			}
			res[0] = mid;
			mid = l + (h - l) / 2;
			//cout << mid << endl;
			while (mid<nums.size() - 1 && nums[mid] == nums[mid + 1]){
				int lo = mid + 1, hi = h;
				mid = help(nums, lo, hi, target);
			}
			res[1] = mid;
		}
		return res;
	}

	int help(vector<int>& nums, int l, int h, int target){
		int mid = 0;
		while (l<h){
			mid = l + (h - l) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid]<target){
				l = mid + 1;
			}
			else{
				h = mid;
			}
		}
		if (nums[l] == target) return l;
		return -1;
	}



	//java version, more concise
	/*public int[] searchRange(int[] nums, int target) {
		int[] result = new int[2];
		result[0] = findFirst(nums, target);
		result[1] = findLast(nums, target);
		return result;
	}

	private int findFirst(int[] nums, int target){
		int idx = -1;
		int start = 0;
		int end = nums.length - 1;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] >= target){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
			if (nums[mid] == target) idx = mid;
		}
		return idx;
	}

	private int findLast(int[] nums, int target){
		int idx = -1;
		int start = 0;
		int end = nums.length - 1;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] <= target){
				start = mid + 1;
			}
			else{
				end = mid - 1;
			}
			if (nums[mid] == target) idx = mid;
		}
		return idx;
	}*/
};