//����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
/*���� :
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���(����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��
�������� :
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
�ļ�·��Ϊwindows��ʽ
�磺E : \V1R2\product\fpgadrive.c 1325
�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ�������������Ŀ��һ���ո�������� : fpgadrive.c 1325 1
���������Ŀ�Ӷൽ��������Ŀ��ͬ������£����������һ�γ���˳������
�������8����¼����ֻ���ǰ8����¼.
����ļ����ĳ��ȳ���16���ַ�����ֻ�����16���ַ�
�������� :E : \V1R2\product\fpgadrive.c 1325
�������:fpgadrive.c 1325 1*/
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
#include<functional>
#include<iostream>
using namespace std;
bool cmp_key(const pair<pair<string, string>, pair<int, int>> &c1, const pair<pair<string, string>, pair<int, int>> &c2)
{
	if (c1.second.second < c2.second.second)
	{
		return true;
	}
	/*else if (c1.second.first == c2.second.first)
	{
		if (c1.second.second < c2.second.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
	else
	{
		return false;
	}
}
int main()
{
	string input;
	int time = 0;
	bool(*ptr)(pair<int, int> &c1, pair<int, int> &c2);
	pair<int, int> count_time;
	pair<string, string> filename_row;
	multimap<pair<string, string>, pair<int, int>> m;
	multimap<pair<string, string>, pair<int, int>>::iterator it;
	int i;
	int j;
	while (getline(cin, input))
	{
		if (input.size() == 0)
		{
			break;
		}
		time++;
		//cout << input << endl;
		i = input.size() - 1;
		while (input[i] != '\\' && i >= 0)
		{
			i--;
		}
		j = i + 1;
		while (input[j] != ' '&& j < input.size())
		{
			j++;
		}
		filename_row.first = input.substr(i + 1, j - i - 1);
		filename_row.second = input.substr(j + 1, input.size() - j - 1);
		//cout << filename_row.first << endl;
		//cout << filename_row.second << endl;
		it = m.find(filename_row);
		if (it == m.end())
		{
			count_time.first = 1;
			count_time.second = time;
			m.insert(pair<pair<string, string>, pair<int, int >>(filename_row, count_time));
		}
		else
		{
			(*it).second.first++;
		}
	}
	vector<pair<pair<string, string>, pair<int, int>>> v;
	it = m.begin();
	while (it != m.end())
	{
		v.push_back((*it));
		it++;
	}
	sort(v.begin(), v.end(), cmp_key);
	if (v.size() > 8)
	{
		for (int i = 0; i < 8; i++)
		{
			v[i] = v[v.size() - 8 + i];
		}
		v.resize(8);
	}
	for (int i = 0; i < v.size(); i++)
	{
		string filename = v[i].first.first;
		if (filename.size()>16)
		{
			filename = filename.substr(filename.size() - 16, 16);
		}
		cout << filename << " " << v[i].first.second << " " << v[i].second.first << endl;
	}
	return 0;
}
