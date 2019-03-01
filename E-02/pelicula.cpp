#include "pelicula.h"
#include "horario.h"

#include <iostream>
#include <string>

using namespace std;

pelicula::pelicula(horario ini, horario dur, std::string n) {
	inicio = ini;
	duracion = dur;
	nombre = n;
	fin = ini + dur;
}

pelicula::pelicula() {}

pelicula::~pelicula() {}

std::string pelicula::getNombre(){
	return nombre;
}

void pelicula::print() {
	fin.print();
}

bool pelicula::operator<(pelicula& other) {
	if (other.fin < fin) {
		return false;
	}
	else if (other.fin > fin) {
		return true;
	}
	else {
		return other.nombre > nombre;
	}
}


