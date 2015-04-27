/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH
#include "../utils.cc"

/** @class Agenda
    @brief Representa una agenda.
 */
class Agenda {
private:

public:
	/* Està posat a tot arreu "int i" però faltarà determinar els paràmetres finals*/
	
  //Constructors
	Agenda();

  //Modificadors
    //Tasques
    void apuntar_tasca(int i);
	void modificar_tasca(int i);
	void esborrar_tasca(int i);
  	

  	//Rellotge
	void canviar_hora();
	void canviar_data();
	bool data_posterior();


  //Consultors
	void consultar_tasca(int i);


};
#endif

