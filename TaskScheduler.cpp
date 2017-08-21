//Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
//
//However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
//
//You need to return the least number of intervals the CPU will take to finish all the given tasks.
//
//Example 1:
//Input: tasks = ['A','A','A','B','B','B'], n = 2
//Output: 8
//Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
//Note:
//The number of tasks is in the range [1, 10000].
//The integer n is in the range [0, 100].

#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class TaskScheduler {
public:
	int leastInterval(vector<char>& tasks, int n) {
		//O(nlgn)
		unordered_map<char, int> m;
		for (char c : tasks)
		{
			++m[c];
		}
		priority_queue<int> q;
		for (pair<char, int> p : m)
		{
			q.push(p.second);
		}
		int period = n + 1;
		int res = 0;
		while (!q.empty())
		{
			int time = 0;
			vector<int> tmp;
			for (int i = 0; i<period; ++i)
			{
				if (!q.empty())
				{
					tmp.push_back(q.top());
					q.pop();
					++time;
				}
			}
			for (int i = 0; i<tmp.size(); ++i)
			{
				if (--tmp[i])
				{
					q.push(tmp[i]);
				}
			}

			res += q.empty() ? time : period;
		}
		return res;

		//O(n)
		/*unordered_map<char, int>mp;
		int count = 0;
		for (auto e : tasks)
		{
			mp[e]++;
			count = max(count, mp[e]);
		}

		int ans = (count - 1)*(n + 1);
		for (auto e : mp) if (e.second == count) ans++;
		return max((int)tasks.size(), ans);*/
	}
};