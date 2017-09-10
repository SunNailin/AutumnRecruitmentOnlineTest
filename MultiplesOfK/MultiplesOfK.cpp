// MultiplesOfK.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool hasMutiplesOfK(vector<int> data, int length, int K) {
	for (int i = 0; i < data.size() - length + 1; i++) {
		int tempSum = 0;
		for (int j = i; j < length + i; j++) {
			tempSum += data[j];
		}
		if (tempSum % K == 0) return true;
	}
	return false;
}

int MutiplesOfK(vector<int> data, int K) {
	for (int i = data.size(); i > 0; i--) {
		if (hasMutiplesOfK(data, i, K)) return i;
	}
	return 0;
}
// 100%AC
int main(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	vector<int> data;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		data.push_back(temp);
	}
	int k;
	cin >> k;
	int res = MutiplesOfK(data,k);
	cout << res;
	return 0;
}

