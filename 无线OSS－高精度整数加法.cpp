#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<stdio.h>
#include<iostream>
#include<functional>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
string add_positive(string s1, string s2);
int main()
{
	string s1;
	string s2;
	while (cin >> s1)
	{
		cin >> s2;
		string res;
		int carry = 0;
		int num;
		if (s1.size() < s2.size())
		{
			swap(s1, s2);
		}
		for (int i = 0; i < s2.size(); i++)
		{
			num = s1[s1.size() - 1 - i] - '0' + s2[s2.size() - 1 - i] - '0' + carry;
			if (num >= 10)
			{
				num = num - 10;
				carry = 1;
			}
			char temp = num + '0';
			res = temp + res;
		}
		for (int i = s2.size(); i < s1.size(); i++)
		{
			num = s1[s1.size() - 1 - i] - '0' + carry;
			if (num >= 10)
			{
				num = num - 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			char temp = num + '0';
			res = temp + res;
		}
		if (carry == 1)
		{
			res = '1' + res;
		}
		cout << res << endl;
	}
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size() - 1; i++)
	{
		printf("%d ", data[i]);
	}
	printf("%d\n", data[data.size() - 1]);
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			printf("%d ", data[i][j]);
		}
		printf("%d\n", data[i][data[i].size() - 1]);
	}
}