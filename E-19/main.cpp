//PABLO AGUDO BRUN

#include "bintree_hija.h"

#include <iostream>
#include <fstream>

using namespace std;


void resolver(bintree_ext<char>& arbol, tSolucion& solucion) {
	arbol.datos(solucion);
}

void resuelveCaso() {
	char vacio = '.';
	tSolucion solucion;
	bintree_ext<char> arbol;

	arbol = arbol.leerArbolext(vacio);

	resolver(arbol, solucion);

	std::cout << solucion.nodos << " " << solucion.hojas << " " << solucion.altura << "\n";

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