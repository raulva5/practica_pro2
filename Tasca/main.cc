#include "Tasca.hh"
#include <iostream>
#include <string>

int main(){
	Tasca t1;
	t1.modificar_titol("Tasca1");
	
	t1.consulta_titol();
	
	Tasca t2("Tasca2");
	t2.consulta_titol();
	bool be = false;
	t1.afegir_etiqueta("asu", be);
	t1.afegir_etiqueta("tabla", be);
	t1.afegir_etiqueta("ste", be);
	t1.afegir_etiqueta("paco", be);


	t2.afegir_etiqueta("paco", be);
	t2.afegir_etiqueta("paco", be);
	if(!be)  cout << "Paco no afegit" << endl;
	t2.afegir_etiqueta("hfer", be);
	t2.afegir_etiqueta("tuto", be);
	t2.afegir_etiqueta("josefina", be);

	cout << "PROVA ESBORRAR ETIQUETA:" << endl;
	bool b = false;
	t2.esborrar_etiqueta("paco", b);
	if(b) cout << "paco borrat" << endl;


	t1.esborrar_etiqueta("jasdjasd", b);
	if(b) cout << "jasdjasd borrat" << endl;



	cout << "ETIQ1" << endl;
	t1.escribir_etiquetes();
	cout << endl << "ETIQ2" << endl;
	t2.escribir_etiquetes();


	cout << "CONSULTA ETIQUETA" << endl;
	if(t1.te_etiqueta("paco")) cout << "paco TROBADA" << endl;
	if(t1.te_etiqueta("jose")) cout << "jose TROBADA" << endl;

}