//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <iomanip>

#include "bintree_eda.h"

using namespace std;

int calcularAltura(int ramas) {
	int alturaRama = 1, rama;

	for (int i = 0; i < ramas; i++) {
		std::cin >> rama;

		if (rama != 0) {
			alturaRama = std::max(alturaRama, calcularAltura(rama) + 1);
		}
	}

	return alturaRama;
}

void resuelveCaso() {
	int ramas, altura;

	std::cin >> ramas;

	if (ramas == 0) {
		altura = 1;
	}
	else {
		altura = calcularAltura(ramas) + 1;
	}

	std::cout << altura << "\n";
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}