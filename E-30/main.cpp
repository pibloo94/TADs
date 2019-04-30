//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>


using namespace std;


void imprimir(
	std::vector<std::string>& nuevos,
	std::vector<std::string>& eliminados,
	std::vector<std::string> modificados) {

	if (nuevos.size() == 0 && eliminados.size() == 0 && modificados.size() == 0) {
		std::cout << "Sin cambios\n";
	}
	else {
		if (nuevos.size() != 0) {
			for (int i = 0; i < nuevos.size(); i++) {
				if (i == 0) {
					std::cout << "+ " << nuevos[i];
				}
				else {
					std::cout << " " << nuevos[i];
				}
			}

			std::cout << "\n";
		}


		if (eliminados.size() != 0) {
			for (int i = 0; i < eliminados.size(); i++) {
				if (i == 0) {
					std::cout << "- " << eliminados[i];
				}
				else {
					std::cout << " " << eliminados[i];
				}
			}

			std::cout << "\n";
		}

		if (modificados.size() != 0) {
			for (int i = 0; i < modificados.size(); i++) {
				if (i == 0) {
					std::cout << "* " << modificados[i];
				}
				else {
					std::cout << " " << modificados[i];
				}
			}

			std::cout << "\n";
		}
	}
}

void resolver(
	std::map <std::string, int>& viejo,
	std::map <std::string, int>& nuevo) {

	std::vector<std::string> nuevos;
	std::vector<std::string> eliminados;
	std::vector<std::string> modificados;

	std::map <std::string, int>::iterator it1 = viejo.begin(); //iterador a diccionario viejo
	std::map <std::string, int>::iterator it2 = nuevo.begin(); //iterador a diccionario nuevo

	while (it1 != viejo.end() && it2 != nuevo.end()) {
		if (it1->first > it2->first) { //nuevos
			nuevos.push_back(it2->first);
			it2++;
		}
		else if (it1->first < it2->first) { //eliminados
			eliminados.push_back(it1->first);
			it1++;

		}
		else if (it1->first == it2->first) { //modificados
			if (it1->second != it2->second) {
				modificados.push_back(it1->first);
			}

			it1++;
			it2++;
		}
	}

	//si sigue habiendo elementos en el diccionario viejo se cuentan como eliminados
	if (it1 != viejo.end()) {
		while (it1 != viejo.end()) {
			eliminados.push_back(it1->first);
			it1++;
		}
	}
	//si sigue habiend elementos en el diccionario nuevo se cuenta como nuevos
	else if (it2 != nuevo.end()) {
		while (it2 != nuevo.end()) {
			nuevos.push_back(it2->first);
			it2++;
		}
	}

	imprimir(nuevos, eliminados, modificados);
}

void resuelveCaso() {
	std::map <std::string, int> viejo;
	std::map <std::string, int> nuevo;

	std::string clave, linea;
	int valor;

	getline(std::cin, linea);
	std::stringstream l1(linea);

	while (l1 >> clave >> valor) {
		viejo[clave] = valor;
	}

	getline(std::cin, linea);
	std::stringstream l2(linea);

	while (l2 >> clave >> valor) {
		nuevo[clave] = valor;
	}

	resolver(viejo, nuevo);

	std::cout << "----\n";

}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;
	std::cin.get(); //salto de linea al leer

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