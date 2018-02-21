#include <iostream>
#include <vector>
using namespace std;

#include "Estudiant.hh"


void seleccio(vector<bool>& v, int n) {
	for (int i = 0; i < n; i++) {
		int assig;
		cin >> assig;
		v[assig - 1] = true;
	}
}

void mitjanes(vector<Estudiant>& est,const vector<bool>& selec, int sel) {
	int tam = est.size();
	int assig = selec.size();
	for (int  i = 0; i < tam; i++) {
		int dni;
		cin >> dni;
		Estudiant x(dni);
		est[i] = x;
		double mitj = 0;
		for (int j = 0; j < assig; j++) {
			double nota;
			cin >> nota;
			if (selec[j]) mitj += nota;
		}
		mitj = mitj/sel;
		est[i].afegir_nota(mitj);
	}
}


int main() {
	int nestudiants, nassignatures, seleccionades;
	cin >> nestudiants >> nassignatures >> seleccionades;
	vector<bool> assig_selec(nassignatures, false);
	seleccio(assig_selec, seleccionades);
	vector<Estudiant> estudiants(nestudiants);
	mitjanes(estudiants, assig_selec, seleccionades);
	for (int i = 0; i < nestudiants; i++) estudiants[i].escriure();
}
