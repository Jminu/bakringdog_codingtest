#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	while (true) {
		bool isValid = true;
		string str;
		getline(cin, str);

		if (str == ".")
			break;

		stack<char> stack;


		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				stack.push(str[i]);
			}
			else if (str[i] == ')') {
				if (stack.empty() || stack.top() != '(') {
					isValid = false;
					break;
				}
				stack.pop();
			}
			else if (str[i] == ']') {
				if (stack.empty() || stack.top() != '[') {
					isValid = false;
					break;
				}
				stack.pop();
			}
		}
		if (!stack.empty())
			isValid = false;
		
		if (isValid)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

}