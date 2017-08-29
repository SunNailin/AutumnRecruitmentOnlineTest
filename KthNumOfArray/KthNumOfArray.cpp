// KthNumOfArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int IntCompare(int a, int b) {
	return a > b;
}

int KthNumOfArray(vector<int> &data, int k) {
	int res;
	if (data.empty()) return 0;
	sort(data.begin(), data.end(), IntCompare);
	res = data[k - 1];
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> data;
	int temp;
	char c;
	while ((c = getchar()) != '\n') {
		if (c != ' ') {
			ungetc(c, stdin);
			cin >> temp;
			data.push_back(temp);
		}
	}
	int k;
	cin >> k;
	int res = KthNumOfArray(data, k);
	cout << res;
	return 0;
}

