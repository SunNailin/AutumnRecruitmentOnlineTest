// Zhongxing_ScreatCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

// (((S^N % 10)^M % 1000000007
// 快速幂
int helper(int base, int exponent, int modulo)   {
	long long longBase = base, temp = 1;     
	while (exponent>0)       {
		if (exponent & 1)    
			temp = (temp % modulo) * (longBase % modulo) % modulo;
		longBase = (longBase % modulo) * (longBase % modulo) % modulo;
		exponent /= 2;
	}
	return (int)(temp % modulo);
}


int findSecretCode(int secretCode, int valueN, int valueM) {
	int res;
	res = helper(secretCode, valueN, 10);
	res = helper(res, valueM, 1000000007);
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int secretCode;
	int valueN;
	int valueM;
	cin >> secretCode;
	cin >> valueN;
	cin >> valueM;
	int res = findSecretCode(secretCode, valueN, valueM);
	cout << res;
	return 0;
}

