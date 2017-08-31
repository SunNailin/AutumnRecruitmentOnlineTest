// Zhongxing_FindDefferentWays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

int countContinousOne(string str) {
	int max = 0;
	int temp = 0;
	for (int i = 0; i < str.size; i++) {
		if (str[i] == '1') {
			temp++;
			if (i = str.size() - 1 || str[i + 1] == '0') {
				if (temp > max)
					max = temp;
				temp = 0;
			}
		}
	}
	return max;
}

int findDifferentWays(int size, int allowChanges, string str) {
	set<string> strSet;	
	int max = 0;
	
	for (int i = 0; i < allowChanges; i++) {
		string tempStr;
		int tempMax = countContinousOne(tempStr);
		if (tempMax > max) {
			max = tempMax;
			tempMax = 0;
		}
	}

	if (countContinousOne(tempStr) == max)
		strSet.insert(tempStr);
	return strSet.size();
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	cin >> str;
	cout << str;
	return 0;
}

