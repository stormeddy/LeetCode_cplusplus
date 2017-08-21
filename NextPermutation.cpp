//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//1, 2, 3 ¡ú 1, 3, 2
//3, 2, 1 ¡ú 1, 2, 3
//1, 1, 5 ¡ú 1, 5, 1

#include<vector>
#include<algorithm>

using namespace std;

class Subsets {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1, k = i;
		while (i > 0 && nums[i - 1] >= nums[i])
			i--;
		for (int j = i; j<k; j++, k--)
			swap(nums[j], nums[k]);
		if (i > 0) {
			k = i--;
			while (nums[k] <= nums[i])
				k++;
			swap(nums[i], nums[k]);
		}


		//int n = nums.size();
		//int j = n - 1;
		////int idx=n-1;
		////int low=nums[j];
		//while (j >= 1 && nums[j] <= nums[j - 1]){
		//	//if(nums[j]<low) idx=j;
		//	--j;
		//}
		//if (j == 0){
		//	sort(nums.begin(), nums.end());
		//}
		//else{
		//	//cout<<j<<endl;
		//	int pre = nums[j - 1];
		//	int pre_ind = j - 1;
		//	int idx = j;
		//	int low = nums[j];
		//	while (j<n){
		//		if (nums[j]<low&& nums[j]>pre) { idx = j; low = nums[j]; }
		//		++j;
		//	}
		//	swap(nums[idx], nums[pre_ind]);
		//	sort(nums.begin() + pre_ind + 1, nums.end());
		//}
		//}
	}
};