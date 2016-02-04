// 1036.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class People {
public:
	string name;
	string sex;
	string subject;
	int score;
};
bool cmp(People p1, People p2) {
	return p1.score < p2.score;
}


int main()
{
	int N;
	cin >> N;
	vector<People>male;
	vector<People>female;

    return 0;
}

