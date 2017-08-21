#include "stdint.h"
#include<iostream>

using namespace std;
//Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).
//
//For example, the 32 - bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.



class Numberof1Bits
{
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n)
		{
			/*if (n&1){
			++res;
			}
			n >>= 1;*/
			++res;
			n &= n - 1;
		}
		return res;
	}

};


void main_Numberof1Bits()
{
	uint32_t x = 11;
	Numberof1Bits nb;

	cout << nb.hammingWeight(x) << endl;



}