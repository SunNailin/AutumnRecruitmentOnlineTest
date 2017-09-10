// MultiplesOfK.cpp : 定义控制台应用程序的入口点。
//
/*K 的倍数

题目描述：
序列中任意个连续的元素组成的子序列称为该序列的子串。
现在给你一个序列P和一个整数K，询问元素和是K的倍数的子串的最大长度。
比如序列【1,2,3,4,5】，给定的整数K为 5，其中满足条件的子串为{5}、{2,3}、{1,2,3,4}、{1,2,3,4,5}，
那么答案就为 5，因为最长的子串为{1,2,3,4,5}；如果满足条件的子串不存在，就输出 0。
输入
第一含一个整数N, 1 ≤ 𝑁 ≤ 105 。
第二行包含 N 个整数𝑝𝑖 ，𝑝𝑖 表示序列P第i个元素的值。0 ≤ 𝑝𝑖 ≤ 105 。
第三行包含一个整数 K， 1 ≤ 𝐾 ≤ 105  。
输出
输出一个整数ANS，表示答案。

样例输入
Input Sample 1
5
1 2 3 4 5
5
Input Sample 2
6
3 1 2 7 7 7
4
样例输出
Output Sample 1
5
Output Sample 2
5*/

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
		if (tempSum % K == 0 && tempSum >= K) return true;
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
	int res = MutiplesOfK(data, k);
	cout << res;
	return 0;
}

