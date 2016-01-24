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
	Node *left;
	Node *right;
	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
};
Node *input;
void buildTree(Node p,int i, int j) {
	if (i != -1) {
		p.left = &(input[i]);	
	}
	if (j != -1) {
		p.right = &(input[j]);
	}
}
void traverseInorder(Node p,int *outData,int &count) {
	if (p.left!=NULL)
	{
		traverseInorder(*(p.left),outData,count);
	}
	p.data = outData[count++];
	if (p.right!=NULL)
	{
		traverseInorder(*(p.right),outData,count);
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
		buildTree(input[n], i, j);
	}
	int *data = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	sort(data, data + N);
	int index = 0;
	traverseInorder(input[0], data, index);
	queue<Node> assist;
	assist.push(input[0]);
	bool flag = false;
	while (!assist.empty())
	{
		Node p = assist.front();
		assist.pop();
		if (!flag)
		{
			cout << p.data;
			flag = true;
		}
		else
		{
			cout << " " << p.data;
		}
		if (p.left!=NULL)
		{
			assist.push(p->left);
		}

	}
    return 0;
}

