/** @file Cromosomes.hh
    @brief Especificació de la classe Cromosomes
*/

#ifndef _CROMOSOMES_
#define _CROMOSOMES_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif


/*
 * Classe Cromosomes
 */
 
/** @class Cromosomes
    @brief Representa el parell de cromosomes.
    
    Conté els cromosomes i operacions per tratar-los.
*/

class Cromosomes {

private:

	/** @brief Vector del parell de cromosomes */
	vector<char> crom;

public:

	// Constructora

	/** @brief Creador per defecte
		@pre cert
		@post El resultat es un vector de cromosomes buit
	*/
	Cromosomes();

	//Modificadores
	
	/** @brief Modificadora els cromosomes
		\pre cert
		\post El parametre implicit conté la intersecció del seu vector i el 
		passar per paràmetre
	*/
	void combinacio_crom(const Cromosomes& x);
	
	// Lectura i escriptura
	
	/** @brief Operació de lectura
		\pre cert
		\post El parametre implícit conté el vector de cromosomes llegit del 
		canal estandard d'entrada
	*/
	void llegir_cromosomes(int m);
	
	/** @brief Operació de escriptura
		\pre cert
		\post S'escriu pel el canal de sortida estàndard el vector de cromosomes
	*/
	void escriure_cromosomes() const;
};
#endif
