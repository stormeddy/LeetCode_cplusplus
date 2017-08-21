//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.

#include<vector>
#include<algorithm>

using namespace std;

class JumpGameII {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int start = 0, end = 0;
		int res = 0;
		while (end<n - 1){
			++res;
			int next_end = end + 1;
			for (int i = start; i <= end; ++i){
				if (i + nums[i] >= n - 1) return res;
				next_end = max(next_end, i + nums[i]);
			}
			start = end + 1;
			end = next_end;
		}
		return res;
	}
};