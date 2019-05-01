//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


void imprimir(const std::map<std::string, std::vector<int>>& palabras) {

	for (auto &it:palabras) {
		std::cout << it.first;

		for (int i = 0; i < it.second.size(); i++) {
			std::cout << " " << it.second[i];
		}

		std::cout << "\n";
	}
}

void resolver(
	std::map<std::string, std::vector<int>>& palabras,
	int& j) {

	std::string clave, linea;

	getline(std::cin, linea);
	std::stringstream v(linea);

	std::map<std::string, std::vector<int>>::iterator it = palabras.begin();

	while (v >> clave) {
		for (int i = 0; i < clave.size(); i++) {
			clave[i] = tolower(clave[i]);
		}

		if (clave.size() > 2) {
			it = palabras.find(clave);

			if (it == palabras.end()) { // en caso de que no exista
				palabras[clave].push_back(j);
			}
			else {
				if (palabras[clave][palabras[clave].size() - 1] != j) {
					palabras[clave].push_back(j);
				}
			}
		}
	}	
}

bool resuelveCaso() {
	int n;
	std::map<std::string, std::vector<int>> palabras;

	std::cin >> n;
	cin.get();

	if (n == 0) {
		return true;
	}

	for (int j = 1; j <= n; j++) {
		resolver(palabras, j);
	}

	imprimir(palabras);

	std::cout << "----\n";

	return false;
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