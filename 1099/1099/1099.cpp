// 1099.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
class Node {
public:
	int data;
	int left;
	int right;
};
Node *input;

void traverseInorder(int p,int *outData,int &count) {
	if (input[p].left != -1) {
	//	cout << input[p].left << endl;
		traverseInorder(input[p].left,outData,count);
	}
	input[p].data = outData[count++];
	if (input[p].right!=-1)
	{
		traverseInorder(input[p].right,outData,count);
	}
}
int main()
{
	int N;
	cin >> N;
	input = new Node[N];
	int i, j;
	for (int n = 0; n < N; n++)
	{
		cin >> i >> j;
		input[n].left = i;
		input[n].right = j;
	}
	int *data = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	sort(data, data + N);
	int index = 0;
	traverseInorder(0, data, index);
	queue<Node> assist;
	vector<Node>output;
	assist.push(input[0]);
	bool flag = false;
	while (!assist.empty())
	{
		Node p = assist.front();
		assist.pop();
		output.push_back(p);
		if (p.left!=-1)
		{
			assist.push(input[p.left]);
		}
		if (p.right!=-1)
		{
			assist.push(input[p.right]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << output[i].data;
		}
		else
		{
			cout << " " << output[i].data;
		}
	}
	cout << endl;
    return 0;
}

