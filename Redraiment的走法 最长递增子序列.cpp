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
int increase(vector<int> data, vector<int> &dp);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> data(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &data[i]);
		}
		vector<int> dp(n);
		int res = increase(data, dp);
		printf("%d\n", res);
	}
	return 0;
}
int increase(vector<int> data, vector<int> &dp)
{
	dp[0] = 1;
	for (int i = 1; i < data.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (data[j] < data[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int res = dp[0];
	for (int i = 0; i < dp.size(); i++)
	{
		res = max(res, dp[i]);
	}
	return res;
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