//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.

#include<vector>
#include<algorithm>

using namespace std;

class WordSearch {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		for (int i = 0; i<m; ++i){
			for (int j = 0; j<n; ++j){
				if (help(board, word, 0, m, n, i, j)) return true;
			}
		}
		return false;
	}

	bool help(vector<vector<char>>& board, string word, int cur, int m, int n, int x, int y){
		if (x<0 || x >= m || y<0 || y >= n || board[x][y] == '\0' || board[x][y] != word.at(cur)) return false;
		if (cur == word.size() - 1) return true;
		char t = board[x][y];
		board[x][y] = '\0';
		if (help(board, word, cur + 1, m, n, x - 1, y) || help(board, word, cur + 1, m, n, x + 1, y) || help(board, word, cur + 1, m, n, x, y - 1)
			|| help(board, word, cur + 1, m, n, x, y + 1)) return true;
		board[x][y] = t;
		return false;
	}
};