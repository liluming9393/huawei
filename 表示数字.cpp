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
int main()
{
	string s;
	while (cin >> s)
	{
		string res;
		bool flag = false;
		if (s[0] >= '0' && s[0] <= '9')
		{
			res += '*';
		}
		res += s[0];
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9' && (s[i - 1]<'0' || s[i - 1]>'9'))
			{
				res += '*';
				res += s[i];
			}
			else if (s[i - 1] >= '0'&&s[i - 1] <= '9' && (s[i]<'0' || s[i]>'9'))
			{
				res += '*';
				res += s[i];
			}
			else
			{
				res += s[i];
			}
		}
		if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9')
		{
			res += '*';
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