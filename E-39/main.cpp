// PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include "venta_libros.h"

using namespace std;


bool resuelveCaso() {
	std::string operacion, x;
	ventas_libros v;
	int n;

	unsigned int numCasos;
	std::cin >> numCasos;

	if (!std::cin) {
		return false;
	}

	for (int i = 0; i < numCasos; i++) {
		try {
			std::cin >> operacion;
			cin.get();

			if (operacion == "nuevoLibro") {
				std::cin >> n;
				cin.get();
				getline(std::cin, x);
				v.nuevoLibro(n, x);
			}
			else if (operacion == "comprar") {
				getline(std::cin, x);
				v.comprar(x);
			}
			else if (operacion == "estaLibro") {
				getline(std::cin, x);
				bool esta = v.estaLibro(x);

				if (esta) {
					std::cout << "El libro " << x << " esta en el sistema\n";
				}
				else {
					std::cout << "No existe el libro " << x << " en el sistema\n";
				}

				std::cout << "---\n";
			}
			else if (operacion == "elimLibro") {
				getline(std::cin, x);
				v.elimLibro(x);
			}
			else if (operacion == "numEjemplares") {
				getline(std::cin, x);
				int num = v.numEjemplares(x);

				if (num != 0) {
					std::cout << "Existen " << num << " ejemplares del libro " << x << "\n";
				}
				else {
					std::cout << "No existe el libro " << x << " en el sistema\n";
				}

				std::cout << "---\n";
			}
			else if (operacion == "top10") {
				std::vector<std::string> lista = v.top10();

				for (auto& l : lista) {
					std::cout << l << "\n";
				}

				std::cout << "---\n";
			}
		}
		catch(std::exception & e) {
			std::cout << e.what() << "\n";
			std::cout << "---\n";
		}
	}

	std::cout << "------\n";

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	while(resuelveCaso());
	

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}