//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//
//[show hint]
//
//Hint:
//Could you do it in-place with O(1) extra space?
//Related problem: Reverse Words in a String II

#include<vector>
#include<algorithm>

using namespace std;

class RotateArray {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;
		int count = 0;
		for (int start = 0; count < n; start++) {
			int current = start;
			int prev = nums[start];
			do {
				int next = (current + k) % n;
				int temp = nums[next];
				nums[next] = prev;
				prev = temp;
				current = next;
				count++;
			} while (start != current);
		}
	}
};