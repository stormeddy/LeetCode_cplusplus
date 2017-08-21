//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.
//

#include<vector>

using namespace std;

class FindMinimuminRotatedSortedArrayII {
public:
	int findMin(vector<int>& num) {
		int lo = 0;
		int hi = num.size() - 1;
		int mid = 0;

		while (lo < hi) {
			if (num[lo]<num[hi]) break;
			mid = lo + (hi - lo) / 2;

			if (num[mid] > num[hi]) {
				lo = mid + 1;
			}
			else if (num[mid] < num[hi]) {
				hi = mid;
			}
			else { // when num[mid] and num[hi] are same
				++lo;
				--hi;
			}
		}
		return num[lo];
	}
};