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

		if (B % 2 == 0) //B�� ¦���� ��
		{
			B = B / 2;
			cnt++;
		}
		else //B�� Ȧ���� ��
		{
			if (B % 10 == 1) //1�� �ڸ��� 1�� Ȧ��
			{
				B = B / 10;
				cnt++;
			}
			else //�Ϲ����� Ȧ���� �Ұ���
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