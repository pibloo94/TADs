//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "carnet_puntos.h"



bool resuelveCaso() {
	std::string orden, dni;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos dgt;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				cin >> dni;
				dgt.nuevo(dni);
			}
			else if (orden == "quitar") {
				cin >> dni >> punt;
				dgt.quitar(dni, punt);
			}
			else if (orden == "recuperar") {
				cin >> dni >> punt;
				dgt.recuperar(dni, punt);
			}
			else if (orden == "consultar") {
				cin >> dni;
				punt = dgt.consultar(dni);
				cout << "Puntos de " << dni << ": " << punt << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				cin >> punt;
				int cuantos = dgt.cuantos_con_puntos(punt);
				cout << "Con " << punt << " puntos hay " << cuantos << '\n';
			}
			else if (orden == "lista_por_puntos") {
				cin >> punt;
				auto const& lista = dgt.lista_por_puntos(punt);
				cout << "Tienen " << punt << " puntos:";
				for (auto const& dni : lista)
					cout << ' ' << dni;
				cout << '\n';
			}
			else{
				cout << "OPERACION DESCONOCIDA\n";
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
		}

		std::cin >> orden;
	}

	std::cout << "---\n";

	return true;
}

int main() {

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