// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int result[1000] = { 0 };
	FILE *file = freopen("1.txt", "r", stdin);
	int N = 0;
	while (cin >> N)
	{
		string LongStr;
		cin >> LongStr;
		for (int i = 0; i < N; ++i)
		{
			result[i] = 1;
			int a = 0, b = 0;
			cin >> a >> b;
			for (int j = a - 1; j < b; ++j)
			{
				result[i] = (result[i] * (LongStr[j] - 28)) % 9973;
			}
		}
		for (int i = 0; i < N; ++i)
		{
			cout << result[i] << endl;
		}
	}
    return 0;
}
