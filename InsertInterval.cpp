//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//Example 2:
//Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class InsertInterval {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		auto it = intervals.begin();
		for (; it != intervals.end(); ++it){
			if (newInterval.end < (*it).start) //all intervals after will not overlap with the newInterval
				break;
			else if (newInterval.start >(*it).end) //*it will not overlap with the newInterval
				ret.push_back(*it);
			else{ //update newInterval bacause *it overlap with the newInterval
				newInterval.start = min(newInterval.start, (*it).start);
				newInterval.end = max(newInterval.end, (*it).end);
			}
		}
		// don't forget the rest of the intervals and the newInterval
		ret.push_back(newInterval);
		for (; it != intervals.end(); ++it)
			ret.push_back(*it);
		return ret;
	}
};