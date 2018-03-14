#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    pair<char, string> p;
    map<string, int> m;
    
    while (cin >> p.first and cin >> p.second){
        if (p.first == 'a') ++m[p.second];
        else if (p.first == 'e'){
             if (m[p.second] != 0) --m[p.second];
        }
        else cout << m[p.second] << endl;
    }
}
