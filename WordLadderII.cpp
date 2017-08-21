//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//Only one letter can be changed at a time
//Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//For example,
//
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log","cog"]
//Return
//  [
//    ["hit","hot","dot","dog","cog"],
//    ["hit","hot","lot","log","cog"]
//  ]
//Note:
//Return an empty list if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non-empty and are not the same.

#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<string>

using namespace std;

class WordLadderII {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict;
		dict.insert(wordList.begin(), wordList.end());
		dict.insert(beginWord);

		unordered_map<string, vector<string>> nei;
		unordered_map<string, int> dist;
		vector<string> sol;
		vector<vector<string>> res;
		bfs(beginWord, endWord, dict, nei, dist);
		dfs(beginWord, endWord, dict, nei, dist, sol, res);
		return res;
	}

private:
	void bfs(string start, string end, unordered_set<string>& dict,unordered_map<string, vector<string>>& nei, unordered_map<string, int>& dist){
		for (string s : dict){
			nei[s] = vector<string>();
		}
		queue<string> q;
		q.push(start);
		dist[start] = 0;
		while (!q.empty()){
			int cnt = q.size();
			bool found = false;
			for (int i = 0; i < cnt; i++){
				string cur = q.front();
				q.pop();
				int cur_dist = dist[cur];
				get_neighbours(cur, dict,nei[cur]);
				for (string s : nei[cur]){					
					if (dist.find(s) == dist.end()){
						dist[s] = cur_dist + 1;
						if (s.compare(end) == 0) found = true;
						else q.push(s);
					}
				}
			}
			if (found) break;

		}

	}

	void get_neighbours(string cur, unordered_set<string>& dict, vector<string>& res){
		for (char ch = 'a'; ch <= 'z'; ++ch){
			for (int i = 0; i < cur.size(); ++i){
				if (cur[i] == ch) continue;
				char tmp = cur[i];
				cur[i] = ch;
				if (dict.find(cur) != dict.end()){
					res.push_back(cur);
				}
				cur[i] = tmp;
			}
		}
	}


	void dfs(string cur, string end, unordered_set<string>& dict, unordered_map<string, vector<string>>& nei, unordered_map<string, int>& dist, vector<string>& sol, vector<vector<string>>& res){
		sol.push_back(cur);
		if (cur.compare(end) == 0) res.push_back(sol);
		else{
			for (string next : nei[cur]){
				if (dist[next] == dist[cur] + 1){
					dfs(next, end, dict, nei, dist, sol, res);
				}
			}
		}
		sol.pop_back();
	}
};


void main_WordLadderII()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = vector<string>{"hot", "dot", "dog", "lot", "log", "cog"};
	WordLadderII wl2;
	vector<vector<string>> res = wl2.findLadders(beginWord, endWord, wordList);
	for (vector<string> cur : res){
		for (string s : cur){
			cout << s <<" ";
		}
		cout <<""<< endl;
	}



}