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
void train(vector<int> data, vector<int> in, vector<int> out, int num, vector<string> &result);
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> data(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &data[i]);
		}
		vector<int> in;
		vector<int> out;
		vector<string> result;
		train(data, in, out, 0, result);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}
void train(vector<int> data, vector<int> in, vector<int> out, int num, vector<string> &result)
{
	if (num == data.size())
	{
		while (in.size() != 0)
		{
			out.push_back(in[in.size() - 1]);
			in.pop_back();
		}
		string res;
		for (int i = 0; i < out.size() - 1; i++)
		{
			res = res + (char)(out[i] + '0') + ' ';
		}
		res = res + (char)(out[out.size() - 1] + '0');
		result.push_back(res);
		return;
	}
	if (num != data.size())
	{
		in.push_back(data[num]);
		train(data, in, out, num + 1, result);
		in.pop_back();
		if (in.size() != 0)
		{
			out.push_back(in[in.size() - 1]);
			in.pop_back();
			train(data, in, out, num, result);
		}
	}
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