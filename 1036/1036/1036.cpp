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
	People input;
	for (int i = 0; i < N; i++)
	{
		cin >> input.name >> input.sex >> input.subject >> input.score;
		if (input.sex=="M")
		{
			male.push_back(input);
		}
		else
		{
			female.push_back(input);
		}
	}
	sort(male.begin(), male.end(), cmp);
	sort(female.begin(), female.end(), cmp);
	if (!female.empty())
	{
		vector<People>::iterator iter = female.end() - 1;
		cout << iter->name<< " " << iter->subject << endl;
	}
	else
	{
		cout << "Absent" << endl;
	}
	if (!male.empty())
	{
		vector<People>::iterator iter = male.begin();
		cout << iter->name << " " << iter->subject << endl;
	}
	else
	{
		cout << "Absent" << endl;
	}
	if (male.size()!=0&&female.size()!=0)
	{
		int delta = (female.end()-1)->score - male.begin()->score;
		cout << delta << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
    return 0;
}

