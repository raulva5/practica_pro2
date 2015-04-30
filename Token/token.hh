/** @file token.hh
    @brief Classe Token
 */

#ifndef TOKEN_HH
#define TOKEN_HH

#include <string>
#include "stdlib.h"
#include <iostream>
using namespace std;

/** @class Token
    @brief Representa un string rellevant per a la classe Comanda.
 */

class Token {

private:
    string m;
    bool nombre;
    bool text;
    bool etiqueta;
    bool hora;
    bool data;
    bool expressio;
    bool esborrat;
    string t_esborrat;
    bool consulta;
    
    bool error;
    
    static bool es_digit(const char& c);
    static bool es_nombre(string& s);
    static bool es_lletra(const char& c);
    void es_paraula(string& p);
    void tractar_hora();
    void tractar_data();
    static void llegir_etiqueta(string& s, int& i);
    void tractar_expressio();
    void iniciar();

public:
    
    // Constructores
    
    Token();
    
    /** @brief Fa el tractament d'una string actualitzant la informaciÃ³ interna perquÃ¨ funcionin bÃ© les consultores
     \pre cert
     \post be = cert si i nomÃ©s si s Ã©s un string vÃ lid que pot formar part d'una comanda; quan be = cert, s'ha creat un objecte Token sobre el qual es poden fer consultes */
    Token(const string& s, bool& be); // assigna s a m i actualitza atributs

    // Consultores
    
    /** @brief Consulta l'string contingut en el p.i.
     \pre cert
     \post retorna l'string contingut en el p.i. */
    string cos();
    
    /** @brief Comprova si Ã©s un nombre (seqÃ¼Ã¨ncia de dÃ­gits no buida)
     \pre cert
     \post cert si el p.i. contÃ© un nombre */
    bool es_nombre();
    
    /** @brief Comprova si Ã©s una paraula (seqÃ¼Ã¨ncia de sÃ­mbols que comenÃ§a per una lletra i no contÃ© ni "." ni "," ni ":" ni "#")
     \pre cert
     \post cert si el p.i. contÃ© una paraula */
    bool es_text();
    
    /** @brief Comprova si Ã©s una etiqueta (sÃ­mbol # seguit d'una paraula)
     \pre cert
     \post cert si el p.i. contÃ© una etiqueta */
    bool es_etiqueta();
    
    /** @brief Comprova si Ã©s una hora (amb format **:**, on * Ã©s un dÃ­git)
     \pre cert
     \post cert si el p.i. contÃ© una hora */
    bool es_hora();
    
    /** @brief Comprova si Ã©s una data (amb format **.**.**, on * Ã©s un dÃ­git)
     \pre cert
     \post cert si el p.i. contÃ© una data */
    bool es_data();
    
    /** @brief Comprova si Ã©s una expressiÃ³ booleana d'etiquetes (ben parentitzada, on els operadors sÃ³n "," (disjunciÃ³ binÃ ria) i "." (conjunciÃ³ binÃ ria) i els operands sÃ³n etiquetes) 
     \pre cert
     \post cert si el p.i. contÃ© una expressiÃ³ booleana d'etiquetes */
    bool es_expressio();
    
    /** @brief Comprova si Ã©s un esborrat (una seqÃ¼Ã¨ncia de sÃ­mbols que comenÃ§a per "-")
     \pre cert
     \post cert si el p.i. Ã©s un esborrat */
    bool es_esborrat();
     
    /** @brief Consulta el tipus d'esborrat
     \pre el p.i. Ã©s un esborrat
     \post retorna "etiqueta" si el p.i. contÃ© una etiqueta desprÃ©s del sÃ­mbol "-", "etiquetes" si contÃ© l'string "etiquetes" desprÃ©s de "-", i "tasca" si contÃ© un nombre desprÃ©s de "-" */
    string tipus_esborrat();
    
    /** @brief Comprova si Ã©s una consulta ("?" o "passat?" o "rellotge?")
     \pre el p.i. Ã©s una consulta
     \post cert si el p.i. Ã©s una consulta */
    bool es_consulta(); // retorna consulta
    
};

#endif