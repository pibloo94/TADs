//PABLO AGUDO BRUN


#include <iostream>
#include <fstream>
#include <string>

#include "bintree_eda.h"

using namespace std;


bool resuelveCaso() {
	char tipo;

	std::cin >> tipo;

	if (!std::cin) {
		return false;
	}

	if (tipo == 'N') {
		int vacio = -1;

		bintree <int> arbol;
		arbol = leerArbol(vacio);
		int min = arbol.calcularMinElem();
		std::cout << min << "\n";
	}
	else if (tipo == 'P') {
		std::string vacio = "#";

		bintree <std::string> arbol;
		arbol = leerArbol(vacio);

		std::string min = arbol.calcularMinElem();

		std::cout << min << "\n";
	}

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	// Resolvemos
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}