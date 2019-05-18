//PABLO AGUDO BRUN

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "autoescuela.h"

using namespace std;


bool resuelveCaso() {
	std::string operacion, profesor, alumno;
	int N;

	std::cin >> operacion;

	if (!std::cin) {
		return false;
	}

	autoescuela aut;

	while (operacion != "FIN") {
		try {
			if (operacion == "alta") {
				std::cin >> alumno >> profesor;
				aut.alta(alumno, profesor);
			}
			else if (operacion == "es_alumno") {
				std::cin >> alumno >> profesor;
		
				if (aut.es_alumno(alumno, profesor)) {
					std::cout << alumno << " es alumno de " << profesor << "\n";
				}
				else {
					std::cout << alumno << " no es alumno de " << profesor << "\n";
				}
			}
			else if (operacion == "puntuacion") {
				std::cin >> alumno;

				std::cout << "Puntuacion de " << alumno << ": " << aut.puntuacion(alumno) << "\n";
			}
			else if (operacion == "actualizar") {
				std::cin >> alumno >> N;
				aut.actualizar(alumno, N);
			}
			else if (operacion == "examen") {
				std::cin >> profesor >> N;
				std::vector<std::string> listaAlumnos = aut.examen(profesor, N);
				
				std::cout << "Alumnos de " << profesor << " a examen:\n";

				for (auto& a:listaAlumnos) {
					std::cout << a << "\n";
				}
			}
			else if (operacion == "aprobar") {
				std::cin >> alumno;
				aut.aprobar(alumno);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		
		std::cin >> operacion;
	}

	std::cout << "------\n";

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
