#include <iostream>
#include <vector>
using namespace std;

#include "vectorIOint.hh"

vector<int> busqueda(const vector<int>& v) {
	vector<int> max_min(2);
	int max = v[0];
	int min = v[0];
	
	for (int i = 0; i < v.size(); ++i) {
		if (max < v[i]) max = v[i];
		if (min > v[i]) min = v[i];
	}
	max_min[0] = max;
	max_min[1] = min;
	return max_min;
}

int main() {
	vector<int> v;
	vector<int> resultado;
	leer_vector_int(v);
	resultado = busqueda(v);
	cout << resultado[0] << " " << resultado[1] << endl;
}
