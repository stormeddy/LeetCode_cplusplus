//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].

#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Subsets {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int n = nums.size();
		vector<string> res;
		if (n == 0) return res;
		int st = nums[0], end = nums[0];
		for (int i = 1; i < n; ++i){
			if (nums[i] == end + 1){
				end = nums[i];
			}
			else{
				if (st != end){
					//cout<<st<<endl;
					//cout<<to_string(st)+"->"+to_string(end)<<endl;
					res.push_back(to_string(st) + "->" + to_string(end));
				}
				else{
					res.push_back(to_string(st));
				}
				st = end = nums[i];
			}
		}
		if (st != end){
			//cout<<st<<endl;
			//cout<<to_string(st)+"->"+to_string(end)<<endl;
			res.push_back(to_string(st) + "->" + to_string(end));
		}
		else{
			res.push_back(to_string(st));
		}
		return res;
	}
};