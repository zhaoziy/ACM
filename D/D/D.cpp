// D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct countStr
{
	int ID;
	int letter[26];
}word[100000];

int result[100000] = { 0 };

bool my_greater0(const countStr &a, const countStr &b){	return a.letter[0] > b.letter[0];}
bool my_greater1(const countStr &a, const countStr &b) { return a.letter[1] > b.letter[1]; }
bool my_greater2(const countStr &a, const countStr &b) { return a.letter[2] > b.letter[2]; }
bool my_greater3(const countStr &a, const countStr &b) { return a.letter[3] > b.letter[3]; }
bool my_greater4(const countStr &a, const countStr &b) { return a.letter[4] > b.letter[4]; }
bool my_greater5(const countStr &a, const countStr &b) { return a.letter[5] > b.letter[5]; }
bool my_greater6(const countStr &a, const countStr &b) { return a.letter[6] > b.letter[6]; }
bool my_greater7(const countStr &a, const countStr &b) { return a.letter[7] > b.letter[7]; }
bool my_greater8(const countStr &a, const countStr &b) { return a.letter[8] > b.letter[8]; }
bool my_greater9(const countStr &a, const countStr &b) { return a.letter[9] > b.letter[9]; }
bool my_greater10(const countStr &a, const countStr &b) { return a.letter[10] > b.letter[10]; }
bool my_greater11(const countStr &a, const countStr &b) { return a.letter[11] > b.letter[11]; }
bool my_greater12(const countStr &a, const countStr &b) { return a.letter[12] > b.letter[12]; }
bool my_greater13(const countStr &a, const countStr &b) { return a.letter[13] > b.letter[13]; }
bool my_greater14(const countStr &a, const countStr &b) { return a.letter[14] > b.letter[14]; }
bool my_greater15(const countStr &a, const countStr &b) { return a.letter[15] > b.letter[15]; }
bool my_greater16(const countStr &a, const countStr &b) { return a.letter[16] > b.letter[16]; }
bool my_greater17(const countStr &a, const countStr &b) { return a.letter[17] > b.letter[17]; }
bool my_greater18(const countStr &a, const countStr &b) { return a.letter[18] > b.letter[18]; }
bool my_greater19(const countStr &a, const countStr &b) { return a.letter[19] > b.letter[19]; }
bool my_greater20(const countStr &a, const countStr &b) { return a.letter[20] > b.letter[20]; }
bool my_greater21(const countStr &a, const countStr &b) { return a.letter[21] > b.letter[21]; }
bool my_greater22(const countStr &a, const countStr &b) { return a.letter[22] > b.letter[22]; }
bool my_greater23(const countStr &a, const countStr &b) { return a.letter[23] > b.letter[23]; }
bool my_greater24(const countStr &a, const countStr &b) { return a.letter[24] > b.letter[24]; }
bool my_greater25(const countStr &a, const countStr &b) { return a.letter[25] > b.letter[25]; }

bool(*myfun[26])(const countStr &a, const countStr &b) = { my_greater0 ,my_greater1 ,my_greater2 ,my_greater3 ,my_greater4, 
my_greater5 ,my_greater6 ,my_greater7 ,my_greater8 ,my_greater9 ,my_greater10 ,my_greater11 ,my_greater12 ,my_greater13,
my_greater14, my_greater15 ,my_greater16 ,my_greater17 ,my_greater18 ,my_greater19 ,my_greater20 ,my_greater21 ,my_greater22,
my_greater23,my_greater24, my_greater25 };

int main()
{
	int N = 0;

	FILE *file = freopen("1.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;
		word[i].ID = i;
		for (int j = 0; j < input.size(); ++j)
		{
			word[i].letter[input[j] - 'A']++;
		}
	}

	stable_sort(word, word + N, myfun[0]);
	for (int j = 1; j < 26; ++j)
	{
		int begin = 0;
		int end = -1;
		while (begin < N)
		{
			for (int i = begin; i < N - 1; ++i)
			{
				if (word[i].letter[j - 1] != word[begin].letter[j - 1])
					end = i - 1;
			}
			if (begin > end)
			{
				stable_sort(word + begin, word + N, myfun[j]);
				begin = N;
			}
			else
			{
				stable_sort(word + begin, word + end, myfun[j]);
				begin = end + 1;
			}
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		int record = -1;
		for (int k = 0; k < i; ++k)
		{
			bool flag = true;
			for (int m = 0; m < 26; ++m)
			{
				if (word[i].letter[m] != word[k].letter[m])
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
				record = k;
		}
		if (record != -1)
			result[i] = result[record] + 1;
	}
	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << endl;
	}

	return 0;
}
