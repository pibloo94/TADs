//PABLO AGUDO BRUN

#include "queue_invertir.h"

#include <iostream>
#include <fstream>
#include<iomanip>

using namespace std;


bool resuelveCaso() {
	int elemento;

	std::cin >> elemento;

	if (!std::cin) {
		return false;
	}

	ListaInvertir<int> lista;

	while (elemento != 0) {
		lista.push(elemento);
		std::cin >> elemento;
	}


	if (lista.size() > 0) {
		lista.invertir();
		lista.print();
	}
	else {
		std::cout << "\n";
	}

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}