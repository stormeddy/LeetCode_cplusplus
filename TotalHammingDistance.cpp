//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Now your job is to find the total Hamming distance between all pairs of the given numbers.
//
//Example:
//Input: 4, 14, 2
//
//Output: 6
//
//Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
//showing the four bits relevant in this case). So the answer will be:
//HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
//Note:
//Elements of the given array are in the range of 0 to 10^9
//Length of the array will not exceed 10^4.

#include<vector>
#include<iostream>
using namespace std;

class TotalHammingDistance{
public :
	int totalHammingDistance(vector<int>& nums){
		/*int cnt = 0, res = 0;
		int m[2];
		while (true)
		{
			m[0] = 0;
			m[1] = 0;
			cnt = 0;
			for (size_t i = 0; i < nums.size(); ++i)
			{
				if (!nums[i])
				{
					++cnt;
				}
				++m[nums[i] & 1];
				nums[i] >>= 1;
			}
			res += m[0] * m[1];
			if (cnt == nums.size())
			{
				break;
			}
		}
		return res;*/





		if (nums.size() <= 0) return 0;

		int res = 0;

		for (int i = 0; i<32; i++) {
			int setCount = 0;
			for (int j = 0; j<nums.size(); j++) {
				if ((nums[j] & (1 << i)) != 0) setCount++;
			}

			res += setCount * (nums.size() - setCount);
		}

		return res;
	}
	
};

void main_TotalHammingDistance()
{
	TotalHammingDistance thd;
	int a[] = { 4, 14, 2 };
	vector<int> nums;
	for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		//cout << a[i] << endl;
		nums.push_back(a[i]);
	}
	cout << thd.totalHammingDistance(nums) << endl;



}