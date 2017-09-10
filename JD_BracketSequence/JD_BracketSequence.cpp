// JD_BracketSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsValid(string s) {
	stack<char> stack;
	for (char &c : s) {
		switch (c) {
			case '(': stack.push(c); break;
			case ')': 
				if (stack.empty())
					return false; 
				else 
					stack.pop();
				break;
		}
	}
	return stack.empty();
}

int MethodNumber(string s) {
	vector<int> count;
	stack<char> stack;
	int res = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			int countTemp = 0;
			for (int j = i; j < s.size(); j++) {
				if (s[j] == ')') {
					s.erase(i);
					s.erase(j);
				}
				if (IsValid(s))
					countTemp++;
			}
			count.push_back(countTemp);
		}
	}
	for (int i = 0; i < count.size(); i++) {
		if (count[i] != 0)
			res *= count[i];
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	cin >> str;
	cout << str;
	cout << MethodNumber(str);
	return 0;
}

