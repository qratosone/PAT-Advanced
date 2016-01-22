// 1027.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string model = "0123456789ABC";
void convert(int n) {
	int a = n / 13;
	int b = n % 13;
	cout << model[a] << model[b];
}
int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << '#';
	convert(r);
	convert(g);
	convert(b);
    return 0;
}

