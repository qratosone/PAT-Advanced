// 1020.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct Node {
	Node * lchild;
	Node * rchild;
	int data;
}Node;
int post[31]; //LRV
int in[31]; //LVR
Node *tree;

void buildTree(int p1, int p2, int i1, int i2, Node* &treeNode) {
	if (treeNode==NULL)
	{
		treeNode = new Node();
	}
	if (p1>p2||i1>i2)
	{
		return;
	}
	treeNode->lchild = NULL;
	treeNode->rchild = NULL;
	for (int i =i1 ; i <=i2; i++)
	{
		if (post[p2] == in[i]) { //V found
			treeNode->data = in[i];
//			tree.lchild = new Node();
			int length = i - i1;
			if (length!=0)
			{
				tree->lchild = new Node();
				buildTree(p1, p1 + length - 1, i1, i1 + length - 1, tree->lchild);
			}
			length = i2 - i;
			if (length!=0)
			{
				tree->rchild = new Node();
				buildTree(i, i + length - 1, i + 1, i2, tree->rchild);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> in[i];
	}
	tree = new Node();
	buildTree(0, N - 1, 0, N - 1, tree);
	queue<Node*>level;
	level.push(tree);
	vector<int>output;
	while (!level.empty())
	{
		if (level.front()->data)
		{
			int number = level.front()->data;
			cout << number << endl;
			output.push_back(number);
		}

		if (level.front()->lchild!=NULL)
		{
			level.push(level.front()->lchild);
		}
		if (level.front()->rchild!=NULL)
		{
			level.push(level.front()->rchild);
		}
		level.pop();
	}
	//bool flag = false;
	//for (int i = 0; i < N; i++)
	//{
	//	if (!flag) {
	//		flag = true;
	//		cout << output[i];
	//	}
	//	else
	//	{
	//		cout << " " << output[i];
	//	}
	//}
	cout << endl;
	return 0;
}
