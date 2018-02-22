#include <iostream>
#include <list>
using namespace std;


void anadir_a_lista(list<int>& l, int nombre) {
	list<int>::iterator it = l.end();
	l.insert(it, nombre);
}


void eliminar_de_lista(list<int>& l, int nombre) {
	if (!l.empty()) {
		list<int>::iterator it = l.begin();
		bool trobat = false;
		while (!trobat and it != l.end()) {
			trobat = (*it == nombre);
			if (!trobat) ++it;
		 }
		 if(trobat) l.erase(it);
	}
}


void salida(list<int>& l) {
	if (l.empty()) cout << 0 << endl;
	else {
		int min, max;
		double mitj = 0.0;
		list<int>::const_iterator it = l.begin();
		min = *it;
		max = *it;
		while (it != l.end()) {
			mitj += *it;
			if (max < *it) max = *it;
			if (min > *it) min = *it;
			++it;
		}
		cout << min << " " << max << " " << mitj/l.size() << endl;
	}
}

int main() {
	list<int> l;
	int codi, nombre;
	cin >> codi >> nombre;
	while (codi != 0 and nombre != 0) {
		if (codi == -1) anadir_a_lista(l, nombre);
		else if (codi == -2) eliminar_de_lista(l, nombre);
		salida(l);
		cin >> codi >> nombre;
	}
}
