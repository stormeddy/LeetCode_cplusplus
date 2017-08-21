//Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
//
//Example 1:
//Input: [3, 1, 4, 1, 5], k = 2
//Output: 2
//Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
//Although we have two 1s in the input, we should only return the number of unique pairs.
//Example 2:
//Input:[1, 2, 3, 4, 5], k = 1
//Output: 4
//Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
//Example 3:
//Input: [1, 3, 1, 5, 4], k = 0
//Output: 1
//Explanation: There is one 0-diff pair in the array, (1, 1).
//Note:
//The pairs (i, j) and (j, i) count as the same pair.
//The length of the array won't exceed 10,000.
//All the integers in the given input belong to the range: [-1e7, 1e7].

#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;



class KdiffPairsinanArray {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) {
			return 0;
		}
		unordered_set<int> starters;
		unordered_map<int, int> indices;
		for (int i = 0; i < nums.size(); i++) {
			if (indices.count(nums[i] - k)) {
				starters.insert(nums[i] - k);
			}
			if (indices.count(nums[i] + k)) {
				starters.insert(nums[i]);
			}

			indices[nums[i]] += 1;
		}

		return starters.size();



		/*int n = nums.size();
		sort(nums.begin(), nums.end());
		int i = 0;
		int res = 0;
		while (i<n){
		int j = i + 1;
		while (j<n){
		if (nums[j] - nums[i] == k){
		++res;
		}
		else if (nums[j] - nums[i]>k){
		break;
		}
		while (j<n - 1 && nums[j] == nums[j + 1]) ++j;
		++j;
		}
		while (i<n - 1 && nums[i] == nums[i + 1]) ++i;
		++i;
		}
		return res;*/
	}
};