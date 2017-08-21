//Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.The algorithm should run in linear time and in O(1) space.

#include<vector>
#include<algorithm>

using namespace std;

class MajorityElementsII {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int x = 0, y = 0, c1 = 0, c2 = 0;
		for (int i : nums){
			if (x == i){
				++c1;
			}
			else if (y == i){
				++c2;
			}
			else if (!c1){
				x = i;
				c1 = 1;
			}
			else if (!c2){
				y = i;
				c2 = 1;
			}
			else{
				--c1;
				--c2;
			}
		}
		c1 = c2 = 0;
		for (int i : nums){
			if (x == i) ++c1;
			else if (y == i) ++c2;
		}
		vector<int> res;
		if (c1>nums.size() / 3) res.push_back(x);
		if (c2>nums.size() / 3) res.push_back(y);
		return res;
	}
};