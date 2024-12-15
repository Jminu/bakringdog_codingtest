#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int alpha[26] = { 0 };
	string S;
	getline(cin, S);
	
	for (int i = 0; i < S.length(); i++) {
		alpha[S[i] - 'a']++;
	}
	
	for (int i = 0; i < sizeof(alpha) / 4; i++) {
		cout << alpha[i] << " ";
	}

	return 0;
}