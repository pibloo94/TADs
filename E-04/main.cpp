//PABLO AGUDO BRUN

#include "polinomio.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;


int resolver(polinomio p, int valor) {
	int x = p.evaluar(valor);

	return x;
}

bool resuelveCaso() {

	polinomio p;
	monomio m;

	std::cin >> m.coeficiente >> m.exponente;

	if (!std::cin) {
		return false;
	}

	//inserto los monominos en el polinomio
	while (m.coeficiente != 0 || m.exponente != 0) {
		p.insertar(m);
		std::cin >> m.coeficiente >> m.exponente;
	}

	p.ordenar(); //una vez insertados todos los monomios en el polinomio ordeno

	int n, valor;

	std::cin >> n;

	//evaluo el polinomio
	for (int i = 0; i < n; i++) {
		std::cin >> valor;

		if (i == 0) {
			std::cout << resolver(p, valor);
		}
		else {
			std::cout << " " << resolver(p, valor);
		}
	}

	std::cout << "\n";

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