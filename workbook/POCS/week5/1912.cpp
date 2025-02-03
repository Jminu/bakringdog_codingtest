#include <iostream>
using namespace std;

int N;
int arr[100001];
int DP[100001];
int max_val;

//�ִ� ����
int find_max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	max_val = arr[0];
	DP[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		DP[i] = find_max(DP[i - 1] + arr[i], arr[i]); //���������� �հ�, ������ġ�� ���� ��,
													//����, ������ġ�� ���� ���ߴµ� �� �۾�����? -> ����.
													//������ġ�� �ٷ� ������ġ���� �ٽ� ����
		max_val = find_max(max_val, DP[i]); //�ִ��� ����
	}

	cout << max_val;
}