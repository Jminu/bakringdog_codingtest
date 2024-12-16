#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
	string S;
	int M; //명령어 개수

	getline(cin, S); //문자열
	cin >> M; //명렁어 개수 입력

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
		case 'L': //커서를 왼쪽으로 한칸이동
			if (cursor == myList.begin()) continue;
			else cursor--;
			break;

		case 'D': //커서를 오른쪽으로 한칸이동
			if (cursor == myList.end()) continue;
			else cursor++;
			break;

		case 'B': //커서 왼쪽 문자를 삭제
			if (cursor == myList.begin()) continue;
			else {
				list<char>::iterator temp = cursor;
				cursor--;
				myList.erase(cursor);
				cursor = temp;
			}
			break;

		case 'P': //커서 오른쪽에 문자 추가
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