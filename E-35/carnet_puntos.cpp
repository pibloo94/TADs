//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "carnet_puntos.h"

using namespace std;


//annade un nuevo conductor identicado por su dni(un string), con 15 puntos.
void carnet_puntos::nuevo(std::string DNI){
	auto
	//En caso de que el DNI este duplicado, la operacion lanza una excepcion 
}

//le resta puntos a un conductor tras una infraccion. 
void carnet_puntos::quitar(std::string DNI, int puntos){
	//Si a un conductor se le quitan mas puntos de los que tiene, se quedara con 0 puntos.
	
	//En caso de que el conductor no exista, lanza una excepcion
}

//le anade puntos a un conductor enmendado.
void carnet_puntos::recuperar(std::string DNI, int puntos){
	//Si debido a una recuperacion un conductor supera los 15 puntos, se quedara con 15 puntos.
	
	//En caso de que el conductor no exista, lanza una excepcion
}

//devuelve los puntos actuales de un conductor. 
int carnet_puntos::consultar(std::string DNI){
	//En caso de que el conductor no exista, lanza una excepcion

	return 0;
}

//devuelve cuantos conductores tienen un determinado numero de puntos.
std::vector<int> carnet_puntos::cuantos_con_puntos(int puntos){
	//En caso de que el numero de puntos no este entre 0 y 15 lanza una excepcion

	return std::vector<int>();
}

//produce una lista con los DNI de los conductores que poseen un numero determinado de puntos.
std::vector<std::string> carnet_puntos::listar_por_puntos(){
	//La lista estara ordenada por el momento en el que el conductor paso a tener esos puntos, primero el que menos tiempo lleva con esos puntos.
	
	//En caso de que el numero de puntos no este entre 0 y 15 lanza una excepcion
	return std::vector<std::string>();
}
