#include <iostream>
#include <math.h>
using namespace std;

void cantor(char* str, long long int start_idx, long long int end_idx, long long int length)
{
	long long int divided_length = length / 3;
	long long int first_idx = start_idx;

	if (length == 1)
		return;

	//길이가 3이 될때는 중간 문자만 공백으로
	if (length == 3)
	{
		str[start_idx + 1] = ' ';
		return;
	}

	//중앙 부분을 공백으로
	for (int i = start_idx + divided_length; i <= start_idx + 2 * divided_length - 1; i++)
	{
		str[i] = ' ';
	}

	cantor(str, first_idx, first_idx + divided_length - 1, divided_length); //첫번째 등분
	cantor(str, first_idx + 2 * divided_length, first_idx + 3 * divided_length - 1, divided_length); //세번째 등분
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

		for (int i = 0; i < powered_result; i++) //'-'삽입
		{
			if (i == powered_result - 1)
				str[i + 1] = '\0'; //문자열의 끝에 null문자 삽입

			str[i] = '-';
		}

		cantor(str, 0, powered_result - 1, powered_result);
		cout << str << '\n';

		delete str;
	}
}