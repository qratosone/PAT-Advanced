// 1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main() {
	string locker, unlocker;
	string lockerTime, unlockerTime;
	string name, inTime, outTime;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> inTime >> outTime;
		if (i==0)
		{
			locker = name;
			unlocker = name;
			lockerTime = outTime;
			unlockerTime = inTime;
			continue;
		}
		if (inTime < unlockerTime) {
			unlocker = name;
			unlockerTime = inTime;
		}
		if (outTime>lockerTime)
		{
			locker = name;
			lockerTime = outTime;
		}
	}
	cout << unlocker <<" "<< locker << endl;
	return 0;
}