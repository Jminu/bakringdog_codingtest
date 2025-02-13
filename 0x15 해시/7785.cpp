#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int n;
unordered_set<string> s;
vector<string> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < n; i++)
	{
		string name;
		string log;
		
		cin >> name >> log;

		if (log == "enter")
		{
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}

	for (unordered_set<string>::iterator it = s.begin(); it != s.end(); it++)
	{
		v.push_back(*it);
	}

	sort(v.begin(), v.end());

	for (vector<string>::iterator it = v.end() - 1; it >= v.begin(); it--)
	{
		cout << *it << '\n';
	}
}