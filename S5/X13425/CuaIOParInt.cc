#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
	ParInt x;
	while (x.llegir()) c.push(x);
}

void escriureCuaParInt(queue<ParInt> c) {
	ParInt x;
	while (!c.empty()) {
		x = c.front();
		x.escriure();
		c.pop();
	}
}
