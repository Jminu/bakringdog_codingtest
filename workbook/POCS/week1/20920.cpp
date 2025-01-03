#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> v1, pair<string, int> v2)
{
	if (v1.second != v2.second) //빈도수 비교
		return v1.second > v2.second;
	else if (v1.first.length() != v2.first.length()) //길이 비교
		return v1.first.length() > v2.first.length();
	else if (v1.first[0] != v2.first[0]) //사전식 비교
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

	//map으로 만든다.
	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		
		if (word_map.find(word) != word_map.end()) //이미 map에 존재하면
		{
			word_map[word]++;
		}
		else //존재 안하면
		{
			word_map.insert({ word, 1 });
		}
	}

	vector<pair<string, int>> word_vector;

	//map을 돌면서 vector에 삽입함
	for (map<string, int>::iterator it = word_map.begin(); it != word_map.end(); it++)
	{
		pair<string, int> map_temp = *it;
		word_vector.push_back(map_temp);
	}

	//정렬
	sort(word_vector.begin(), word_vector.end(), comp);

	//출력
	for (vector<pair<string, int>>::iterator it = word_vector.begin(); it != word_vector.end(); it++)
	{
		if ((*it).first.length() < M) //단어의 길이가 M보다 작으면 건너뜀
			continue;
		cout << (*it).first << '\n';
	}
}