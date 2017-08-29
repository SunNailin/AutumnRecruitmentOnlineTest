// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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
�й���ʷ�������ֹ��������ݵ�ʱ�ڣ����֮��ͨ�����ַ�ʽ�ɳ��������̽���飬��������ྪ�Ķ��ǵĵ�ս���£�������һ���������ģ�
  A����B�������˶����������һ����Щ�����̽��B������Tʱ�乥��A�������A������������A���ذܣ����A������ǰ�����A����ʤ��
  ����A���ļ����Ҫ��T֮ǰ���鱨��ȫ���ͻ�A����Ϊ�˱����鱨��B���ػ��ȡ������ƻ���A���ļ��������һ������ı����㷨��
  �Ὣ�鱨������m�������У�ֻ��ͬʱ�õ����������n�������ܽ�����鱨����m�����ݻ���m������ֱ��ͳ�������ͬʱ��B������
  ���������鱨�Ĺ�����Ҫ���B���������飬�����鱨��ʱ���ǲ��̶��ģ�A������Ѿ���֮ǰ�鱨������ʱ�䶼��¼������
  A�������Ҫ�����A���õ������鱨ʱ�������ֵ��
ע��Ϊ�˼������m���������ɹ��İѸ��Ե��鱨�ͻ�A�������ķѵ�ʱ���Ƕ����ġ�
  �������A�������¼���鱨����ʱ�����������¼ÿ��ʱ���ܹ����ֵĴ�������Point�ṹ��ʾ��*/

struct Point
{
	int value; // �鱨����ʱ��
	int num; // value���ֹ��Ĵ�����
	double ratio; // value�������鱨����ռ�ĸ��ʡ�
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