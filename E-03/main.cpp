/*
 * main.cpp
 *
 *  Created on: 26 feb. 2019
 *      Author: pablo
 */
#include "complejo.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;


bool resolver(complejo& c, int iter) {
	bool cumple = true;
	int i = 0;
	complejo aux, sum(0, 0);

	//Zn = Zn-1^2 + c
	while (i < iter && cumple) {
		aux = ((sum * sum) + c);

		if (aux.module() > 2) {
			cumple = false;
		}

		sum = aux;

		i++;
	}

	return cumple;
}

void resuelveCaso() {
	float real, imaginaria;
	int iter;

	std::cin >> real >> imaginaria >> iter;

	complejo c = complejo(real, imaginaria);

	if (resolver(c, iter)) {
		std::cout << "SI" << "\n";
	}
	else {
		std::cout << "NO" << "\n";
	}
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
