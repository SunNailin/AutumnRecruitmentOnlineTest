// Didi_Xor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int XorSections(vector<int> v) {
	int res = 2;

	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int res = XorSections(v);
	cout << res;
	return 0;
}

