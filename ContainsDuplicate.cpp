//Given an array of integers, find if the array contains any duplicates.Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class ContainsDuplicate {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int i : nums)
		{
			if (s.find(i) != s.end())
			{
				return true;
			}
			s.insert(i);
		}
		return false;

		//return nums.size()>unordered_set<int>(nums.begin(), nums.end()).size();
	}
};