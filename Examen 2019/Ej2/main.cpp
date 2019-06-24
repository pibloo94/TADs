//PABLO AGUDO BRUN

#include <fstream>
#include <iostream>

#include "bintree_hija.h"

using namespace std;


void resuelveCaso() {
	char vacio = '.';
	tSolucion solucion;

	BintreeEj2<char> arbol;

	arbol = arbol.leerArbol_ext(vacio);

	arbol.completo(solucion);

	if (solucion.cumple) {
		std::cout << "SI";
	}
	else {
		std::cout << "NO";
	}

	std::cout << "\n";
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i ++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}