// 1058.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include  <iostream>   
#include <cstdio>
//是赋值以逗号为分隔符  
using   namespace   std;

int   main()
{
	int   a1, a2, a3, b1, b2, b3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	int g=0, s=0, k=0;
	k += (a3 + b3);
	if (k >= 29) {
		s++;
		k = k % 29;
	}
	s +=( a2 + b2);
	if (s >= 17) {
		g ++;
		s = s % 17;
	}
	
	g += (a1 + b1);
	cout << g << "." << s << "." << k << endl;
	return   0;
}
