//#include "stdint.h"
#include<iostream>

using namespace std;

//Given an integer, write a function to determine if it is a power of two.



class PowerofTwo
{
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) return false;
		int nn = n;
		int t = 0;
		while (n)
		{
			++t;
			n >>= 1;
		}

		return (1 << (t - 1)) == nn;
	}

};


void main_PowerofTwo()
{
	int x = -16;
	PowerofTwo nb;

	cout << nb.isPowerOfTwo(x) << endl;



}