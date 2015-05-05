/** @file Tasca.hh
    @brief Classe Tasca
 */

#ifndef TASCA_HH
#define TASCA_HH

#include <exception>
#include <iostream>
#include <string>
#include <map>

/** @class Tasca
    @brief Representa el títol de la tasca i la/es etiqueta/es
 */
class Tasca {

private:
	string titol;
    map<string,bool> etiq;

public:
 // Constructores
    Tasca();
    Tasca(const string &t);

//Destructor
    ~Tasca();
    
// Modificadores
    void modificar_titol(const string &t);
    void afegir_etiqueta(const string &e);
    void esborrar_etiqueta(const string &e, bool &b);
    
// Consultores
    string consulta_titol() const;
    
//Lector / Escritor
    void escribir_etiquetes() const;
};

#endif
