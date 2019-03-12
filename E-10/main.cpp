//PABLO AGUDO BRUN

#include "queue_insertar.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool resuelveCaso() {
	int n, m, p;
	long int elementoLista, elementoInsertar;

	std::cin >> n;

	if (!std::cin) {
		return false;
	}

	ListaInsertar<long int> lista1;


	for (int i = 0; i < n; i++) {
		std::cin >> elementoLista;
		lista1.push(elementoLista);
	}

	std::cin >> m >> p;

	ListaInsertar<long int> lista2;

	for (int i = 0; i < m; i++) {
		std::cin >> elementoInsertar;
		lista2.push(elementoInsertar);
	}

	lista1.insertar(p, lista2);

	std::cout << "\n";
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}