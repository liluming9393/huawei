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
	while (getline(cin,s))
	{
		int start = 0;
		int end = 0;
		bool flag = false;
		vector<string> data;
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
			{
				if (flag == false)
				{
					start = i;
					flag = true;
				}
			}
			else
			{
				if (flag == true)
				{
					end = i;
					flag = false;
					data.push_back(s.substr(start, end - start));
				}
			}
		}
		if (flag == true)
		{
			data.push_back(s.substr(start, s.size() - start));
		}
		for (int i = data.size() - 1; i > 0; i--)
		{
			cout << data[i] << " ";
		}
		cout << data[0] << endl;
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