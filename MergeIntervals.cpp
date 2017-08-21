//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].
//

#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(Interval a, Interval b) // 注意comp函数可以为static bool或者bool，返回值为bool类型。a.start<b.start为升序  
{
	return a.start < b.start;
}


class MergeIntervals {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		int n = intervals.size();
		vector<Interval> res;
		if (n == 0) return res;
		sort(intervals.begin(), intervals.end(), comp);
		res.push_back(intervals[0]);
		for (int i = 1; i<n; ++i){
			Interval cur = intervals[i];
			if (cur.start>res.back().end){
				res.push_back(cur);
			}
			else{
				res.back().end = max(res.back().end, cur.end);
			}
		}
		return res;
	}
};