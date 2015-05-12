/** @file Tasca.hh
    @brief Classe Tasca
 */

#ifndef TASCA_HH
#define TASCA_HH

#include <exception>
#include <iostream>
#include <string>
#include <map>
using namespace std;
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
    Tasca(string &t);

//Destructor
    ~Tasca();
    
// Modificadores
    /** @brief 
    \pre: p.e. t no buit
    \post: titol = t*/
    void modificar_titol(string &t);

    /** @brief 
    \pre: p.e. e no buit
    \post: safegeix un element a map<string,bool> etiq*/
    void afegir_etiqueta(string &e);

    /** @brief 
    \pre: p.e. e no buit
    \post: l'etiqueta amb nom e...
        b = true s'esborra
        b = false si no s'esborra*/
    void esborrar_etiqueta(string &e, bool &b);
    
// Consultores
    /** @brief 
    \pre: p.i. no buit
    \post: retorna el titol del p.i.*/
    string consulta_titol() const;
    
//Lector / Escritor
    /** @brief 
    \pre: p.i. conte etiquetes
    \post: s'escriuen totes les etiquetes ordenades alfabeticament*/
    void escribir_etiquetes() const;
};

#endif
