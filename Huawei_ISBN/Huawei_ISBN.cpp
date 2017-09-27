// Huawei_ISBN.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string ISBN(string inStr) {
	// ����Ƿ�Ϸ�
	if (inStr.length() != 11) {
		return "ERROR";
	}
	for (int i = 0; i < inStr.length(); i++) {
		if (i == 1 || i == 5) {
			if (inStr[i] != '-')
				return "ERROR";
		}
		else {
			if (inStr[i] > '9' || inStr[i] < '0')
				return "ERROR";
		}
	}
	int sum = 0;
	int count = 1;
	for (int i = 0; i < inStr.length(); i++) {
		if (inStr[i] != '-') {
			sum += count * (inStr[i] - '0');
			count++;
		}
	}
	int mod = sum % 11;
	char modC = ' ';
	if (mod < 10) {
		modC = mod + '0';
	}
	else {
		modC = 'X';
	}
	string res = inStr + "-";
	res.insert(res.end(), 1, modC);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string inStr;
	cin >> inStr;
	string res = ISBN(inStr);
	cout << res;
	return 0;
}

