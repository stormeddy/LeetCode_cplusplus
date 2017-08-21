//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution and you may not use the same element twice.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include<vector>

using namespace std;

class TwoSumII_Inputarrayissorted {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int start = 0, end = numbers.size() - 1;
		int sum = numbers[start] + numbers[end];
		while (sum != target)
		{
			if (sum<target)
			{
				++start;
			}
			else
			{
				--end;
			}
			sum = numbers[start] + numbers[end];
		}
		vector<int> res;
		res.push_back(start + 1);
		res.push_back(end + 1);
		return res;
	}
};