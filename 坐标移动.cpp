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
		int x = 0;
		int y = 0;
		vector<string> data;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ';')
			{
				end = i;
				data.push_back(s.substr(start, end - start));
				start = end + 1;
			}
		}
		for (int i = 0; i < data.size(); i++)
		{
			string temp = data[i];
			if (temp[0] == 'A')
			{
				if (temp.size() == 2 && temp[1] >= '0' &&temp[1] <= '9')
				{
					x -= (temp[1] - '0');
				}
				else if (temp.size() == 3 && temp[1] >= '0' &&temp[1] <= '9'&& temp[2] >= '0' &&temp[2] <= '9')
				{
					x -= (temp[1] - '0') * 10 + (temp[2] - '0');
				}
			}
			else if (temp[0] == 'D')
			{
				if (temp.size() == 2 && temp[1] >= '0' &&temp[1] <= '9')
				{
					x += (temp[1] - '0');
				}
				else if (temp.size() == 3 && temp[1] >= '0' &&temp[1] <= '9'&& temp[2] >= '0' &&temp[2] <= '9')
				{
					x += (temp[1] - '0') * 10 + (temp[2] - '0');
				}
			}
			else if (temp[0] == 'S')
			{
				if (temp.size() == 2 && temp[1] >= '0' &&temp[1] <= '9')
				{
					y -= (temp[1] - '0');
				}
				else if (temp.size() == 3 && temp[1] >= '0' &&temp[1] <= '9'&& temp[2] >= '0' &&temp[2] <= '9')
				{
					y -= (temp[1] - '0') * 10 + (temp[2] - '0');
				}
			}
			else if (temp[0] == 'W')
			{
				if (temp.size() == 2 && temp[1] >= '0' &&temp[1] <= '9')
				{
					y += (temp[1] - '0');
				}
				else if (temp.size() == 3 && temp[1] >= '0' &&temp[1] <= '9'&& temp[2] >= '0' &&temp[2] <= '9')
				{
					y += (temp[1] - '0') * 10 + (temp[2] - '0');
				}
			}
		}
		cout << x << "," << y << endl;
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