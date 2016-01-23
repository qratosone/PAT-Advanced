// 1083.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
class student {
public:
	string name;
	string ID;
	int grade;
	void output() {
		printf("%s %s\n", name.c_str(), ID.c_str());
	}
	//bool operator < (const student& p) const {
	//	return grade > p.grade;
	//}
};
vector<student> input;
bool cmp(student s1, student s2) {
	return s1.ID > s2.ID;
}
int main()
{
	int N;
	cin >> N;
	student temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp.name >> temp.ID >> temp.grade;
		input.push_back(temp);
	}
	sort(input.begin(), input.end(),cmp);
	int g1, g2;
	cin >> g1 >> g2;
	bool flag = false;
		for (int i = 0; i <N; i++)
		{
			if (input[i].grade < g1||input[i].grade > g2) {
				continue;
			}
			input[i].output();
			flag = true;
		}
		if (!flag) {
			cout << "NONE" << endl;
		}
    return 0;
}

