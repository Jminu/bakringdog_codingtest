#include <iostream>
#include <math.h>
using namespace std;

void cantor(char* str, long long int start_idx, long long int end_idx, long long int length)
{
	long long int divided_length = length / 3;
	long long int first_idx = start_idx;

	if (length == 1)
		return;

	//���̰� 3�� �ɶ��� �߰� ���ڸ� ��������
	if (length == 3)
	{
		str[start_idx + 1] = ' ';
		return;
	}

	//�߾� �κ��� ��������
	for (int i = start_idx + divided_length; i <= start_idx + 2 * divided_length - 1; i++)
	{
		str[i] = ' ';
	}

	cantor(str, first_idx, first_idx + divided_length - 1, divided_length); //ù��° ���
	cantor(str, first_idx + 2 * divided_length, first_idx + 3 * divided_length - 1, divided_length); //����° ���
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long int powered_result;
	

	while (cin >> N)
	{
		powered_result = pow(3, N);
		char* str = new char[powered_result + 1];

		for (int i = 0; i < powered_result; i++) //'-'����
		{
			if (i == powered_result - 1)
				str[i + 1] = '\0'; //���ڿ��� ���� null���� ����

			str[i] = '-';
		}

		cantor(str, 0, powered_result - 1, powered_result);
		cout << str << '\n';

		delete str;
	}
}