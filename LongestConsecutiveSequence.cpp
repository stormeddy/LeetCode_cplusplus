//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.

#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class LongestConsecutiveSequence {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		int res = 0;
		for (int i : nums){
			//if(s.find(i)==s.end()) continue;
			int pre = i - 1, nex = i + 1;
			s.erase(i);
			while (s.find(pre) != s.end()) s.erase(pre--);
			while (s.find(nex) != s.end()) s.erase(nex++);
			res = max(res, nex - pre - 1);
		}
		return res;
	}
};