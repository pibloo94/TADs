//PABLO AGUDO BRUN

#ifndef polinomio_h
#define polinomio_h

#include <iostream>
#include <vector>
#include <algorithm>

struct monomio {
	int coeficiente = 0;
	int exponente = 0;
};

class polinomio {
private:
	std::vector<monomio> listaMonomios;

public:
	polinomio(); //constructor por defecto
	~polinomio(); //destructor
	void insertar(monomio m);
	void ordenar();
	int evaluar(int x);
};
#endif