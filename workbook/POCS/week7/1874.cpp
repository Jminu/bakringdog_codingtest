#include <iostream>
#include <string>
#define MAX 100001
using namespace std;

int n;
int st[MAX];
int top = -1;
int arr[MAX];
string str;

void push(int item)
{
	if (top == MAX - 1)
		return;
	
	st[++top] = item;
	str.append("+");
}

void pop()
{
	if (top == -1)
		return;

	int popped = st[top--];
	str.append("-");
}

int peek()
{
	return st[top];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int i = 1;
	int idx = 1;
	
	while (true)
	{
		if (idx > n && top == -1) //���������� �� ���´ٸ�, ������ �������
			break;
		else if (i > n && top == n) //���������� ������ ������ ����, push�� ��� �Ұ��� �׷��� ������ ����
			break;

		if (peek() == arr[idx])
		{
			pop();
			idx++;
		}
		else
		{
			push(i);
			i++;
		}
	}

	if (idx > n && top == -1)
		for (int i = 0; i < str.length(); i++)
			cout << str[i] << '\n';

	if (i > n && top == n)
		cout << "NO" << '\n';
}