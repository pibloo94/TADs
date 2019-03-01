#ifndef horario_h
#define horario_h

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>


class horario {
private:
	int hora, min, seg;

public:
	horario(int hora, int min, int seg); //constructor
	horario(); //constructor vacio
	~horario(); //destructor
	bool operator<(horario const& other);
	void print();
};

#endif

