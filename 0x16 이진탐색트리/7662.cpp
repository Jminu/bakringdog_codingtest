//BOJ 7662
#include <iostream>
#include <set>

using namespace std;

int t;
int k;
multiset<int> sm;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> k;
		sm.clear(); //트리 비움
		for (int j = 0; j < k; j++)
		{
			char ch_operator;
			long long int operand;

			cin >> ch_operator >> operand;
			switch (ch_operator)
			{
			case 'I':
				sm.insert(operand); //값 삽입, 넣으면 자동으로 정렬 (이진탐색트리)
				break;
			case 'D':
				if (sm.empty())
					break;

				if (operand == 1) //최댓값 삭제
				{
					multiset<int>::iterator max_it = prev(sm.end());
					sm.erase(max_it);
				}
				else //최솟값 삭제
				{
					multiset<int>::iterator min_it = sm.begin();
					sm.erase(min_it);
				}
				break;
			}
		}

		if (sm.empty())
			cout << "EMPTY" << '\n';
		else
		{
			multiset<int>::iterator max_it = prev(sm.end());
			multiset<int>::iterator min_it = sm.begin();

			cout << *max_it << ' ' << *min_it << '\n';
		}
	}
}