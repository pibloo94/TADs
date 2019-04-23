//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>

#include "treemap_eda.h"

using namespace std;


void imprimir(map<std::string, int>& clase) {
	for (auto const& cv: clase) {
		if (cv.valor != 0) {
			std::cout << cv.clave << ", " << cv.valor << "\n";
		}
	}
}

void resolver(map<std::string, int>& clase, int& nAlumn) {
	std::string est, val;
	char x;
	int i = 0;

	std::cin.get();

	while (i < nAlumn) {
		getline(std::cin, est);
		getline(std::cin, val);

		if (clase.count(est) > 0) { //hace falta?
			if (val == "CORRECTO") {
				clase[est]++;
			}
			else {
				clase[est]--;
			}
		}
		else {
			if (val == "CORRECTO") {
				clase[est] = 1;
			}
			else {
				clase[est] = -1;
			}
		}

		i++;
	}
}

bool resuelveCaso() {
	int nAlumn;

	map<std::string, int> clase;

	std::cin >> nAlumn;

	//Leer caso de prueba
	if (nAlumn == 0)
		return false;

	//Resolver problema
	resolver(clase, nAlumn);

	//Imprimir resultado
	imprimir(clase);

	std::cout << "---" << "\n";

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