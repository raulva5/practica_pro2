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
    void apuntar_tasca(const Comanda &c);
	void modificar_tasca(const Comanda &c);
	void esborrar_tasca(const Comanda &c);

	void tractar_rellotge(const Comanda &c);
	void modificar_rellotge(const Data &d);

//Consultors
	void consulta(const Comanda &c);
	void consulta_passat();
	
	void consulta_rellotge() const;

};
#endif


