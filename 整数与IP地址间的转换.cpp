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
bool check_ip(string ip_string, vector<int> &ip_vec);
int main()
{
	string s;
	long long int n;
	while (cin >> s)
	{
		vector<int> ip_vec(4);
		check_ip(s, ip_vec);
		n = ((unsigned int)ip_vec[0] << 24) + ((unsigned int)ip_vec[1] << 16) + ((unsigned int)ip_vec[2] << 8) + ((unsigned int)ip_vec[3]);
		cout << n << endl;
		cin >> n;
		cout << ((n & 0xff000000) >> 24) << "." << ((n & 0x00ff0000) >> 16) << "." << ((n & 0x0000ff00) >> 8) << "." << ((n & 0x000000ff)) << endl;
	}
	return 0;
}
bool check_ip(string ip_string, vector<int> &ip_vec)
{
	ip_string += '.';
	int start = 0;
	int end = 0;
	string temp;
	int count = 0;
	for (int i = 0; i < ip_string.size(); i++)
	{
		if (ip_string[i] != '.' && (ip_string[i]<'0' || ip_string[i]>'9'))
		{
			return false;
		}
		if (ip_string[i] == '.')
		{
			end = i;
			if (start == end)
			{
				return false;
			}
			temp = ip_string.substr(start, end - start);
			start = end + 1;
			ip_vec[count] = atoi(temp.c_str());
			if (ip_vec[count] < 0 || ip_vec[count]>255)
			{
				return false;
			}
			count++;
		}
	}
	if (count != 4)
	{
		return false;
	}
	return true;
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