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
Node *tree2;
void buildTree(int p1, int p2, int i1, int i2, Node* &treeNode) {
	if (treeNode==NULL)
	{
		treeNode = new Node();
	}
	if (p1>p2||i1>i2)
	{
		return;
	}
	//cout << "flag"<< endl;
	treeNode->lchild = NULL;
	treeNode->rchild = NULL;
	treeNode->data = post[p2];
	//cout <<post[p2] << endl;
	int count = p1;
	int i;
	for ( i =i1 ; i <=i2; i++, count++)
	{
		if (post[p2] == in[i]) { //V found
			break;
		}
		
	}
	buildTree(p1, count - 1, i1, i - 1, treeNode->lchild);
	buildTree(count, p2 - 1, i + 1, i2, treeNode->rchild);
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
//			cout << number << endl;
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
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (!flag) {
			flag = true;
			cout << output[i];
		}
		else
		{
			cout << " " << output[i];
		}
	}
	cout << endl;
	return 0;
}
