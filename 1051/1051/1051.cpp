// 1051.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int M, N, K;//M为栈的最大容量，N为要检查序列的长度，K为检查次数
	cin >> M >> N >> K;
	stack<int>check;
	int input;
	for (int i = 0; i < K; i++) {
		int temp = 1;
		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			while (check.size()<=M&&flag)
			{
				if (check.empty() ||input!=check.top())
				{
					check.push(temp++);
				}
				else if(input==check.top())
				{
					check.pop();
					break;
				}


			}
			
		}
		if (check.size()>M) {
			flag = false;

		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		while  (!check.empty()) {
			check.pop();
		}
	}

    return 0;
}

