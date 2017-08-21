#include<cmath>
#include<iostream>

using namespace std;

//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?



class PowerofThree
{
public:
	bool isPowerOfThree(int n) {
		//return fmod(log10(n) / log10(3), 1) == 0;
		return (n>0 && 1162261467 % n == 0);
	}

};


void main_PowerofThree()
{
	int x = -16;
	PowerofThree nb;
	cout << INT_MAX << endl;
	cout << nb.isPowerOfThree(x) << endl;



}