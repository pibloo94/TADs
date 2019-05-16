// PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "ventas_libros.h"

using namespace std;


void resuelveCaso() {
	std::string operacion, x;
	ventas_libros v;
	int n;

	std::cin >> operacion;

	if (operacion == "nuevoLibro") {
		std::cin >> n >> x;
		v.nuevoLibro(n, x);
	}else if (operacion == "comprar") {
		std::cin >> x;
		v.comprar(x);
	}
	else if (operacion == "estaLibro") {
		std::cin >> x;
		bool esta = v.estaLibro(x);

		if (esta) {
			std::cout << "El libro " << x << " esta en el sistema";
		}
		else {
			std::cout << "No existe el libro " << x << " en el sistema";
		}
		std::cout << "---\n";
	}
	else if (operacion == "elimLibro") {
		std::cin >> x;
		v.elimLibro(x);
	}
	else if (operacion == "numEjemplares") {
		std::cin >> x;
		int num = v.numEjemplares(x);

		if (num != 0) {
			std::cout << "Existen " << num << " ejemplares del libro " << x;
		}
		else {
			std::cout << "No existe el libro " << x << " en el sistema";
		}

		std::cout << "---\n";
	}
	else if (operacion == "top10") {
		std::vector<std::string> lista = v.top10();

		for (int i = 0; i < lista.size(); i++) {
			std::cout << lista[i] << "\n";
		}

		std::cout << "---\n";
	}
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	unsigned int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
		std::cout << "------\n";
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}