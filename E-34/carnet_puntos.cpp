//PABLO AGUDO BRUN	

#include <iostream>
//PABLO AGUDO BRUN

#include "carnet_puntos.h"

using namespace std;


carnet_puntos::carnet_puntos(){
	listaPuntosTotal = std::vector<int>(16, 0);
}

//anade un nuevo conductor identicado por su dni, con 15 puntos
void carnet_puntos::nuevo(std::string DNI){
	it = mapConductores.find(DNI);

	//si el conductor ya existe lanza una excepcion
	if (it != mapConductores.end()) {
		throw std::domain_error("Conductor duplicado");
	}
	else { //en caso contrario se anade al nuevo conductor con 15 puntos
		mapConductores[DNI] = 15;
		mapPunteros[DNI] = 15;
		listaPuntosTotal[15] ++;
	}
}

void carnet_puntos::quitar(std::string DNI, int punt){
	it = mapConductores.find(DNI);

	//si el conductor no existe se lanza excepcion
	if (it == mapConductores.end()) {
		throw std::domain_error("Conductor inexistente");
	}
	else { //en caso contrario se le restan los puntos al conductor
		int aux = mapConductores[DNI] - punt;

		if (aux < 0) { //si a un conductor se le quitan mas puntos de los que tiene, se quedara con 0 puntos.
			mapConductores[DNI] = 0;
			mapPunteros[DNI] = 0;
			listaPuntosTotal[0] ++;
		}
		else { //aux >= 0
			listaPuntosTotal[mapPunteros[DNI]] --;
			listaPuntosTotal[aux] ++;
			mapConductores[DNI] = aux;
			mapPunteros[DNI] = aux;
		}
	}
}
//devuelve los puntos actuales de un conductor
int carnet_puntos::consultar(std::string DNI){
	it = mapConductores.find(DNI);
	int puntos;

	//si el conductor no existe se lanza excepcion
	if (it == mapConductores.end()) {
		throw std::domain_error("Conductor inexistente");
	}
	else {
		puntos = mapConductores[DNI];
	}

	return puntos;
}

//devuelve cuantos conductores tienen un determinado numero de puntos
int carnet_puntos::cuantos_con_puntos(int punt){
	int numCond;

	//si los puntos no estan comprendidos entre 0 y 15 se lanza excepcion
	if (punt < 0 || punt > 15) {
		throw std::domain_error("Puntos no validos");
	}
	else {
		numCond = listaPuntosTotal[punt];
	}

	return numCond;
}

