#include<cmath>
#include<iostream>

using namespace std;

//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//Given num = 16, return true.Given num = 5, return false.
//
//Follow up : Could you solve it without loops / recursion ?



class PowerofFour
{
public:
	bool isPowerofFour(int num) {
		//return fmod(log10(n) / log10(4), 1) == 0;
		return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
	}

};


void main_PowerofFour()
{
	int x = -16;
	PowerofFour nb;
	cout << INT_MAX << endl;
	cout << nb.isPowerofFour(x) << endl;



}