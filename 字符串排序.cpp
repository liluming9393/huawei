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
struct ss
{
	char c;
	int time;
};
bool cmp(const struct ss &c1, const struct ss &c2)
{
	char temp1 = c1.c;
	char temp2 = c2.c;
	if (((temp1 >= 'a' && temp1 <= 'z') || (temp1 >= 'A' && temp1 <= 'Z')) && ((temp2 >= 'a' && temp2 <= 'z') || (temp2 >= 'A' && temp2 <= 'Z')))
	{
		if (temp1 >= 'A' && temp1 <= 'Z')
		{
			temp1 = temp1 - 'A' + 'a';
		}
		if (temp2 >= 'A' && temp2 <= 'Z')
		{
			temp2 = temp2 - 'A' + 'a';
		}
		if (temp1 < temp2)
		{
			return true;
		}
		if (temp1 == temp2)
		{
			if (c1.time < c2.time)
			{
				return true;
			}
		}
	}
	else
	{
		if (c1.time < c2.time)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	string s;
	while (getline(cin,s))
	{
		vector<struct ss> data;
		for (int i = 0; i < s.size(); i++)
		{
			char temp1 = s[i];
			if ((temp1 >= 'a' && temp1 <= 'z') || (temp1 >= 'A' && temp1 <= 'Z'))
			{
				ss temp;
				temp.c = s[i];
				temp.time = i;
				data.push_back(temp);
			}
		}
		sort(data.begin(), data.end(), cmp);
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char temp1 = s[i];
			if ((temp1 >= 'a' && temp1 <= 'z') || (temp1 >= 'A' && temp1 <= 'Z'))
			{
				cout << data[j].c;
				j++;
			}
			else
			{
				cout << s[i];
			}
		}
		cout << endl;
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