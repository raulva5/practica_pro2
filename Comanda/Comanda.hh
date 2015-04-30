/** @file comanda.hh
    @brief Classe Comanda
 */

#ifndef COMANDA_HH
#define COMANDA_HH

#include <sstream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <iostream>
#include "token.hh"
using namespace std;

/** @class Comanda
    @brief Representa una comanda (lÃ­nia de text d'entrada).
 El mÃ¨tode llegir permet utilitzar consultores sobre la comanda llegida i comprovar
 que no tingui errors sintÃ ctics.
 */
class Comanda {

private:
    static const int MAX_i_data = 2;
    
    vector<Token> e;
    int mida;

    bool e_insercio;
    bool e_consulta;
    bool e_passat;
    bool e_modificacio;
    bool e_rellotge;
    bool e_esborrat;
    bool e_acabament;

    int  n_dates;
    vector<string> i_data;

    bool t_hora;
    string i_hora;
    
    bool t_titol;
    string i_titol;
    
    int  n_etiquetes;
    vector<string> i_etiqueta;
    
    bool t_expressio;
    string i_expressio;
    
    string i_esborrat;
    
    int i_tasca;
    
    bool error;
    
    // inicialitzar atributs de la comanda
    void iniciar();
    
    void anotar_titol(int& i);
    
    void anotar_hora(int& i);
    
    void anotar_data(int& i);
    
    void anotar_etiqueta(int& i);
    
    void anotar_temps(int& i);
    
    void afegir_elements();
    
    void tractar_insercio();

    void tractar_consulta();
    
    void tractar_consulta_rapida(bool& el_que_sigui);
    
    void tractar_modificacio();
    
    void tractar_esborrat_parcial();
    
    void tractar_esborrat_tasca();
    
    void fixar_temps_rellotge();
    
public:
    // Constructores
    
    Comanda();
    
    // Modificadores
    
    /** @brief Llegeix una comanda (lÃ­nia de text d'entrada) i actualitza la informaciÃ³ interna perquÃ¨ funcionin bÃ© les consultores
    \pre cert
    \post si s'ha llegit una comanda sense errors sintÃ ctics, be = cert i s'escriu la comanda; si la comanda tÃ© errors sintÃ ctics, be = fals i s'escriu "Error de format"; retorna cert quan la comanda no Ã©s "sortir" */
    bool llegir(bool& be);
    
    // Consultores
    
    /** @brief Comprova si la comanda Ã©s una inserciÃ³ ("+" Ã©s el primer string)
    \pre: cert
    \post: cert si Ã©s una inserciÃ³ */
    bool es_insercio();
    
    /** @brief Comprova si la comanda Ã©s una consulta ("?", "passat?" o "rellotge?" Ã©s el primer string)
    \pre cert
    \post cert si Ã©s una consulta */
    bool es_consulta();
    
    /** @brief Comprova si la comanda Ã©s una consulta del passat ("passat?" Ã©s el primer string)
    \pre cert
    \post cert si Ã©s una consulta sobre el passat */
    bool es_passat();
    
    /** @brief Comprova si la comanda Ã©s una modificaciÃ³ (el primer string Ã©s un enter, perÃ² el segon no comenÃ§a per "-")
    \pre cert
    \post cert si Ã©s una modificaciÃ³ */
    bool es_modificacio();
    
    /** @brief Comprova si la comanda Ã©s sobre el rellotge (el primer string Ã©s "rellotge" o "rellotge?")
    \pre cert
    \post cert si la comanda Ã©s una consulta sobre el rellotge o una modificaciÃ³ del 
     temps del rellotge */
    bool es_rellotge();
    
    /** @brief Comprova si la comanda Ã©s d'esborrat (comenÃ§a per "-k" o per "k -x", on k Ã©s un enter)
    \pre cert
    \post cert si Ã©s un esborrat */
    bool es_esborrat();
    
    /** @brief Consulta el tipus d'esborrat
    \pre la comanda Ã©s d'esborrat
    \post retorna el tipus d'esborrat: "etiquetes" (si cal esborrar totes les etiquetes), "etiqueta" (si cal esborrar-ne una) o "tasca" (si cal esborrar la tasca) */
    string tipus_esborrat();
    
    /** @brief Consulta el nombre de dates contingudes en la comanda
    \pre cert
    \post retorna el nombre de dates proporcionades en la comanda (0, 1 o 2) */
    int  nombre_dates();
    
    /** @brief Consulta una data individual de la comanda
    \pre 1 <= i <= nombre_dates()
    \post retorna la data i-Ã¨sima de la comanda */
    string data(int i);
    
    /** @brief Comprova si la comanda contÃ© hora
    \pre cert
    \post cert si la comanda contÃ© hora */
    bool te_hora();
    
    /** @brief Consulta l'hora de la comanda
    \pre la comanda contÃ© hora
    \post retorna l'hora continguda en la comanda */
    string hora();
    
    /** @brief Comprova si la comanda contÃ© un tÃ­tol (una seqÃ¼Ã¨ncia de paraules, Ã©s a dir, strings que comencen per una lletra i no contenen ni "." ni "," ni ":" ni "#")
    \pre cert
    \post retorna cert si la comanda contÃ© un tÃ­tol */
    bool te_titol();
    
    /** @brief Consulta el tÃ­tol de la comanda
    \pre Ã©s una inserciÃ³ o Ã©s una modificaciÃ³ amb tÃ­tol
    \post retorna el tÃ­tol contingut en la comanda */
    string titol();
    
    /** @brief Consulta el nombre d'etiquetes de la comanda (strings que comencen per # seguit d'una paraula)
    \pre cert
    \post retorna el nombre d'etiquetes contingudes en la comanda */
    int nombre_etiquetes();
    
    /** @brief Consulta una etiqueta de la comanda
    \pre 1 <= i <= nombre_etiquetes()
    \post retorna l'etiqueta i-Ã¨sima de la comanda */
    string etiqueta(int i);
    
    /** @brief Consulta la presÃ¨ncia d'una expressiÃ³ booleana d'etiquetes en la comanda, Ã©s a dir, una expressiÃ³ ben parentitzada, on els operadors sÃ³n "," (disjunciÃ³ binÃ ria) i "." (conjunciÃ³ binÃ ria) i els operands sÃ³n etiquetes
    \pre cert
    \post cert si la comanda contÃ© una expressiÃ³ booleana d'etiquetes */
    bool te_expressio();

    /** @brief Consulta una expressiÃ³ d'etiquetes
    \pre la comanda contÃ© una expressiÃ³ d'etiquetes
    \post retorna l'expressio booleana d'etiquetes continguda en la comanda */
    string expressio();
    
    /** @brief Consulta el nÃºmero de tasca que hi ha a la comanda
    \pre la comanda Ã©s un esborrat o una modificaciÃ³
    \post retorna el nÃºmero de tasca de l'operaciÃ³ continguda en la comanda */
    int tasca();
};

#endif