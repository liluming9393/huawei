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
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
			{
				s[i] = (s[i] - 'a' + 1) % 26 + 'A';
			}
			else if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				s[i] = (s[i] - 'A' + 1) % 26 + 'a';
			}
			else if (s[i] >= '0'&&s[i] <= '9')
			{
				s[i] = (s[i] - '0' + 1) % 10 + '0';
			}
		}
		cout << s << endl;
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'B'&&s[i] <= 'Z')
			{
				s[i] = (s[i] - 'A' - 1) % 26 + 'a';
			}
			else if (s[i] == 'A')
			{
				s[i] = 'z';
			}
			else if (s[i] >= 'b'&&s[i] <= 'z')
			{
				s[i] = (s[i] - 'a' - 1) % 26 + 'A';
			}
			else if (s[i] == 'a')
			{
				s[i] = 'Z';
			}
			else if (s[i] >= '1'&&s[i] <= '9')
			{
				s[i] = (s[i] - '0' - 1) % 10 + '0';
			}
			else if (s[i] == '0')
			{
				s[i] = '9';
			}
		}
		cout << s << endl;
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