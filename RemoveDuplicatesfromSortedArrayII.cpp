//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array nums = [1,1,1,2,2,3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

#include<vector>

using namespace std;

class RemoveDuplicatesfromSortedArray {
public:
	int removeDuplicates(vector<int>& A) {
		int count = 0, n = A.size();
		if (n == 0) return 0;
		for (int i = 1; i < n - 1; i++){
			if (A[i] == A[i - 1] && A[i] == A[i + 1]) count++;
			else A[i - count] = A[i];
		}
		A[n - 1 - count] = A[n - 1];
		return n - count;
	}
};