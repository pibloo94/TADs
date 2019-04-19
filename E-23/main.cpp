//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <vector>

#include "bintree_eda.h"

using namespace std;


struct tSolucion {
	int nGrupos = 0;
	int nExcursionistas = 0;
};

template <class T>
tSolucion resolver(bintree<T> arbol) {
	tSolucion sol, izq, der;

	if (arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() > 0) {
			sol.nGrupos = 1;
			sol.nExcursionistas = arbol.root();
		}
		else {
			sol.nGrupos = 0;
			sol.nExcursionistas = 0;
		}
	}
	else {
		if (!arbol.left().empty() && !arbol.right().empty()) {
			izq = resolver(arbol.left());
			der = resolver(arbol.right());

			if (izq.nExcursionistas > der.nExcursionistas) {
				sol.nExcursionistas = izq.nExcursionistas;
			}
			else {
				sol.nExcursionistas = der.nExcursionistas;
			}

			sol.nGrupos = izq.nGrupos + der.nGrupos;
		}
		else if (!arbol.left().empty()) {
			sol = resolver(arbol.left());
		}
		else if (!arbol.right().empty()) {
			sol = resolver(arbol.right());
		}

		sol.nExcursionistas += arbol.root();

		if (sol.nGrupos == 0 && arbol.root() > 0) {
			sol.nGrupos++;
		}
	}

	return sol;
}

void resuelveCaso() {
	tSolucion sol;

	int vacio = -1;
	bintree<int> arbol = leerArbol(vacio);

	if (!arbol.empty()) {
		sol = resolver(arbol);
	}

	std::cout << sol.nGrupos << " " << sol.nExcursionistas << "\n";
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