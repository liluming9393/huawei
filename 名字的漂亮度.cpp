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
	int n;
	string s;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			vector<int> count(26);
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			for (int i = 0; i < s.size(); i++)
			{
				count[s[i] - 'a']++; 
			}
			sort(count.begin(), count.end());
			int res = 0;
			for (int i = 0; i < 26; i++)
			{
				res += (i + 1)*count[i];
			}
			cout << res << endl;
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