/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH

#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../Data/Data.hh"
#include "../Tasca/Tasca.hh"
#include "../Comanda/Comanda.hh"
using namespace std;
/** @class Agenda
    @brief Representa una agenda.
*/

class Agenda {
private:
	Data rellotge;
	map<Data,Tasca> m;
	vector<map<Data, Tasca>::iterator> menu;

	void consulta_etiqueta(const string &e);
	void consulta_expressio(const string &s);
public:
	
//Constructors
	Agenda();

//Destructor
	~Agenda();

//Modificadors
	/** @brief 
    \pre: p.e. c conte la informacio per a crear una tasca
    \post: b = true map<Data,Tasca> m conte una tasca nova
    		b = false la tasca no s'ha afegit
    */
    void apuntar_tasca(Comanda &c, bool &b);
    
    /** @brief 
    \pre: p.e. c conte la informacio per a modificar una tasca
    \post: es modifica una tasca de map<Data,Tasca> m*/
	void modificar_tasca(Comanda &c);

	 /** @brief 
    \pre: p.e. conte informacio per a esborrar una tasca 
    		map<Data,Tasca> m no buit
    \post: s'esborra una i nomes una tasca de map<Data,Tasca> m si hi es*/
	void esborrar_tasca(Comanda &c);

	 /** @brief 
    \pre: p.e. c conte la informacio per a modificar una tasca
    \post: es modifica una tasca de map<Data,Tasca>*/
	void modificar_rellotge(const string data, const string hora, bool &be);

//Consultors
	 /** @brief 
    \pre: p.i. no buit
    \post: el vector menu conte tasques seleccionades segons indica el p.e. c
    		s'escriu el vector menu*/
	void consulta(Comanda &c);

	 /** @brief 
    \pre: p.i. no buit
    \post: el vector menu conte les tasques passades*/
	void consulta_passat();
	
	 /** @brief 
    \pre: p.i. no buit
    \post: la hora interna s'escriu*/
	void consulta_rellotge() const;

};
#endif


