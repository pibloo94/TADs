//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;

struct tSolucion {
	std::string nombreDeporte;
	int inscritos;
};

bool ordenar(tSolucion a, tSolucion b) {
	if (a.inscritos > b.inscritos) {
		return true;
	}
	else if (a.inscritos == b.inscritos) {
		if (a.nombreDeporte < b.nombreDeporte) {
			return true;
		}
	}

	return false;
}

void imprimir(const std::vector<tSolucion>& v) {
	for (auto &it : v) {
		std::cout << it.nombreDeporte << " " << it.inscritos << "\n";
	}
}


bool resuelveCaso() {
	std::string palabra, deporte, alumno;
	std::string nombreEst;

	std::unordered_map<std::string, int> deportes;
	std::unordered_map<std::string, std::string> alumnos;

	std::unordered_map<std::string, int>::iterator itD = deportes.begin();
	std::unordered_map<std::string, std::string>::iterator itA = alumnos.begin();

	std::cin >> palabra;

	if (!std::cin) {
		return false;
	}

	while (palabra != "_FIN_") {
		if (palabra[0] >= 'a' && palabra[0] <= 'z') { //es un alumno
			alumno = palabra;
			itA = alumnos.find(alumno);

			if (itA == alumnos.end()) { // si el alumno no esta en ningun deporte
				alumnos[alumno] = deporte; // se le asigna un deporte al alumno
				deportes[deporte]++; // aumentas la cantidad de alumnos
			}
			else { // si el alumno ya esta inscrito en un deporte
				if (itA->second != deporte && itA->second != "SIN DEPORTE") { // si el deporte es distinto al del inscrito
					deportes[itA->second]--; // se desinscribe el alumno;
					alumnos[alumno] = "SIN DEPORTE";
				}
			}
		}
		else { // es un deporte
			deporte = palabra;
			deportes[palabra] = 0; // no se repiten deportes
		}

		std::cin >> palabra;
	}

	tSolucion sol;
	std::vector<tSolucion> v;

	for (auto &it : deportes) {
		sol.nombreDeporte = it.first;
		sol.inscritos = it.second;
		v.push_back(sol);
	}

	std::sort(v.begin(), v.end(), ordenar);

	imprimir(v);

	std::cout << "***\n";

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
