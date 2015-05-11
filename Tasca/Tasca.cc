#include "Tasca.hh"


/* Constructores */
Tasca::Tasca()
{	
	etiq = map<string,bool>;
	pair<std::map<string,int>::iterator,bool> it;
	pair<std::map<string,int>::const_iterator,bool> it2 = etiq.begin();
	// para saber podemos decir que if(it2 != it) si tiene etiquetas
}

Tasca::Tasca(string &t)
{
    	etiq = map<string,bool>;
	pair<std::map<string,int>::iterator,bool> it;
	pair<std::map<string,int>::const_iterator,bool> it2 = etiq.begin();
	// para saber podemos decir que if(it2 != it) si tiene etiquetas
	 this->titol = t;
    
}
//Destructor
    ~Tasca();
    
// Modificadores

void Tasca::modificar_titol(const string &t) {
	this->titol = t;
}

void Tasca::afegir_etiqueta(const string &e) 
{
	
	if (etiq.empty) etiq.insert(e,true);
	else {
		this -> it = etiq.insert(make_pair(e,true));
		/*
		if (this -> it.second) cout << "Se ha insertado correctamente" << endl; 
		else { 
			cout << "No se ha podido insertar, porque hay un elemento con la " << 
			"misma clave." << endl; 
		} 
		*/
	}
}
 
void Tasca::esborrar_etiqueta(const string &e, bool &b)  
{
    
	this->it2 = etiq.find(e);
	if (it2 != etiq.end()) b = true;
    else {
		b = false;
		cout << "No s'ha realitzat" << endl; 
	}
}
// Consultores

string Tasca::consulta_titol() const 
{
    return this->titol;
}
//Lector / Escritor
void Tasca::escribir_etiquetes() const 
{
	for (auto it = etiq.cbegin(); it != etiq.cend(); ++it) {
		cout << " #" << (*it).first;
    }
}
};
