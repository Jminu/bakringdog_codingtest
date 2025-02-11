//BOJ 2473 세 용액
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
int arr[5001] = { 0 };
long long int result[3] = { 0 };

//절댓값이 작은게 0에 더 가깝다.
long long int compare(long long int a, long long int b)
{
	if (llabs(a) < llabs(b)) //그냥 abs를 사용하면 int형을 반환한다.
		return a;
	else
		return b;
}

void two_pointer()
{
	int p1;
	int p2;
	int p3;

	long long int total = 0;
	long long int close_val = (long long int)arr[0] + arr[1] + arr[n - 1];
	
	for (p1 = 0; p1 < n - 2; p1++) //첫번째 용액을 고정한 채로 
	{
		p2 = p1 + 1;
		p3 = n - 1;

		while (p2 < p3) //나머지 2개의 용액을 투포인터를 사용해서 탐색
		{
			total = (long long int)arr[p1] + arr[p2] + arr[p3]; //int형식으로만 더하면 overflow,
			close_val = compare(close_val, total);              //그래서 lli형으로 캐스팅

			if (close_val == total) //0과 더 가까운 곳으로 갱신했다면
			{
				result[0] = arr[p1]; //3가지 용액을 저장
				result[1] = arr[p2];
				result[2] = arr[p3];
			}

			//0보다 크면 가장 큰 p3를 감소시키고
			//0보다 작으면 가장 작은 p2를 증가
			if (total > 0)
				p3--;
			else if (total < 0)
				p2++;
			else //total=0이면, 끝
			{
				result[0] = arr[p1];
				result[1] = arr[p2];
				result[2] = arr[p3];
				return; //3개의 용액을 저장하고, 함수 종료
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	two_pointer();

	for (int i = 0; i < 3; i++)
		cout << result[i] << ' ';

}