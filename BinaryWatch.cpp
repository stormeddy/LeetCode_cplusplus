//A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//
//Each LED represents a zero or one, with the least significant bit on the right.
//
//
//For example, the above binary watch reads "3:25".
//
//Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
//Example:
//
//Input: n = 1
//Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//Note:
//The order of output does not matter.
//The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

#include<vector>
#include<bitset>
#include<string>
#include<iostream>

using namespace std;

class BinaryWatch
{
//public:
//	vector<string> readBinaryWatch(int num) {
//		vector<string> r;
//		for (int i = 0; i < 12; i++)
//		{
//			for (int j = 0; j < 60; j++)
//			{
//				if (bitset<10>(i<<6|j).count()==num)
//				{
//					r.emplace_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
//				}
//			}
//		}
//		return r;
//	}


	vector<int> hour = vector<int>{ 1, 2, 4, 8 }, minute = vector<int>{ 1, 2, 4, 8, 16, 32 };
public:
	vector<string> readBinaryWatch(int num){
		vector<string> res;
		help(res, make_pair(0, 0), num, 0);
		return res;
	}

	void help(vector<string>& r, pair<int,int> time,int num,int start){
		if (!num)
		{
			r.emplace_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
		}
		for (int j = start; j < hour.size()+minute.size(); j++)
		{
			if (j<hour.size())
			{
				time.first += hour[j];
				if (time.first<12)
				{
					help(r, time, num - 1, j + 1);
				}
				time.first -= hour[j];
			}
			else
			{
				time.second += minute[j - hour.size()];
				if (time.second<60)
				{
					help(r, time, num - 1, j + 1);
				}
				time.second -= minute[j - hour.size()];
			}
		}
	}

};


void main_BinaryWatch()
{
	int x=5;
	BinaryWatch nb;

	vector<string> r = nb.readBinaryWatch(x);
	for (auto i = r.cbegin(); i != r.cend();i++)
	{
		cout << (*i) << endl;
	}


}