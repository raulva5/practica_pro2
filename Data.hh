/** @file Data.hh
    @brief Classe Data
 */

#ifndef DATA_HH
#define DATA_HH
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
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

    void str_to_data(const string &d);
    void str_to_hora(const string &h);
public:
    // Constructores
    /** @brief Constructora per defecte*/
    Data();
    /** @brief Constructora amb hora i data*/
    Data(const string &d, const string &h);
    
    //Destructores
    /** @brief Destructora per defecte*/
    ~Data();

    // Modificadores
    
    /** @brief Modifica dia, mes, any, minut i hora
    \pre: d té el format "DD.MM.YY", h te el format "HH.MM"
    \post: ha modificat dia, mes, any, minut, hora */
    void modificar_data_hora(const string &d, const string &h);
    
    /** @brief Modifica dia, mes i any
    \pre: d té el format "DD.MM.YY"
    \post: ha modificat dia, mes i any */
    void modificar_data(const string &d);

    /** @brief Modifica hora i minut
    \pre: d té el format "HH:MM"
    \post: ha modificat hora i minut */
    void modificar_hora(const string &h);

    /** @brief Copia la data del p.e.
    \pre: d no buit
    \post: S'ha copiat any, mes, dia de d al p.i. */
    void copiar_data(const Data d);

    /** @brief Copia la hora del p.e.
    \pre: d no buit
    \post: S'ha copiat hora i minut de d al p.i. */
    void copiar_hora(const Data d);

    //Llegir/Escriure
    
    /** @brief 
    \pre: p.i. no buit
    \post: imprimeix per consola la data del p.i. amb format "DD.MM.YY HH:MM */
    void escriure_data() const;

    //Operadors
    bool operator==(const Data& d) const;
    bool operator!=(const Data& d) const;
    bool operator<=(const Data& d) const;
    bool operator<(const Data& d) const;
    bool operator>=(const Data& d) const;
    bool operator>(const Data& d) const;
};

#endif
