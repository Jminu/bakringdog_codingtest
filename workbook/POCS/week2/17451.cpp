#include <iostream>
using namespace std;


//������ ������ ũ�鼭, ���� ���� ����� �Ǿ����
long long int func(long long int* input_arr, int arr_length)
{
	long long int current_speed = input_arr[arr_length - 1]; //����ӵ� 300

	for (int i = arr_length - 2; i >= 0; i--)
	{
		if (current_speed % input_arr[i] != 0) {
			current_speed = (current_speed / input_arr[i] + 1) * input_arr[i];
		}
	}
	return current_speed;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int first_speed = 0;
	int n;
	cin >> n;

	long long int* input_arr = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> input_arr[i];
	}

	cout << func(input_arr, n);
	delete[] input_arr;
}