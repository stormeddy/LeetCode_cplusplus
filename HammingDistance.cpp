//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.
//
//Note:
//0 ¡Ü x, y < 231.
//
//Example:
//
//Input: x = 1, y = 4
//
//Output: 2
//
//Explanation:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ¡ü   ¡ü
//
//The above arrows point to positions where the corresponding bits are different.

#include<iostream>

using namespace std;
class HammingDistance
{
public:
	int hammingDistance(int x, int y) {
		int t = x^y;
		int res = 0;
		while (t != 0)
		{
			/*if (t & 1 == 1)
			{
			++res;
			}
			t >>= 1;*/

			//better one
			//turn off the right most bit in n in each iteration
			++res;
			t &= t - 1;
		}
		return res;
	}

};

void main_HammingDistance(){
	HammingDistance hd;
	int x = 2, y = 11;
	cout<<hd.hammingDistance(x,y)<<endl;
}
