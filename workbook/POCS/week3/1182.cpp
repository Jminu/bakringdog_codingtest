#include <iostream>
using namespace std;

int N;
int S;
int input_arr[21] = { 0 }; //원래 수열
int output_arr[21] = { 0 }; //부분 수열
bool is_used[21] = { false };
int sequences = 0;

//부분수열의 합 구하기
int get_sum(int length) {
	int result = 0;
	for (int i = 0; i < length; i++) {
		result += output_arr[i];
	}
	return result;
}

void backtracking(int k, int start, int length) { //탐색의 시작은 start로 해서 중복을 막음. (-3, 3) (3, -3)은 같음
	if (k == length) { //수열의 길이만큼 배열을 채우면
		if (get_sum(length) == S) //구한 부분수열의 합이 S와 같다면
			sequences++; //수열개수 증가
		return;
	}

	for (int i = start; i < N; i++) {
		output_arr[k] = input_arr[i];
		backtracking(k + 1, i + 1, length);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		cin >> input_arr[i];
	}

	for (int i = 1; i <= N; i++) {
		backtracking(0, 0, i);
	}
	
	cout << sequences;
}