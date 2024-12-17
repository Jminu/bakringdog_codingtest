#include <iostream>
#include <string>

using namespace std;

int queue[100000] = { 0 };
int f = -1;
int r = -1;

void push(int x) {
	r++;
	queue[r] = x;
}

int pop() {
	if (f == r)
		return -1;
	f++;
	return queue[f];
}

int size() {
	int cnt = 0;
	for (int i = f + 1; i <= r; i++) {
		cnt++;
	}
	return cnt;
}

int empty() {
	if (f == r) return 1;
	else return 0;
}

int front() {
	if (f == r)
		return -1;
	return queue[f + 1];
}

int back() {
	if (f == r)
		return -1;
	return queue[r];
}

int main(void) {
	int N;
	string cmd;

	cin >> N;
	getchar();

	for (int i = 0; i < N; i++) {
		cmd = "";
		cin >> cmd;
		
		if (cmd.compare("push") == 0) {
			int X;
			cin >> X;
			push(X);
		}
		else if (cmd.compare("pop") == 0) {
			int X;
			X = pop();
			cout << X << '\n';
		}
		else if (cmd.compare("size") == 0) {
			int queue_size;
			queue_size = size();
			cout << queue_size << '\n';

		}
		else if (cmd.compare("empty") == 0) {
			int empty_val;
			empty_val = empty();
			cout << empty_val << '\n';
		}
		else if (cmd.compare("front") == 0) {
			int front_val;
			front_val = front();
			cout << front_val << '\n';
		}
		else {
			int back_val;
			back_val = back();
			cout << back_val << '\n';
		}
	}

	return 0;
}