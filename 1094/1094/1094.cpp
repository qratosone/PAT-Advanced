// 1094.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void outputvector(vector<int>v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec_arr[100];
	while (m--) {
		int parent, count;
		cin >> parent >> count;
		while (count--) {
			int child;
			cin >> child;
			vec_arr[parent].push_back(child);
		}
	}
	//һ��һ�����°�
	int  max = 1;
	int max_lev = 1;
	int cur_lev = 1;
	vector<int>v1, v2;
	v1.push_back(1);//��root=1����
	while (true)
	{
		cur_lev++;
		if (v1.size()==0)
		{
			break;
		}
		//outputvector(v1);
		for (int i = 0; i < v1.size(); i++)
		{
			//outputvector(v1);
			for (int j = 0; j < vec_arr[v1[i]].size(); j++) {
				//cout << vec_arr[v1[i]][j] << endl;
				v2.push_back(vec_arr[v1[i]][j]);//�ѵ�ǰ�㣨v1�������к���ȫ���Ƶ�v2��
			}
		}
		//outputvector(v2);
		if (v2.size()>max)
		{
			max = v2.size();
			max_lev = cur_lev;
		}
		v1 = v2;
		v2.clear();
	}
	cout << max << " " << max_lev << endl;
    return 0;
}

