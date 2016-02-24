// 1094.cpp : 定义控制台应用程序的入口点。
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
	//一层一层往下扒
	int  max = 1;
	int max_lev = 1;
	int cur_lev = 1;
	vector<int>v1, v2;
	v1.push_back(1);//从root=1出发
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
				v2.push_back(vec_arr[v1[i]][j]);//把当前层（v1）的所有孩子全都推到v2中
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

