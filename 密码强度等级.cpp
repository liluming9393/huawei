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
		int count_small_letter = 0;
		int count_big_letter = 0;
		int count_num = 0;
		int count_character = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				count_small_letter++;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				count_big_letter++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				count_num++;
			}
			else
			{
				count_character++;
			}
		}
		int score = 0;
		if (s.size() <= 4)
		{
			score += 5;
		}
		else if (s.size() >= 5 && s.size() <= 7)
		{
			score += 10;
		}
		else if (s.size() >= 0)
		{
			score += 25;
		}
		if (count_small_letter == 0 && count_big_letter == 0)
		{
			score += 0;
		}
		else if (count_small_letter == 0 || count_big_letter == 0)
		{
			score += 10;
		}
		else
		{
			score += 20;
		}
		if (count_num == 0)
		{
			score += 0;
		}
		else if (count_num == 1)
		{
			score += 10;
		}
		else
		{
			score += 20;
		}
		if (count_character == 0)
		{
			score += 0;
		}
		else if (count_character == 1)
		{
			score += 10;
		}
		else
		{
			score += 25;
		}
		if (count_small_letter > 0 && count_big_letter > 0 && count_num > 0 && count_character > 0)
		{
			score += 5;
		}
		else if ((count_small_letter > 0 || count_big_letter > 0) && count_num > 0 && count_character > 0)
		{
			score += 3;
		}
		else if ((count_small_letter > 0 || count_big_letter > 0) && count_num > 0 && count_character == 0)
		{
			score += 2;
		}
		if (score >= 90)
		{
			printf("VERY_SECURE\n");
		}
		else if (score >= 80)
		{
			printf("SECURE\n");
		}
		else if (score >= 70)
		{
			printf("VERY_STRONG\n");
		}
		else if (score >= 60)
		{
			printf("STRONG\n");
		}
		else if (score >= 50)
		{
			printf("AVERAGE\n");
		}
		else if (score >= 25)
		{
			printf("WEAK\n");
		}
		else if (score >= 0)
		{
			printf("VERY_WEAK\n");
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