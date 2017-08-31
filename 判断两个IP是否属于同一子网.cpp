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
bool check_mask(string mask_string, vector<int> &mask_vec);
int main()
{
	string mask;
	string ip1;
	string ip2;
	vector<int> mask_vec(4);
	vector<int> ip1_vec(4);
	vector<int> ip2_vec(4);
	while (cin >> mask)
	{
		cin >> ip1;
		cin >> ip2;
		if (check_mask(mask, mask_vec) == false)
		{
			printf("1\n");
			continue;
		}
		if (check_ip(ip1, ip1_vec) == false)
		{
			printf("1\n");
			continue;
		}
		if (check_ip(ip2, ip2_vec) == false)
		{
			printf("1\n");
			continue;
		}
		bool flag = true;
		for (int i = 0; i < 4; i++)
		{
			ip1_vec[i] = ip1_vec[i] & mask_vec[i];
			ip2_vec[i] = ip2_vec[i] & mask_vec[i];
			if (ip1_vec[i] != ip2_vec[i])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			printf("0\n");
		}
		else
		{
			printf("2\n");
		}
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
bool check_mask(string mask_string, vector<int> &mask_vec)
{
	mask_string += '.';
	int start = 0;
	int end = 0;
	string temp;
	int count = 0;
	for (int i = 0; i < mask_string.size(); i++)
	{
		if (mask_string[i] != '.' && (mask_string[i]<'0' || mask_string[i]>'9'))
		{
			return false;
		}
		if (mask_string[i] == '.')
		{
			end = i;
			if (start == end)
			{
				return false;
			}
			temp = mask_string.substr(start, end - start);
			start = end + 1;
			mask_vec[count] = atoi(temp.c_str());
			if (mask_vec[count] < 0 || mask_vec[count]>255)
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
	unsigned int mask_int = ((unsigned int)mask_vec[0] << 24) + ((unsigned int)mask_vec[1] << 16) + ((unsigned int)mask_vec[2] << 8) + ((unsigned int)mask_vec[3]);
	if (mask_int == 0xffffffff)
	{
		return false;
	}
	if ((mask_int | (mask_int - 1)) != 0xffffffff)
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