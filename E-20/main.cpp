//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
#include <vector>

#include "bintree_hija.h"

using namespace std;


void resuelveCaso() {
	int vacio = -1;
	
	bintree_ext<int> arbol;
	arbol = arbol.leerArbolext(vacio);

	std::vector<int> solFrontera;

	arbol.frontera(solFrontera);
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
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