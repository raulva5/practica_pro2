/** @file Tasca.hh
    @brief Classe Tasca
 */

#ifndef TASCA_HH
#define TASCA_HH
#include "../utils.cc"

/** @class Tasca
    @brief Representa el títol de la tasca , la/es etiqueta/es
 
 */
class Tasca {

public:
	string titol;
    map<string,bool> etiq; // mapa que ens representa les etiquetes ordenades en cas de que hi hagi més d'una

private:
 // Constructores
    
    Tasca();
    Tasca(string &t);
//Destructor
    ~Tasca();
    // Modificadores
    void modificar_titol(string &t);

    void afegir_etiqueta(string &e);
    void esborrar_etiqueta(string &e);
    
    void sorter_etiquetes();
    // Consultores
    map<string, bool> consulta_etiquetes();
    string consulta_titol();    
};

#endif
