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
		bool flag_kongge = false;
		bool flag_yinhao = false;
		vector<string> data;
		s = s + " ";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '\"' && flag_yinhao == false)
			{
				flag_yinhao = true;
				start = i + 1;
			}
			else if (s[i] == '\"' && flag_yinhao == true)
			{
				end = i;
				flag_yinhao = false;
				flag_kongge = false;
				data.push_back(s.substr(start, end - start));
			}
			else if (s[i] == ' ' && flag_yinhao == false && flag_kongge == true)
			{
				end = i;
				flag_kongge = false;
				data.push_back(s.substr(start, end - start));
			}
			else if (flag_kongge == false)
			{
				flag_kongge = true;
				start = i;
			}
		}
		cout << data.size() << endl;
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i] << endl;
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