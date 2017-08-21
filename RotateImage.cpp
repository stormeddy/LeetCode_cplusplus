//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Follow up :
//Could you do this in - place ?

#include<vector>

using namespace std;

class RotateImage {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i<n / 2; ++i){
			for (int j = i; j<n - i - 1; ++j){
				int t = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = t;
			}
		}
	}


	/*
	* clockwise rotate
	* first reverse up to down, then swap the symmetry
	* 1 2 3     7 8 9     7 4 1
	* 4 5 6  => 4 5 6  => 8 5 2
	* 7 8 9     1 2 3     9 6 3
	*/
	/*void rotate(vector<vector<int> > &matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = i + 1; j < matrix[i].size(); ++j)
				swap(matrix[i][j], matrix[j][i]);
		}
	}*/
};