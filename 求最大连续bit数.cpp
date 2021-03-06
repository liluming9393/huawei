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
		int temp;
		int res = 0;
		int count = 0;
		int flag = false;
		for (int i = 0; i < 8; i++)
		{
			temp = n % 2;
			if (temp == 1)
			{
				flag = true;
				count++;
			}
			else if (temp == 0 && flag == true)
			{
				flag = false;
				res = max(res, count);
				count = 0;
			}
			n = n / 2;
		}
		if (flag == true)
		{
			res = max(res, count);
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