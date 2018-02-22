#include <iostream>
#include <queue>
using namespace std;


void consultar(queue<int>& cua) {
	int min, max;
	double media;
	queue<int> copia;
	copia = cua;
	min = max = media = copia.front();	
	copia.pop();
	while(!copia.empty()) {
		if (min > copia.front()) min = copia.front();
		if (max < copia.front()) max = copia.front();
		media += copia.front();
		copia.pop();
	}
	media = media/cua.size();
	cout << "min " << min << "; max " << max << "; media " << media;
	cout << endl;
}


int main() {
	queue<int> cua;
	int seq;
	while(cin >> seq and (seq > -1002 and seq < 1001)) {
		if(seq == -1001) {
			if (!cua.empty()) {
				cua.pop();
				if (cua.empty()) cout << 0 << endl;
				else consultar(cua);
			}
			else cout << 0 << endl;
		}
		else {
			cua.push(seq);
			consultar(cua);
		}
	}
}
