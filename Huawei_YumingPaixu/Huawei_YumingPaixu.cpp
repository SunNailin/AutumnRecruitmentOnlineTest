// Huawei_YumingPaixu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <hash_map>
#include <map>
#include <hash_set>
#include <stack>

using namespace std;

bool cmp(const string &x, const string &y)  
{
	return x<y;
}
//字符串排序
void strSort(vector<string> &strVec) {
	sort(strVec.begin(), strVec.end(), cmp);
}

vector<string> split(const string &str, const string &sep){
	vector<string> res;
    int i = 0;
	while (i != str.size()){
		int flag = 0;
		while (i != str.size() && flag == 0){
			flag = 1;
			for (int x = 0; x < sep.size(); ++x)
			if (str[i] == sep[x]){
				++i;
				flag = 0;
				break;
			}
		}
		flag = 0;
		int j = i;
		while (j != str.size() && flag == 0){
			for (int x = 0; x < sep.size(); ++x)
			if (str[j] == sep[x]){
				flag = 1;
				break;
			}
			if (flag == 0)
				++j;
		}
		if (i != j){
			res.push_back(str.substr(i, j - i));
			i = j;
			i = j;
		}
	}
	return res;
}

vector<string> YumingPaixu(string input) {
	vector<string> ymVec = split(input, "|");
	vector<vector<string> > strVec;
	for (int i = 0; i < ymVec.size(); i++) {
		vector<string> temp = split(ymVec[i], ".");
		strVec.push_back(temp);
	}

	strSort(strVec.back());
	vector<string> res;
	return ymVec;
}

int main()
{
	string hosts;
	cin >> hosts;
	vector<string> res = YumingPaixu(hosts);
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << "|";
	}
	cout << res[res.size() - 1];
	return 0;
}

