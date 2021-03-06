// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
中国历史上曾出现过多次诸侯割据的时期，诸侯之间通过各种方式派出间谍来刺探军情，留下了许多惊心动魄的谍战故事，其中有一个是这样的：
  A国在B国安插了多名间谍，有一次这些间谍刺探到B国将在T时间攻打A国，如果A国不做防备则A国必败；如果A国能提前埋伏则A国必胜，
  所以A国的间谍需要在T之前将情报安全的送回A国。为了避免情报被B国截获而取消攻打计划：A国的间谍采用了一种特殊的编码算法，
  会将情报编码在m份数据中，只有同时拿到至少任意的n份数才能解码出情报；这m份数据会由m个间谍分别送出，避免同时被B国捕获。
  由于输送情报的过程中要躲避B国的随机检查，输送情报的时间是不固定的，A国间谍已经将之前情报的输送时间都记录下来。
  A国间谍需要估算出A国拿到完整情报时间的期望值。
注：为了简单起见，m个间谍都会成功的把各自的情报送回A国；所耗费的时间是独立的。
  概念抽象：A国间谍记录的情报输送时间的情况：会记录每个时间总共出现的次数，以Point结构表示：*/

struct Point
{
	int value; // 情报输送时间
	int num; // value出现过的次数。
	double ratio; // value在所有情报输送占的概率。
};

void input(vector<Point>* points);

double calculateExpectation(const vector<Point>& points, const int total, const int min);
int main()
{
	int total = 0;
	cin >> total;
	int min = 0;
	cin >> min;

	vector<Point> points;
	input(&points);

	double res = calculateExpectation(points, total, min);
	cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;
	return 0;
}

void input(vector<Point>* points)
{
	int n = 0;
	cin >> n;
	points->resize(n);

	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		Point& point = (*points)[i];
		cin >> point.value;
		cin >> point.num;
		sum += point.num;
	}

	for (int i = 0; i < n; ++i)
	{
		Point& point = (*points)[i];
		point.ratio = point.num / sum;
	}
}

double calculateExpectation(const vector<Point>& points, const int total, const int min)
{
	double ratio = 0.0;
	int totalNum = 0;
	int totalTime = 0;
	double expectation = 1.0;
	vector<Point> tempPoints = points;
	for (int i = 0; i < tempPoints.size(); i++) {
		totalNum += tempPoints[i].num;
		totalTime += tempPoints[i].num * tempPoints[i].value;
	}
	for (int i = 0; i < tempPoints.size(); i++) {
		tempPoints[i].ratio = (double)tempPoints[i].num / (double)totalNum;
	}
	expectation = (double)totalNum / (double)totalNum;
	return expectation;
}