// 1011.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<double>t1, t2, t3;
	double input;
	double max1, max2, max3;
	int flag1=0, flag2=0, flag3=0;
	for (int i = 0; i <3; i++)
	{
		cin >> input;
		t1.push_back(input);
		if (i==0)
		{
			max1 = input;
		}
		else
		{
			if (input>max1)
			{
				max1 = input;
				flag1 = i;
			}
		}
	}
	for (int i = 0; i <3; i++)
	{
		cin >> input;
		t2.push_back(input);
		if (i == 0)
		{
			max2 = input;
		}
		else
		{
			if (input>max2)
			{
				max2 = input;
				flag2 = i;
			}
		}
	}
	for (int i = 0; i <3; i++)
	{
		cin >> input;
		t3.push_back(input);
		if (i == 0)
		{
			max3 = input;
		}
		else
		{
			if (input>max3)
			{
				max3 = input;
				flag3 = i;
			}
		}
	}
	char w1, w2, w3;
	string model = "WTL";
	cout << model[flag1] << " " << model[flag2] << " " << model[flag3] << " ";
	double result = (t1[flag1] * t2[flag2] * t3[flag3] *0.65- 1) * 2;
	printf("%.2f\n", result);
    return 0;
}

