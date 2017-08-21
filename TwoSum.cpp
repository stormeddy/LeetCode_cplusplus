//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].


#include<iostream>

#include<unordered_map>
#include<vector>

using namespace std;

class TwoSum {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for (size_t i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];

			//if numberToFind is found in map, return them
			if (hash.find(numberToFind) != hash.end()) {
				result.push_back(hash[numberToFind]);
				result.push_back(i);
				return result;
			}

			//number was not found. Put it in the map.
			hash[numbers[i]] = i;
		}
		return result;
	}
};

void main_TwoSum()
{
	int target = 9;
	vector<int> numbers = vector<int>{2, 7, 11, 15};
	TwoSum nb;
	vector<int> res = nb.twoSum(numbers, target);
	for (int i : res)
	{
		cout << i<< endl;
	}
	


}