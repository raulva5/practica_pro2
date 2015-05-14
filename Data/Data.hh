/** @file Data.hh
    @brief Classe Data
 */

#ifndef DATA_HH
#define DATA_HH
#include <exception>
#include <iostream>
#include <string>
using namespace std;
/** @class Dat
    @brief Representa la data i hora d'una tasca, ens permet llegir i consultar la data i/o l'hora de la tasca
 */

class Data {

private:
	int dia;
	int mes;
	int any;
	int minut;
	int hora;
    bool valid;

    void validar_data();
    void str_to_data(const string &d);
    void str_to_hora(const string &h);
public:
// Constructores
    Data();
    Data(const string &d, const string &h);
//Destructores
    ~Data();

// Modificadores
    /** @brief 
    \pre: String d format: dd.mm.aa, String h format: hh:mm
    \post: el p.i. te la data i hora especificades*/
    void modificar_data_hora(const string &d, const string &h);
    void modificar_data(const string &d);
    void modificar_hora(const string &h);

// Consultores
    string consultar_data() const;
    string consultar_hora() const;
    
//Llegir/Escriure
    
    /** @brief 
    \pre: p.i. no buit
    \post: imprimeix per consola la data del p.i.*/
    void escriure_data();

//Operadors
    bool operator==(const Data& d);
    bool operator!=(const Data& d);
    bool operator<=(const Data& d);
    bool operator<(const Data& d);
    bool operator>=(const Data& d);
    bool operator>(const Data& d);
};

#endif
