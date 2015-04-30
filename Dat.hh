/** @file Dat.hh
    @brief Classe Dat
 */

#ifndef DAT_HH
#define DAT_HH
#include "../utils.cc"
#include "../DAT/Dat.hh"

/** @class Dat
    @brief Representa la data i hora d'una tasca, ens permet llegir i consultar la data i/o l'hora de la tasca
 
 */
class Dat {

public:
	int dia;
	int mes;
	int anyo;
	int minutos;
	int hora;

private:
 // Constructores
    
    Dat();
     
    void llegir_rellotge();
    // Modificadores
     /** @brief 
    \pre 
    \post */
     void modificar_rellotge(string& data,string& hora);
     void modificar_data(string& data);
     void modificar_hora(string& hora);
    
    
    // Consultores
    /** @brief 
    \pre: 
    \post: */
    void consultar_rellotge();
    void consultar_data();
    void consultar_hora();

    
};

#endif
