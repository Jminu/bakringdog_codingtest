#include <iostream>
using namespace std;

int N;
int S;
int input_arr[21] = { 0 }; //���� ����
int output_arr[21] = { 0 }; //�κ� ����
bool is_used[21] = { false };
int sequences = 0;

//�κм����� �� ���ϱ�
int get_sum(int length) {
	int result = 0;
	for (int i = 0; i < length; i++) {
		result += output_arr[i];
	}
	return result;
}

void backtracking(int k, int start, int length) { //Ž���� ������ start�� �ؼ� �ߺ��� ����. (-3, 3) (3, -3)�� ����
	if (k == length) { //������ ���̸�ŭ �迭�� ä���
		if (get_sum(length) == S) //���� �κм����� ���� S�� ���ٸ�
			sequences++; //�������� ����
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