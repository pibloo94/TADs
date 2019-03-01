//PABLO AGUDO BRUN

#include "polinomio.h"

polinomio::polinomio() {};

polinomio::~polinomio() {};

void polinomio::insertar(monomio m) {
	listaMonomios.push_back(m);
}

void polinomio::ordenar() {
	std::sort(listaMonomios.begin(), listaMonomios.end());
}

bool operator<(monomio left, monomio right) {
	return ((left.exponente < right.exponente) || (left.exponente == right.exponente && left.coeficiente < right.exponente));
}

int polinomio::evaluar(int valor) {
	int x = 0;

	for (int i = 0; i < listaMonomios.size(); i++) {
		x += listaMonomios[i].coeficiente * pow(valor, listaMonomios[i].exponente);
	}

	return x;
}
