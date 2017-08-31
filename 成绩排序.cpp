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
struct score
{
	string name;
	int num;
	int time;
};
bool cmp0(const struct score &s1, const struct score &s2)
{
	if (s1.num < s2.num)
	{
		return true;
	}
	if (s1.num == s2.num)
	{
		if (s1.time < s2.time)
		{
			return true;
		}
	}
	return false;
}
bool cmp1(const struct score &s1, const struct score &s2)
{
	if (s1.num > s2.num)
	{
		return true;
	}
	if (s1.num == s2.num)
	{
		if (s1.time < s2.time)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n;
	int flag;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &flag);
		vector<score> data(n);
		for (int i = 0; i < n; i++)
		{
			cin >> data[i].name;
			cin >> data[i].num;
			data[i].time = i;
		}
		if (flag == 0)
		{
			sort(data.begin(), data.end(), cmp1);
		}
		else
		{
			sort(data.begin(), data.end(), cmp0);
		}
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i].name << " " << data[i].num << endl;
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