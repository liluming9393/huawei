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
	int n;
	while (cin >> s)
	{
		cin >> n;
		string res = s.substr(0, n);
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'C' || s[i] == 'G')
			{
				count++;
			}
		}
		int max = count;
		for (int i = 0; i < s.size() - n; i++)
		{
			if (s[i] == 'C' || s[i] == 'G')
			{
				count--;
			}
			if (s[i + n] == 'C' || s[i + n] == 'G')
			{
				count++;
			}
			if (count > max)
			{
				max = count;
				res = s.substr(i + 1, n);
			}
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