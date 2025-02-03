//BOJ 16953 A->B
#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A;
	int B;
	int cnt = 0;

	cin >> A >> B;

	while (A != B)
	{
		if (A > B)
		{
			cnt = -1;
			break;
		}

		if (B % 2 == 0) //B가 짝수일 때
		{
			B = B / 2;
			cnt++;
		}
		else //B가 홀수일 때
		{
			if (B % 10 == 1) //1의 자리가 1인 홀수
			{
				B = B / 10;
				cnt++;
			}
			else //일반적인 홀수는 불가능
			{
				cnt = -1;
				break;
			}
		}
	}

	if (cnt == -1)
		cout << cnt;
	else
		cout << cnt + 1;
}