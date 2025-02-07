//BOJ 9663 N-Queen
#include <iostream>
using namespace std;

int n;
int is_used1[40] = { 0 };
int is_used2[40] = { 0 };
int is_used3[40] = { 0 };
int cnt = 0;

void func(int cur_row) //cur_row: ���� ��ġ�� ��, ���� ���� �࿡ �� �� ����.
{
	if (cur_row == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (is_used1[i] || is_used2[i + cur_row] || is_used3[i - cur_row + n - 1])
			continue;

		is_used1[i] = 1;
		is_used2[i + cur_row] = 1;
		is_used3[i - cur_row + n - 1] = 1;
		func(cur_row + 1); //���������� ����
		is_used1[i] = 0;
		is_used2[i + cur_row] = 0;
		is_used3[i - cur_row + n - 1] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0); //0����� ����

	cout << cnt;
}