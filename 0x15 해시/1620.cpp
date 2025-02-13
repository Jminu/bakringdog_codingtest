#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
int m;
unordered_map<int, string> m1;
unordered_map<string, int> m2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		m1[i] = name;
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		if (str[0] >= 49 && str[0] <= 57) //���ڸ� �Է¹޾��� ��
		{
			int num = atoi(str.c_str());
			unordered_map<int, string>::iterator it = m1.find(num);
			if (it != m1.end())
			{
				cout << it->second << '\n';
			}
		}
		else //���ϸ� �̸��� �Է¹޾��� ��
		{
			unordered_map<string, int>::iterator it = m2.find(str);
			if (it != m2.end())
			{
				cout << it->second << '\n';
			}
		}
	}
}