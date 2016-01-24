// 1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
string model[54]= { "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
"J1", "J2" };
int input[54];
string temp[54];
string output[54];
void copy(string* s1, string* s2) {
	for (int i = 0; i <54; i++)
	{
		s1[i] = s2[i];
	}
}
bool flag = false;
void shift() {
	if (!flag) {
		flag = true;
		copy(temp, model);
		for (int i = 0; i <54; i++)
		{
			int shift = input[i] - 1;
			output[shift] = temp[i];
		}
	}
	else
	{
		copy(temp, output);
		for (int i = 0; i <54; i++)
		{
			int shift = input[i] - 1;
			output[shift] = temp[i];
		}
	}

}
void outputNum() {
	for (int i = 0; i < 53; i++) {
		cout << output[i] << " ";
	}
	cout << output[53] << endl;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 54; i++)
	{
		cin >> input[i];
	}
	for (int i = 0; i < N; i++)
	{
		shift();
	}
	outputNum();
    return 0;
}

