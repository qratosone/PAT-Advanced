// 1008.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	queue<int> q;
	int n;
	while (cin>>n)
	{
		q.push(n);
	}
	q.pop();
	int now = 0;
	int count = 0;
	while (!q.empty())
	{
		int newFloor = q.front();
		q.pop();
		if (newFloor>now)
		{
			count += 6 * (newFloor - now);
		}
		else if(now>newFloor)
		{
			count += 4 * (now - newFloor);
		}
		now = newFloor;
		count += 5;
	}
	cout << count << endl;
    return 0;
}

