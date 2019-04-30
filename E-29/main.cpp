//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "treemap_eda.h"

using namespace std;

int resolver(unordered_map<int, int>& capitulos, int& nCapitulos) {
	long long int secuencia = 0, elem;
	long long int ini = 1, aux = 0;
	int i = 1;

	while (i <= nCapitulos) {
		std::cin >> elem;

		if (capitulos[elem] < ini) {
			aux++;

			if (secuencia < aux) {
				secuencia = aux;
			}
		}
		else { //capitulos[elem] >= ini
			ini = capitulos[elem] + 1;
			aux = i - capitulos[elem];
		}

		capitulos[elem] = i;
		i++;
	}


	return secuencia;
}

void resuelveCaso() {
	int nCapitulos, solucion;

	unordered_map<int, int> capitulos;

	std::cin >> nCapitulos;

	if(nCapitulos != 0){
		solucion = resolver(capitulos, nCapitulos);
	}

	std::cout << solucion << "\n";
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