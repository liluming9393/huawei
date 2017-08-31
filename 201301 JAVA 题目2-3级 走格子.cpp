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
int dp1(int n, int m);
int dp2(int n, int m);
int main()
{
	int n;
	int m;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		int res = 0;
		//res = dp1(n, m);
		//printf("%d\n", res);
		res = dp2(n, m);
		printf("%d\n", res);
	}
	return 0;
}
int dp1(int n, int m)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 0; i < m + 1; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return dp[n][m];
}
int dp2(int n, int m)
{
	if (n < m)
	{
		swap(n, m);
	}
	vector<int> dp(m + 1);
	for (int i = 0; i < m + 1; i++)
	{
		dp[i] = 1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			dp[j] = dp[j - 1] + dp[j];
		}
	}
	return dp[m];
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