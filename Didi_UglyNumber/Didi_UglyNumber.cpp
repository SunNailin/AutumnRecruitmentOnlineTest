// Didi_UglyNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int UglyNumber(int N) {
	vector<int> UglyVec;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	UglyVec.push_back(1);
	while (UglyVec.size() < N) {
		int next2 = UglyVec[index2] * 2;
		int next3 = UglyVec[index3] * 3;
		int next5 = UglyVec[index5] * 5;
		int next = min(next5, min(next3, next2));
		if (next == next5) index5++;
		if (next == next3) index3++;
		if (next == next2) index2++;
		UglyVec.push_back(next);
	}
	int res;
	res = UglyVec.back();
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cin >> N;
	int res = UglyNumber(N);
	cout << res;
	return 0;
}

