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
		if (s.size() <= 8)
		{
			cout << "NG" << endl;
			continue;
		}
		vector<int> type(4);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				type[0] = 1;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				type[1] = 1;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				type[2] = 1;
			}
			else
			{
				type[3] = 1;
			}
		}
		if (type[0] + type[1] + type[2] + type[3] <= 2)
		{
			cout << "NG" << endl;
			continue;
		}
		bool flag = true;
		for (int i = 3; i < s.size(); i++)
		{
			for (int j = 0; j < s.size() - i + 1; j++)
			{
				string substr = s.substr(j, i);
				string checkstr = s.substr(j + 1, s.size() - j - 1);
				int res = checkstr.find(substr);
				if (res != string::npos)
				{
					flag = false;
					j = s.size();
					i = s.size();
				}
			}
		}
		if (flag == true)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "NG" << endl;
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