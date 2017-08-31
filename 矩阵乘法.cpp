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
	int x, y, z;
	while (scanf("%d", &x) != EOF)
	{
		scanf("%d", &y);
		scanf("%d", &z);
		vector<vector<int>> matrix1(x, vector<int>(y));
		vector<vector<int>> matrix2(y, vector<int>(z));
		vector<vector<int>> res(x, vector<int>(z));
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				scanf("%d", &matrix1[i][j]);
			}
		}
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < z; j++)
			{
				scanf("%d", &matrix2[i][j]);
			}
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < z; j++)
			{
				for (int k = 0; k < y; k++)
				{
					res[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
		Display_2D_Matrix(res);
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