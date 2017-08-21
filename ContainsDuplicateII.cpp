//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

#include<vector>
#include<unordered_set>

using namespace std;

class ContainsDuplicatedII {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> s;
		int n = nums.size();
		if (k <= 0) return false;
		if (k > n) k = n - 1;
		for (int i = 0; i < n; ++i){
			if (i > k){
				s.erase(nums[i - k - 1]);
			}
			if (s.find(nums[i]) != s.end()) return true;
			s.insert(nums[i]);
		}
		return false;
	}
};