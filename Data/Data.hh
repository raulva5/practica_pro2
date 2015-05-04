/** @file Data.hh
    @brief Classe Data
 */

#ifndef DATA_HH
#define DATA_HH
#include "../utils.cc"

/** @class Dat
    @brief Representa la data i hora d'una tasca, ens permet llegir i consultar la data i/o l'hora de la tasca
 
 */
class Data {

public:
	int dia;
	int mes;
	int anyo;
	int minutos;
	int hora;

private:
 // Constructores   
    Data();
    
    /** @brief 
    \PRE: 
    \POST:  */
    Data(string &data, string &hora);

//Destructores
    ~Data();

// Modificadores
    
    
    
    
// Consultores

    /*POST: v[0] = data, v[1] = hora*/
    vector<string> convert_data_to_string(const Data &d);
    Data convert_string_to_data(const string &d);
    
    /** @brief 
    \pre: 
    \post: */
    bool less_than(Data &d1, Data &d2);
    bool less_equal(Data &d1, Data &d2);
    
};

#endif
