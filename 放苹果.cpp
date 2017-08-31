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
void apple(int apple_left, int level, int n, int last_apple_num, int &res);
int main()
{
	int m;
	int n;
	while (scanf("%d", &m) != EOF)
	{
		scanf("%d", &n);
		int res = 0;
		apple(m, 0, n, 1, res);
		printf("%d\n", res);
	}
	return 0;
}
void apple(int apple_left, int level, int n, int last_apple_num, int &res)
{
	if (apple_left == 0)
	{
		res++;
		return;
	}
	else if (level == n)
	{
		return;
	}
	for (int i = last_apple_num; i <= apple_left; i++)
	{
		apple(apple_left - i, level + 1, n, i, res);
	}
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