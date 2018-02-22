#include <iostream>
#include <stack>
using namespace std;


bool avaluacio() {
	char c;
	bool correcte = true;
	stack<char> p;
	
	cin >> c;
	if (c == '(' or c == '[') p.push(c);
	else correcte = false;
	
	while (correcte and c != '.') {
		cin >> c;
		if (p.empty() and (c==']' or c==')')) correcte=false;
		else if (c == ')' and p.top() == '(') p.pop();
		else if (c == ')' and p.top() != '[') correcte=false;
		else if (c == ']' and p.top() == '[') p.pop();
		else if (c == ']' and p.top() != '(') correcte=false;
		else if (c == '(' or c == '[') p.push(c);
	}
	if (correcte) correcte = p.empty();
	return correcte;
}


int main() {
	if (avaluacio()) cout << "Correcte";
	else cout << "Incorrecte";
	cout << endl;
}
