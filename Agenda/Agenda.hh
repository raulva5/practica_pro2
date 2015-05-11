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

/** @class Agenda
    @brief Representa una agenda.
*/

class Agenda {
private:
	Data rellotge;
	map<Data,Tasca> m;
	vector<Data> menu;

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
    \post: map<Data,Tasca> m conte una tasca nova*/
    void apuntar_tasca(const Comanda &c);
    
    /** @brief 
    \pre: p.e. c conte la informacio per a modificar una tasca
    \post: es modifica una tasca de map<Data,Tasca> m*/
	void modificar_tasca(const Comanda &c);

	 /** @brief 
    \pre: p.e. conte informacio per a esborrar una tasca 
    		map<Data,Tasca> m no buit
    \post: s'esborra una i nomes una tasca de map<Data,Tasca> m si hi es*/
	void esborrar_tasca(const Comanda &c);

	 /** @brief 
    \pre: segons especifiqui p.e. c, la funcio modificara o llegira el rellotge
    \post: segons c*/
	void tractar_rellotge(const Comanda &c);

	 /** @brief 
    \pre: p.e. c conte la informacio per a modificar una tasca
    \post: es modifica una tasca de map<Data,Tasca>*/
	void modificar_rellotge(const Data &d);

//Consultors
	 /** @brief 
    \pre: p.i. no buit
    \post: el vector menu conte tasques seleccionades segons indica el p.e. c
    		s'escriu el vector menu*/
	void consulta(const Comanda &c);

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


