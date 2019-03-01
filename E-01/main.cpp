#include "horario.h"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void rellenarLista(std::vector<horario>& rellenar, int trenes) {
	int hora, min, seg;
	char aux;

	for (int i = 0; i < trenes; i++) {
		std::cin >> hora;
		std::cin.get(aux);
		std::cin >> min;
		std::cin.get(aux);
		std::cin >> seg;
		rellenar[i] = horario(hora, min, seg);
	}
}

void resolver(std::vector<horario> &lista, horario  &horarioValido) {
	bool valido = false;
	int i = 0;

	while (i < lista.size() && !valido) {
		if (horarioValido < lista[i]) {
			valido = true;
		}

		i++;
	}

	if (valido) {
		lista[i - 1].print();
	}
	else if(!valido){
		std::cout << "NO\n";
	}
}


bool resuelveCaso() {
	int trenes, horas;
	std::cin >> trenes;
	std::cin >> horas;

	std::vector<horario> lista(trenes);
	horario horarioValido;

	if (trenes == 0 && horas == 0) {
		return false;
	}

	rellenarLista(lista, trenes);

	int hora, min, seg;
	char aux;

	for (int i = 0; i < horas; i++) {
		std::cin >> hora;
		std::cin.get(aux);
		std::cin >> min;
		std::cin.get(aux);
		std::cin >> seg;

		try {
			horarioValido = horario(hora, min, seg);
			resolver(lista, horarioValido);
		}
		catch (std::domain_error const &e) {
			std::cout << e.what();
		}
	}

	std::cout << "---" << endl;

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