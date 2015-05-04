/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH
#include "../utils.cc"
#include "../Data/Data.hh"
#include "../Tasca/Tasca.hh"
#include "../Comanda/Comanda.hh"

/** @class Agenda
    @brief Representa una agenda.
*/

class Agenda {
private:
	Data rellotge; // rellotge intern
	map<Data,Tasca> m; 	//m conte totes les tasques de l'agenda
						//Ordenades cronologicament
	vector<Data> v; //v conte la data de les tasques consultades

public:
	
  //Constructors
	Agenda();

  //Destructor
	~Agenda();

  //Modificadors
    //Tasques
    void apuntar_tasca(const Comanda &c);
	void modificar_tasca(const Comanda &c);
	void esborrar_tasca(const Comanda &c);

	void tractar_rellotge(const Comanda &c);
	void modificar_rellotge(const Data &d);

  //Consultors
	void consulta(const Comanda &c);
	void consulta_data(Data d1, Data d2);
	void consulta_etiqueta(vector<string> &e);
	void consulta_expressio(string s);
	
	void consulta_passat();
	
	void consulta_rellotge();

};
#endif


