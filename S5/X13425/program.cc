#include <iostream>
#include <queue>
#include "CuaIOParInt.hh"
#include "ParInt.hh"
using namespace std;


int main() {
	queue<ParInt> cua;
	llegirCuaParInt(cua);
	queue<ParInt> cua1;
	queue<ParInt> cua2;
	
	int temp1, temp2;
	temp1 = temp2 = 0;
	while (!cua.empty()) {
		ParInt consulta;
		consulta = cua.front();
		if (temp1 > temp2) {
			cua2.push(consulta);
			temp2 += consulta.segon();
		}
		else {
			cua1.push(consulta);
			temp1 += consulta.segon();
		}
		cua.pop();
	}
	escriureCuaParInt(cua1);
	cout << endl;
	escriureCuaParInt(cua2);
}
