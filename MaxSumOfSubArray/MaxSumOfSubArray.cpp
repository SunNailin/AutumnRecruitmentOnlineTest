// MaxSumOfSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int MaxSumOfSubArray(vector<int> data) {
	if (data.empty())
		return 0;
	int tempSum = data[0];
	int maxSum = data[0];
	for (int i = 1; i < data.size(); i++) {
		if (tempSum < 0) tempSum = data[i];
		else tempSum += data[i];
		if (maxSum < tempSum) maxSum = tempSum;
	}
	return maxSum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> data;
	int temp;
	char c;
	while ((c = getchar()) != '\n') {
		if (c!=' ') {
			ungetc(c, stdin);
			cin >> temp;
			data.push_back(temp);
		}
	}
	int res = MaxSumOfSubArray(data);
	cout << res;
	return 0;
}

