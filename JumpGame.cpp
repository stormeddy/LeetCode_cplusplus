//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.

#include<vector>
#include<algorithm>

using namespace std;



class JumpGame {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<bool> can(n, false);
		can[0] = true;
		int end = 0;
		for (int i = 0; i<n - 1; ++i){
			if (can[i]){
				if (i + nums[i] >= n){
					return true;
				}
				else{
					if (i + nums[i]>end){
						for (int j = end + 1; j <= i + nums[i]; ++j) can[j] = true;
						end = i + nums[i];
					}

				}
			}
		}
		return can[n - 1];
	}
};