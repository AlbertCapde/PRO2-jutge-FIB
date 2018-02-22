#include <iostream>
#include <stack>
using namespace std;


bool palindrom(stack<int> p, int n) {
	int x;
	bool pal = true;
	
	if (n%2 == 0) {//par
		int i = 0;
		while (pal and i < n/2) {
			cin >> x;
			p.push(x);
			i++;
		}
		while (pal and i < n) {
			cin >> x;
			pal = p.top() == x;
			p.pop();
			i++;
		}
	}
	
	else {//impar
		int i = 0;
		while (pal and i < n/2) {
			cin >> x;
			p.push(x);
			i++;
		}
		cin >> x;
		p.push(x);
		p.pop();
		i++;
		while (pal and i < n) {
			cin >> x;
			pal = p.top() != x;
			p.pop();
			i++;
		}
	}
	return pal;
}


int main() {
	int n;
	cin >> n;
	stack<int> p;
	if (palindrom(p, n)) cout << "SI";
	else cout << "NO";
	cout << endl;
}
