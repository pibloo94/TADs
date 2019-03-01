//PABLO AGUDO BRUN

#include "pelicula.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void rellenarLista(std::vector<pelicula>& listaPeliculas, int npeliculas) {
	horario inicio, duracion;
	int hora, min, seg;
	std::string nombre;
	char aux;

	for (int i = 0; i < npeliculas; i++) {
		std::cin >> hora >> aux >> min >> aux >> seg;
		inicio = horario(hora, min, seg);

		std::cin >> hora >> aux >> min >> aux >> seg;
		duracion = horario(hora, min, seg);

		std::getline(std::cin, nombre); //importante leer linea entera

		listaPeliculas[i] = pelicula(inicio, duracion, nombre);
	}
}

void resolver(std::vector<pelicula>& listaPeliculas) {
	std::sort(listaPeliculas.begin(), listaPeliculas.end());

	for (int i = 0; i < listaPeliculas.size(); i++) {
		listaPeliculas[i].print();
		std::cout << listaPeliculas[i].getNombre() << "\n";
	}

	std::cout << "---" << "\n";
}

bool resuelveCaso() {
	int npeliculas;
	std::cin >> npeliculas;

	if (npeliculas == 0) {
		return false;
	}

	std::vector<pelicula> listaPeliculas(npeliculas);
	rellenarLista(listaPeliculas, npeliculas);
	resolver(listaPeliculas);

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}