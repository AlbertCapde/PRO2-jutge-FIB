#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;


void llegeix(vector<stack<string> >& v) {
	string llibre;
	int categoria;
	cin >> llibre >> categoria;
	v[categoria - 1].push(llibre);
}

void retira(vector<stack<string> >& v) {
	int categoria, nombre;
	cin >> nombre >> categoria;
	for (int i = 0; i < nombre; ++i) {
		v[categoria - 1].pop();
	}
}

void escriu(vector<stack<string> >& v) {
	int categoria;
	cin >> categoria;
	cout << "Pila de la categoria " << categoria << endl;
	stack<string> copia(v[categoria-1]);
	
	while (!copia.empty()) {
		cout << copia.top() << endl;
		copia.pop();
	}
}

int main() {
	int categories;
	cin >> categories;
	vector<stack<string> > devolucions(categories);
	int moviment;
	while (cin >> moviment and moviment != -4) {
		if (moviment == -1) llegeix(devolucions);
		else if (moviment == -2) retira(devolucions);
		else if (moviment == -3) {
			escriu(devolucions);
			cout << endl;
		}
	}
}
