// 1031.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
void outputSpace(int n) {
	for (int i = 0; i <n; i++)
	{
		cout << " ";
	}
}
int main()
{
	string input;
	cin >> input;
	int n1 = (input.length() + 2) / 3;
	int n2 = (input.length() - 2 * n1);
//	cout << n1 << " " << n2 << endl;
	for (int i = 0; i < n1-1; i++)
	{
		cout << input[i];
		outputSpace(n2);
		cout << input[input.length() - 1 - i] << endl;
	}
	string last = input.substr(n1-1, n2+2);
	cout << last << endl;
    return 0;
}

