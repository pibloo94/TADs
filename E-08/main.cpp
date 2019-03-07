//PABLO AGUDO BRUN

#include "queueHija.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool resuelveCaso() {
	int elemento;

	std::cin >> elemento;

	if (!std::cin) {
		return false;
	}

	ListaDuplicada<int> lista;

	while(elemento != 0){
		lista.push(elemento);
		std::cin >> elemento;
	}

	lista.duplica();
	lista.print();

	std::cout << "\n";


	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
