#ifndef pelicula_h
#define pelicula_h

#include "horario.h"
#include <string>

class pelicula {
private:
	horario inicio;
	horario fin;
	horario duracion;
	std::string nombre;

public:
	pelicula(horario inicio, horario duracion, std::string nombre); //constructor
	pelicula(); //constructor vacio
	~pelicula(); // destructor
	void print();
	bool operator<(pelicula & other);
	std::string getNombre();
};

#endif