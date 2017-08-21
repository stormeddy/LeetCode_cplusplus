//Given a string, your task is to count how many palindromic substrings in this string.
//
//The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
//Example 1:
//Input: "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//Input: "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//Note:
//The input string length won't exceed 1000.

#include<vector>
#include<algorithm>

using namespace std;

class PalindromicSubstrings {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int res = 0;
		for (int i = 0; i<n; ++i){
			for (int j = 0; i - j >= 0 && i + j<n && s[i - j] == s[i + j]; ++j) ++res;
			for (int j = 1; i - j + 1 >= 0 && i + j<n && s[i - j + 1] == s[i + j]; ++j) ++res;
		}
		return res;
	}
};