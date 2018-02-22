#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"
#include "ParInt.hh"
using namespace std;


int main() {
	list<ParInt> lista;
	LlegirLlistaParInt(lista);
	int n, suma, cont;
	suma = cont = 0;
	cin >> n;
	
	list<ParInt>::iterator it;
	if (!lista.empty()) {
		it = lista.begin();
		while(it != lista.end()) {
			if ((*it).primer() == n) {
			++cont;
			suma += (*it).segon();
			}
		++it;	
		}
		cout << n << " " << cont << " " << suma;
	}
	
	else cout << n << " " << 0 << " " << 0;
	cout << endl;
}
