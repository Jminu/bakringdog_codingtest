#include <iostream>
using namespace std;

int seat_arr[41] = { 0 };

int fibo(int n) {
	int result = 0;

	if (n == 0 || n == 1)
		return 1;
	else {
		result = fibo(n - 2) + fibo(n - 1);
	}

	return result;
}

int count(int seat_len) {
	int count = 0;
	int result = 0;
	int acc = 1;

	for (int i = 1; i <= seat_len; i++) {
		if (seat_arr[i] != 0) { //vip좌석일 때,
			acc *= fibo(count);
			count = 0;
		}
		else { //일반 좌석일 때,
			if (i == seat_len) { //마지막 좌석 덩어리도 포함시켜야함
				count++;
				acc *= fibo(count);
			}
			count++;
		}
	}
	return acc;
}

int main(void) {
	int N;
	int M;

	cin >> N >> M;

	//고정석 지정
	for (int i = 0; i < M; i++) {
		int vip_seat;
		cin >> vip_seat;
		seat_arr[vip_seat] = vip_seat;
	}

	cout << count(N);
}