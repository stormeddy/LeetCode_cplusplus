//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -¡Þ.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//Your solution should be in logarithmic complexity.

#include<vector>

using namespace std;

class FindPeakElement {
public:
	int findPeakElement(vector<int>& num) {
		int l = 0, h = num.size() - 1;
		while (l<h){
			int mid = l + (h - l) / 2;
			if (num[mid]>num[mid + 1]){
				h = mid;
			}
			else{
				l = mid + 1;
			}
		}
		return l;
};