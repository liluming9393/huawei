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
	string key;
	string s;
	while (cin >> key)
	{
		cin >> s;
		transform(key.begin(), key.end(), key.begin(), ::tolower);
		vector<char> data(26);
		set<char> key_set;
		set<char>::iterator it;
		int count = 0;
		for (int i = 0; i < key.size(); i++)
		{
			it = key_set.find(key[i]);
			if (it == key_set.end())
			{
				key_set.insert(key[i]);
				data[count] = key[i];
				count++;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			it = key_set.find('a' + i);
			if (it == key_set.end())
			{
				data[count] = 'a' + i;
				count++;
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = data[s[i] - 'A'] - 'a' + 'A';
			}
			else
			{
				s[i] = data[s[i] - 'a'];
			}
		}
		cout << s << endl;
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