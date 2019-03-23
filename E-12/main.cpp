//PABLO AGUDO BRUN

#include "queue_afortunado.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


void resolver(int& nAlumnos, int& numero) {
	ListaAfortunado<int> alumnos;

	for (int i = 1; i <= nAlumnos; i++) {
		alumnos.push(i);
	}

	alumnos.afortunado(numero);

}

bool resuelveCaso() {

	int nAlumnos, numero;

	std::cin >> nAlumnos >> numero;

	if (nAlumnos == 0 && numero == 0) {
		return false;
	}

	while (nAlumnos != 0 && numero != 0) {
		resolver(nAlumnos, numero);
		std::cin >> nAlumnos >> numero;
	}

	if (nAlumnos == 0 && numero == 0) {
		return false;
	}

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