// B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int StrPlus(const string &num1, const string &num2, string &ret)
{
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int jw = 0;
	string temp;
	while (i >= 0 && j >= 0)
	{
		int a = num1[i--] - '0';
		int b = num2[j--] - '0';
		int num = a + b + jw;
		temp += num % 10 + '0';
		jw = (num - num % 10) / 10;
	}
	while (i >= 0)
	{
		int a = num1[i--] - '0';
		int num = a + jw;
		temp += num % 10 + '0';
		jw = (num - num % 10) / 10;
	}
	while (j >= 0)
	{
		int b = num2[j--] - '0';
		int num = b + jw;
		temp += num % 10 + '0';
		jw = (num - num % 10) / 10;
	}
	if (jw != 0)
	{
		temp += jw + '0';
	}
	for (int k = temp.size() - 1; k >= 0; --k)
	{
		ret += temp[k];
	}
	return 0;
}

int main()
{
	int N = 0;
	while (cin >> N)
	{
		string dp[201][2];
		dp[0][0] = "1";
		dp[0][1] = "0";
		for (int i = 1; i <= N; ++i)
		{
			StrPlus(dp[i - 1][0], dp[i - 1][1], dp[i][0]);
			dp[i][1] = dp[i - 1][0];
		}
		cout << dp[N][0] << endl;
	}
    return 0;
}
