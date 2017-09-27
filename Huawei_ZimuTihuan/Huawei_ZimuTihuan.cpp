// Huawei_ZimuTihuan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

void ZimuTihuan(string &outStr1, string &outStr2) {
	set<char> set1;
	set<char> commonSet;
	for (int i = 0; i < outStr1.length(); i++) {
		set1.insert(outStr1[i]);
	}
	for (int i = 0; i < outStr2.length(); i++) {
		if (set1.count(outStr2[i])) {
			commonSet.insert(outStr2[i]);
			outStr2[i] = '_';
		}
	}
	for (int i = 0; i < outStr1.length(); i++) {
		if (commonSet.count(outStr1[i]))
			outStr1[i] = '_';
	}
}

int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	ZimuTihuan(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
}

