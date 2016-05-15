// D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool my_greater0(const char &a, const char &b) { return a < b; }

int main()
{
	int N = 0;
	int result[100000] = { 0 };
	map<string, int> mapStr;
	FILE *file = freopen("1.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;
		sort(input.begin(), input.end(), my_greater0);

		map<string, int>::iterator iter;
		iter = mapStr.find(input);
		if (iter != mapStr.end())
		{
			result[i] = iter->second;
			iter->second++;
		}
		else
		{
			mapStr.insert(pair<string, int>(input, 1));
			result[i] = 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << endl;
	}

	return 0;
}
