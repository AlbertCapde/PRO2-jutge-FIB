#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
	list<ParInt>::iterator it = l.begin();
	ParInt x; 
	while (x.llegir()) l.insert(it, x);
}

/*void EscriureLlistaParInt(const list<ParInt>& l) {
	if (not l.empty()) {
		list<int>::const_iterator it;
		cout << "[Primero] ";
		for (it = l.begin(); it != l.end(); ++it){
			cout << *it << " ";
			cout << "[Ultimo]";
		} 
		cout << endl;
}*/
