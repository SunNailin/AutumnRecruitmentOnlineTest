// Sohu_KolakoskiSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

#define MAX_N 10000
#define MAX_M 1000

vector<int> KolakoskiSequence(vector<int> a, int length) {
	vector<int> res;
	int indexOfRes = 0;
	int indexOfA = 0;
	int count = 0;
	if (a[0] > 1) {
		for (int i = 0; i < a[0]; i++) {
			res.push_back(a[0]);
			count++;
		}
		indexOfA = 1;
		indexOfRes = 1;
	}
	else if (a[0] == 1) {	
		res.push_back(a[0]);
		count++;
		for (int i = 0; i < a[1];i++) {
			res.push_back(a[1]);
			count++;
		}
		indexOfA = 2;
		indexOfRes = 2;
	}

	while (count < length) {
		indexOfA %= a.size();
		int tempOfA = a[indexOfA++];
		for (int i = 0; i < res[indexOfRes]; i++) {
			res.push_back(tempOfA);
			count++;
		}
		indexOfRes++;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> a;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	vector<int> res = KolakoskiSequence(a, n);
	for (int i = 0; i < n; i++) {
		cout << res[i]<<endl;
	}
	return 0;
}

