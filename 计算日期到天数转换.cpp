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
bool runnian(int year);
int main()
{
	int year;
	int month;
	int date;
	vector<int> num = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (scanf("%d", &year) != EOF)
	{
		scanf("%d", &month);
		scanf("%d", &date);
		if (runnian(year) == true)
		{
			num[1] = 29;
		}
		else
		{
			num[1] = 28;
		}
		int res = 0;
		for (int i = 0; i < month - 1; i++)
		{
			res = res + num[i];
		}
		res = res + date;
		printf("%d\n", res);
	}
	return 0;
}
bool runnian(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	if (year % 400 == 0)
	{
		return true;
	}
	return false;
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