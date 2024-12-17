#include <iostream>
#include <string>

using namespace std;

const int MAX = 10000;

int deque[2*MAX + 1] = { 0 };
int front = MAX;
int rear = MAX;

void push_front(int X) {
	deque[front] = X;
	front--;
}

void push_back(int X) {
	rear++;
	deque[rear] = X;
}

int pop_front() {
	if (front == rear)
		return -1;
	front++;
	return deque[front];
}

int pop_back() {
	if (front == rear)
		return -1;
	int temp = deque[rear];
	rear--;
	return temp;
}

int size() {
	int cnt = 0;
	for (int i = front + 1; i <= rear; i++) {
		cnt++;
	}
	return cnt;
}

int empty() {
	if (front == rear)
		return 1;
	else
		return 0;
}

int peek_front() {
	if (front == rear)
		return -1;
	return deque[front + 1];
}

int peek_rear() {
	if (front == rear)
		return -1;
	return deque[rear];
}

int main(void) {
	int N;
	cin >> N;

	string cmd;

	for (int i = 0; i < N; i++) {
		int value = 0;
		cin >> cmd;
		if (cmd.compare("push_front") == 0) {
			int X;
			cin >> X;
			push_front(X);
		}
		else if (cmd.compare("push_back") == 0) {
			int X;
			cin >> X;
			push_back(X);
		}
		else if (cmd.compare("pop_front") == 0) {
			value = pop_front();
			cout << value << '\n';
		}
		else if (cmd.compare("pop_back") == 0) {
			value = pop_back();
			cout << value << '\n';
		}
		else if (cmd.compare("size") == 0) {
			value = size();
			cout << value << '\n';
		}
		else if (cmd.compare("empty") == 0) {
			value = empty();
			cout << value << '\n';
		}
		else if (cmd.compare("front") == 0) {
			value = peek_front();
			cout << value << '\n';
		}
		else {
			value = peek_rear();
			cout << value << '\n';
		}
	}
	return 0;
}