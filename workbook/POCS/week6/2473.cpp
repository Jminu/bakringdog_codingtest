//BOJ 2473 �� ���
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
int arr[5001] = { 0 };
long long int result[3] = { 0 };

//������ ������ 0�� �� ������.
long long int compare(long long int a, long long int b)
{
	if (llabs(a) < llabs(b)) //�׳� abs�� ����ϸ� int���� ��ȯ�Ѵ�.
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
	
	for (p1 = 0; p1 < n - 2; p1++) //ù��° ����� ������ ä�� 
	{
		p2 = p1 + 1;
		p3 = n - 1;

		while (p2 < p3) //������ 2���� ����� �������͸� ����ؼ� Ž��
		{
			total = (long long int)arr[p1] + arr[p2] + arr[p3]; //int�������θ� ���ϸ� overflow,
			close_val = compare(close_val, total);              //�׷��� lli������ ĳ����

			if (close_val == total) //0�� �� ����� ������ �����ߴٸ�
			{
				result[0] = arr[p1]; //3���� ����� ����
				result[1] = arr[p2];
				result[2] = arr[p3];
			}

			//0���� ũ�� ���� ū p3�� ���ҽ�Ű��
			//0���� ������ ���� ���� p2�� ����
			if (total > 0)
				p3--;
			else if (total < 0)
				p2++;
			else //total=0�̸�, ��
			{
				result[0] = arr[p1];
				result[1] = arr[p2];
				result[2] = arr[p3];
				return; //3���� ����� �����ϰ�, �Լ� ����
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