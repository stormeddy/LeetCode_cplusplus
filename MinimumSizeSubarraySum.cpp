//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s.If there isn't one, return 0 instead.
//
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

#include<vector>
#include<algorithm>

using namespace std;

class MinimumSizeSubarraySum {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MAX;
		int left = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			while (sum >= s) {
				ans = min(ans, i + 1 - left);
				sum -= nums[left++];
			}
		}
		return (ans != INT_MAX) ? ans : 0;


		/*int n = nums.size();

		if (n == 0) return 0;
		int res = n + 1;
		vector<int> a(n, 0);
		a[0] = nums[0];

		for (int i = 1; i<n; ++i){
			a[i] = a[i - 1] + nums[i];
		}
		for (int i = 0; i<n; ++i){
			if (a[i] >= s){
				if (i + 1<res) res = i + 1;
			}
			int target = a[i] + s;
			int l = i + 1, h = n - 1;
			int mid = 0;
			while (l<h){
				mid = l + (h - l) / 2;
				if (a[mid] == target) break;
				else if (target<a[mid]) h = mid;
				else l = mid + 1;
			}
			if (l<h){
				int cur = mid - i;
				if (cur<res){
					res = cur;
				}
			}
			else if (l == h){
				if (a[l] >= target){
					int cur = l - i;
					if (cur<res){
						res = cur;
					}
				}
			}
		}
		if (res == n + 1) res = 0;
		return res;*/
	}
};