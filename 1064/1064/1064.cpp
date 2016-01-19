// 1064.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<stack>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
vector<int>node;
vector<int>tree;

stack<int> s;
void goAlongLeftBranch(int x) {
	while (x<=N)
	{
		s.push(x);
		x = 2 * x;
	}
}
int counter = 1;
void travIn() {
	int x = 1;
	while (true)
	{
		goAlongLeftBranch(x);
		if (s.empty())
		{
			break;
		}
		x = s.top();
		s.pop();
		int temp = node[counter];
		tree[x] = temp;
		counter++;
		x = 2 * x + 1;
	}
}
void print() {
	cout << tree[1];
	for (int i = 2; i <= N; i++)
	{
		cout <<" "<< tree[i] ;
	}
	cout << endl;
}
int main()
{
	cin >> N;
	node.resize(N + 1);
	tree.resize(N + 1);
	for (int i = 1; i <=N; i++)
	{
		cin >> node[i];
	}
	sort(node .begin(), node .end());
//	print();
	travIn();
	print();
	return 0;
}
