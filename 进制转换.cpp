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
	while (cin>>s)
	{
		int res = 0;
		int temp = 1;
		for (int i = s.size() - 1; i >= 2; i--)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				res += (s[i] - 'A' + 10)*temp;
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				res += (s[i] - 'a' + 10)*temp;
			}
			else
			{
				res += (s[i] - '0')*temp;
			}
			temp *= 16;
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