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
    string llegir_paraula(const string &s, int &i);
public:
 // Constructores
    /** @brief Constructora per defecte*/
    Tasca();
    /** @brief Constructora amb titol*/
    Tasca(const string &t);

//Destructor
    /** @brief Destructora per defecte*/
    ~Tasca();
    
// Modificadores
    /** @brief Modifica el titol
    \pre: t no buit
    \post: titol = t*/
    void modificar_titol(const string &t);

    /** @brief Afegeix una etiqueta
    \pre: e no buit
    \post: s'afegeix una etiqueta a etiq */
    void afegir_etiqueta(const string &e);

    /** @brief S'esborra l'etiqueta e
    \pre: e no buit
    \post: b = true s'esborra l'etiqueta amb nom e
           b = false no s'ha esborrat cap etiqueta*/
    void esborrar_etiqueta(const string &e, bool &b);

    /** @brief S'esborren totes les etiquetes
    \pre: cert
    \post: etiq es buit*/
    void esborrar_etiquetes();
    
// Consultores
    
    /** @brief Consulta el titol
    \pre: cert
    \post: retorna el titol */
    string consulta_titol() const;
    
    /** @brief Comprova si te l'etiqueta e
    \pre: e no buit
    \post: retorna true etiq conte e, false altrament*/
    bool te_etiqueta(const string &e) const;

    /** @brief Comprova si compleix l'expressio
    \pre:   expressio[i] = "(" que indica l'inici d'una expressio / subexpressio
    \post:  expressio[i] = ('.',',') o bé final d'expressio / subexpressio
            retorna true si compleix l'expressio / subexpressio, false altrament*/
    bool expressio(const string &expressio, int &i);
    
//Lector / Escritor
    /** @brief Imprimeix totes les etiquetes
    \pre: cert
    \post: s'escriuen totes les etiquetes ordenades alfabeticament*/
    void escriure_etiquetes() const;
};

#endif
