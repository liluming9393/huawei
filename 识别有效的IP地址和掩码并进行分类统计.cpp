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
bool check_ip(string ip_string, vector<int> &ip_vec);//校验ip合法性
bool check_mask(string mask_string, vector<int> &mask_vec);//校验掩码合法性
bool ip_type(vector<int> net, vector<int> start, vector<int> end);
int main()
{
	string s;
	string ip_string;
	string mask_string;
	vector<int> ip_vec(4);
	vector<int> mask_vec(4);
	vector<int> net_vec(4);
	vector<int> count(7);//A、B、C、D、E、error、private
	vector<int> A_start = { 1, 0, 0, 0 };
	vector<int> A_end = { 126, 255, 255, 255 };
	vector<int> B_start = { 128, 0, 0, 0 };
	vector<int> B_end = { 191, 255, 255, 255 };
	vector<int> C_start = { 192, 0, 0, 0 };
	vector<int> C_end = { 223, 255, 255, 255 };
	vector<int> D_start = { 224, 0, 0, 0 };
	vector<int> D_end = { 239, 255, 255, 255 };
	vector<int> E_start = { 240, 0, 0, 0 };
	vector<int> E_end = { 255, 255, 255, 255 };
	vector<int> A_private_start = { 10, 0, 0, 0 };
	vector<int> A_private_end = { 10, 255, 255, 255 };
	vector<int> B_private_start = { 172, 16, 0, 0 };
	vector<int> B_private_end = { 172, 31, 255, 255 };
	vector<int> C_private_start = { 192, 168, 0, 0 };
	vector<int> C_private_end = { 192, 168, 255, 255 };
	while (getline(cin, s))
	{
		int pos = s.find('~');
		ip_string = s.substr(0, pos);
		mask_string = s.substr(pos + 1, s.size() - pos - 1);
		if (check_ip(ip_string, ip_vec) == false || check_mask(mask_string, mask_vec) == false)
		{
			count[5]++;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				net_vec[i] = ip_vec[i] & mask_vec[i];
			}
			if (ip_type(net_vec, A_start, A_end))
			{
				count[0]++;
				if (ip_type(net_vec, A_private_start, A_private_end))
				{
					count[6]++;
				}
			}
			else if (ip_type(net_vec, B_start, B_end))
			{
				count[1]++;
				if (ip_type(net_vec, B_private_start, B_private_end))
				{
					count[6]++;
				}
			}
			else if (ip_type(net_vec, C_start, C_end))
			{
				count[2]++;
				if (ip_type(net_vec, C_private_start, C_private_end))
				{
					count[6]++;
				}
			}
			else if (ip_type(net_vec, D_start, D_end))
			{
				count[3]++;
			}
			else if (ip_type(net_vec, E_start, E_end))
			{
				count[4]++;
			}
		}
	}
	Display_1D_Matrix(count);
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
bool ip_type(vector<int> net, vector<int> start, vector<int> end)
{
	for (int i = 0; i < 4; i++)
	{
		if (net[i] < start[i] || net[i] > end[i])
		{
			return false;
		}
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