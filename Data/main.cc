#include "Data.hh"
#include <iostream>
#include <string>

int main(){
	
	string data1 = "07.04.04";
	string hora1 = "23:32";
	Data d1;
	d1.modificar_data_hora(data1, hora1);
	cout << "d1 ";
	d1.escriure_data();
	cout << endl;

	string data2 = "04.04.04";
	string hora2 = "57:22";
	Data d2(data2, hora2);
	
	cout << "d2 ";
	d2.escriure_data();
	cout << endl;

	if(d1 < d2) cout << "d1 < d2" << endl;
	if(d1 <= d2) cout << "d1 <= d2" << endl;
	if(d1 > d2) cout << "d1 > d2" << endl;
	if(d1 >= d2) cout << "d1 >= d2" << endl;
	if(d1 == d2) cout << "d1 == d2" << endl;
	if(d1 != d2) cout << "d1 != d2" << endl;

	hora1 = "21:54";
	d1.modificar_hora(hora1);
	d1.escriure_data();
	cout << endl;
	data1 = "10.11.05";
	d1.modificar_data(data1);
	d1.escriure_data();
	cout << endl;

	cout << "COPIES HORA/DATA" << endl;
	d1.copiar_data(d2);
	d1.escriure_data();
	cout << endl;
	d1.copiar_hora(d2);
	d1.escriure_data();
	cout << endl;
}