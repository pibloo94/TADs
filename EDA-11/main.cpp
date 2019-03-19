// PABLO AGUDO BRUN

#include "queue_mezclar.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void resuelveCaso() {
	int elemento;

	ListaMezclar<int> lista1;

	std::cin >> elemento;

	while(elemento != 0){
		lista1.push(elemento);
		std::cin >> elemento;
	}
	
	ListaMezclar<int> lista2;

	std::cin >> elemento;

	while (elemento != 0) {
		lista2.push(elemento);
		std::cin >> elemento;
	}

	lista1.mezclar(lista2);

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

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}