#include "utils.cc"
#include "./Comanda/Comanda.hh"

int main() {

Comanda c;
bool be;
	while(c.llegir(be)){
		if(!be) cout << "Error de format" << endl;
	}

}
cout << "Has sortit" << endl;
