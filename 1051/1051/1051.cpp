// 1051.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int M, N, K;//MΪջ�����������NΪҪ������еĳ��ȣ�KΪ������
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

