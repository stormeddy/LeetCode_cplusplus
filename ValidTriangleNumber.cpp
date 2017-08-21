//Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//
//Example 1:
//Input: [2,2,3,4]
//Output: 3
//Explanation:
//Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
//Note:
//The length of the given array won't exceed 1000.
//The integers in the given array are in the range of [0, 1000].

#include<vector>
#include<algorithm>

using namespace std;

class ValidTriangleNumber {
public:
	int triangleNumber(vector<int>& nums) {
		if (nums.size()<3) return 0;
		sort(nums.begin(), nums.end());
		int res = 0;
		for (size_t i = 0; i<nums.size() - 2; ++i)
			for (size_t j = i + 1; j<nums.size() - 1; ++j){
				int k = j + 1;
				for (; k<nums.size() && nums[i] + nums[j]>nums[k]; ++k);
				res += k - j - 1;
			}
		return res;


		/*int n = nums.size();
		int res = 0;
		sort(nums.begin(), nums.end());
		for (int i = n - 1; i >= 2; --i){
			int l = 0, r = i - 1;
			while (l<r){
				if (nums[l] + nums[r]>nums[i]){
					res += r - l;
					--r;
				}
				else{
					++l;
				}
			}
		}
		return res;*/

	}
};