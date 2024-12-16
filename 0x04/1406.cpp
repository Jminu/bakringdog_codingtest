#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
	string S;
	int M; //��ɾ� ����

	getline(cin, S); //���ڿ�
	cin >> M; //���� ���� �Է�

	list<char> myList;
	for (int i = 0; i < S.length(); i++) {
		myList.push_back(S[i]);
	}

	list<char>::iterator cursor;
	cursor = myList.end();
	
	for (int i = 0; i < M; i++) {
		char cmd;
		cin >> cmd;

		switch (cmd) {
		case 'L': //Ŀ���� �������� ��ĭ�̵�
			if (cursor == myList.begin()) continue;
			else cursor--;
			break;

		case 'D': //Ŀ���� ���������� ��ĭ�̵�
			if (cursor == myList.end()) continue;
			else cursor++;
			break;

		case 'B': //Ŀ�� ���� ���ڸ� ����
			if (cursor == myList.begin()) continue;
			else {
				list<char>::iterator temp = cursor;
				cursor--;
				myList.erase(cursor);
				cursor = temp;
			}
			break;

		case 'P': //Ŀ�� �����ʿ� ���� �߰�
			char c;
			cin >> c;
			if (cursor == myList.end()) {
				myList.push_back(c);
				cursor = myList.end();
			}
			else {
				myList.insert(cursor, c);
			}
			break;
		}
	}

	for (list<char>::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it;
	}

	return 0;
}