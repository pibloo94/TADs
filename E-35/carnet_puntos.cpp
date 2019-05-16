//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "carnet_puntos.h"

using namespace std;

//constructor
carnet_puntos::carnet_puntos() {
	listaPuntos = std::vector<int>(16, 0);
}

//anade un nuevo conductor identicado por su dni(un string), con 15 puntos.
void carnet_puntos::nuevo(std::string DNI) {
	auto it = mapConductores.find(DNI);
	//En caso de que el DNI este duplicado, la operacion lanza una excepcion 
	if (it != mapConductores.end()) {
		throw domain_error("Conductor duplicado");
	}
	else {
		mapConductores[DNI] = 15;
		listaPuntos[15] ++;
		mapConductoresPorPuntos[15].push_front(DNI);
		mapIteradores[DNI] = mapConductoresPorPuntos[15].begin();
	}
}

//le resta puntos a un conductor tras una infraccion. 
void carnet_puntos::quitar(std::string DNI, int puntos) {
	auto it = mapConductores.find(DNI);

	//Si el conductor existe
	if (it != mapConductores.end()) {
		//Si a un conductor se le quitan mas puntos de los que tiene, se quedara con 0 puntos.
		int aux = mapConductores[DNI] - puntos;

		if (it->second != 0) {
			if (aux < 0) {
				listaPuntos[mapConductores[DNI]]--;
				mapConductoresPorPuntos[it->second].erase(mapIteradores[DNI]);
				mapConductoresPorPuntos[0].push_front(DNI);
				mapIteradores.erase(DNI);
				mapIteradores[DNI] = mapConductoresPorPuntos[0].begin();
				mapConductores[DNI] = 0;
				listaPuntos[0] ++;
			}
			else {
				listaPuntos[mapConductores[DNI]]--;
				mapConductoresPorPuntos[it->second].erase(mapIteradores[DNI]);
				mapConductoresPorPuntos[puntos].push_front(DNI);
				mapIteradores.erase(DNI);
				mapIteradores[DNI] = mapConductoresPorPuntos[puntos].begin();
				mapConductores[DNI] = aux;
				listaPuntos[aux] ++;
			}
		}
	}
	//En caso de que el conductor no exista, lanza una excepcion
	else {
		throw domain_error("Conductor inexistente");
	}
}

//le anade puntos a un conductor enmendado.
void carnet_puntos::recuperar(std::string DNI, int puntos) {
	auto it = mapConductores.find(DNI);
	
	if (it != mapConductores.end()) {
		int aux = it->second + puntos;

		//Si debido a una recuperacion un conductor supera los 15 puntos, se quedara con 15 puntos.
		if(it->second != 15){
			if (aux < 15) {
				listaPuntos[it->second] --;
				mapConductoresPorPuntos[it->second].erase(mapIteradores[DNI]);
				mapIteradores.erase(DNI);
				mapIteradores[DNI] = mapConductoresPorPuntos[puntos].begin();
				mapConductores[DNI] = aux;
				listaPuntos[aux] ++;
			}
		}
	}
	//En caso de que el conductor no exista, lanza una excepcion
	else {
		throw domain_error("Conductor inexistente");
	}
}

//devuelve los puntos actuales de un conductor. 
int carnet_puntos::consultar(std::string DNI) {
	auto it = mapConductores.find(DNI);
	int punt;

	//En caso de que el conductor no exista, lanza una excepcion
	if (it == mapConductores.end()) {
		throw domain_error("Conductor inexistente");
	}
	else {
		punt = mapConductores[DNI];
	}

	return punt;
}

//devuelve cuantos conductores tienen un determinado numero de puntos.
int carnet_puntos::cuantos_con_puntos(int puntos) {
	int cuantos;

	//En caso de que el numero de puntos no este entre 0 y 15 lanza una excepcion
	if (puntos < 0 || puntos > 15) {
		throw domain_error("Puntos no validos");
	}
	else {
		cuantos = listaPuntos[puntos];
	}

	return cuantos;
}

//produce una lista con los DNI de los conductores que poseen un numero determinado de puntos.
std::vector<std::string> carnet_puntos::lista_por_puntos(int puntos) {
	//La lista estara ordenada por el momento en el que el conductor paso a tener esos puntos, primero el que menos tiempo lleva con esos puntos.
	std::vector<std::string> lista;

	//En caso de que el numero de puntos no este entre 0 y 15 lanza una excepcion
	if (puntos < 0 || puntos > 15) {
		throw domain_error("Puntos no validos");
	}
	else {
		for (auto& it : mapConductoresPorPuntos[puntos]) {
			lista.push_back(it);
		}
	}
	return lista;
}