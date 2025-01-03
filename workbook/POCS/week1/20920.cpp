#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> v1, pair<string, int> v2)
{
	if (v1.second != v2.second) //�󵵼� ��
		return v1.second > v2.second;
	else if (v1.first.length() != v2.first.length()) //���� ��
		return v1.first.length() > v2.first.length();
	else if (v1.first[0] != v2.first[0]) //������ ��
		return v1.first < v2.first;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int M;

	cin >> N >> M;

	//map<key, value>
	map<string, int> word_map;

	//map���� �����.
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		
		if (word_map.find(word) != word_map.end()) //�̹� map�� �����ϸ�
		{
			word_map[word]++;
		}
		else //���� ���ϸ�
		{
			word_map.insert({ word, 1 });
		}
	}

	vector<pair<string, int>> word_vector;

	//map�� ���鼭 vector�� ������
	for (map<string, int>::iterator it = word_map.begin(); it != word_map.end(); it++)
	{
		pair<string, int> map_temp = *it;
		word_vector.push_back(map_temp);
	}

	//����
	sort(word_vector.begin(), word_vector.end(), comp);

	//���
	for (vector<pair<string, int>>::iterator it = word_vector.begin(); it != word_vector.end(); it++)
	{
		if ((*it).first.length() < M) //�ܾ��� ���̰� M���� ������ �ǳʶ�
			continue;
		cout << (*it).first << '\n';
	}
}