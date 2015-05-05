/** @file Data.hh
    @brief Classe Data
 */

#ifndef DATA_HH
#define DATA_HH

#include <exception>
#include <iostream>
#include <string>

/** @class Dat
    @brief Representa la data i hora d'una tasca, ens permet llegir i consultar la data i/o l'hora de la tasca
 */

class Data {

private:
	int dia;
	int mes;
	int anyo;
	int minutos;
	int hora;

public:
// Constructores   
    Data();
    
    /** @brief 
    \PRE: 
    \POST:  */

//Destructores
    ~Data();

// Modificadores
    
    
    
    
// Consultores

    /*POST: v[0] = data, v[1] = hora*/
    void escribir_data() const;
    
//Lector / Escritor
    void convert_str_to_data(const string &d);
    
    /** @brief 
    \pre: 
    \post: */
    
    
};

#endif
