//�ݺ������� Ǯ�� �ð��ʰ��� ����.
//���� ��Ģ, ��ⷯ ����
//������Ģ: a^(n+m) = a^n * a^m
// 
// if(������ ¦��) -> a^b = a^(b/2) x a^(b/2)
// if(������ Ȧ��) -> a^b = a^(b/2) x a^(b/2 + 1)
// 
//��ⷯ ����: (a*b)%c = (a%c * b%c)%c

#include <iostream>
using namespace std;

//2^7 ,,, 2^3,,,, 2^1
long long int power_recursion(int x, int n, int c) {
	if (n == 0)
		return 1;

	if (n == 1)
		return x % c;

	long long int k = power_recursion(x, n / 2, c);


	if (n % 2 == 0) {
		return k * k % c;
	}
	else {
		return k * k % c * x % c;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A;
	int B;
	int C;

	cin >> A >> B >> C;

	long long int result = power_recursion(A, B, C);

	cout << result;
}