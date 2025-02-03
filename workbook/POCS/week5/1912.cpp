#include <iostream>
using namespace std;

int N;
int arr[100001];
int DP[100001];
int max_val;

//최댓값 리턴
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
		DP[i] = find_max(DP[i - 1] + arr[i], arr[i]); //이전까지의 합과, 현재위치한 값을 비교,
													//만약, 현재위치한 값을 더했는데 더 작아졌다? -> 손해.
													//현재위치의 바로 다음위치부터 다시 시작
		max_val = find_max(max_val, DP[i]); //최댓값을 갱신
	}

	cout << max_val;
}