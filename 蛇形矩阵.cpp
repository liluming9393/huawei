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
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<vector<int>> data(n, vector<int>(n));
		int num = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				data[i - j][j] = num;
				num++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				printf("%d ", data[i][j]);
			}
			printf("%d\n", data[i][n - i - 1]);
		}
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