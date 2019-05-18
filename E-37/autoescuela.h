//PABLO AGUDO BRUN

#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

class autoescuela {

private:
	std::unordered_map<std::string, int> mapPuntuaciones;
	std::unordered_map<std::string, std::string> mapAlumnos;
	std::unordered_map <std::string, std::list<std::string>> mapAlumnosProfesor;
	std::unordered_map <std::string, std::list<std::string>::iterator> mapIteradores;


public:
	autoescuela() {};

	//sirve tanto para dar de alta a un alumno como para cambiarle de profesor.
	void alta(std::string alumno, std::string profesor) {
		auto it = mapAlumnos.find(alumno);

		//Si el alumno no estaba matriculado en la autoescuela se le da una puntuacion de cero.
		if (it == mapAlumnos.end()) {
			mapPuntuaciones.insert({ alumno, 0 });
			mapAlumnos[alumno] = profesor;
			mapAlumnosProfesor[profesor].push_front(alumno);
			mapIteradores[alumno] = mapAlumnosProfesor[profesor].begin();
		}
		//Si ha cambiado de profesor, se le da de alta con el nuevo, con la puntuacion que 
		//tuviera, y se le da de baja con el anterior.
		else {
			mapAlumnosProfesor[it->second].erase(mapIteradores[alumno]);
			mapIteradores.erase(alumno);
			mapAlumnos[alumno] = profesor;
			mapAlumnosProfesor[profesor].push_front(alumno);
			mapIteradores[alumno] = mapAlumnosProfesor[profesor].begin();
		}
	}

	//comprueba si el alumno A esta matriculado actualmente con el profesor P.
	bool es_alumno(std::string alumno, std::string profesor) {

		if (mapAlumnos[alumno] == profesor) {
			return true;
		}
		else {
			return false;
		}
	}

	//devuelve los puntos que tiene el alumno A.
	int puntuacion(std::string alumno) {
		auto it = mapPuntuaciones.find(alumno);

		//Si el alumno no esta dado de alta, entonces se lanza una excepcion
		if (it == mapPuntuaciones.end()) {
			throw std::domain_error("El alumno " + alumno + "no esta matriculado");
		}
		else {
			return mapPuntuaciones[alumno];
		}
	}

	//aumenta en una cantidad N la puntuacion del alumno A.
	void actualizar(std::string alumno, int N) {
		auto it = mapPuntuaciones.find(alumno);

		//Si el alumno no esta dado de alta, entonces se lanza una excepcion
		if (it == mapPuntuaciones.end()) {
			throw std::domain_error("El alumno " + alumno + "no esta matriculado");
		}
		else {
			mapPuntuaciones[alumno] += N;
		}
	}

	//obtiene una lista con los alumnos del profesor P, ordenados alfabeticamente, que se
	//presentaran a examen por tener una puntuacion mayor o igual a N puntos.
	std::vector<std::string> examen(std::string profesor, int N) {
		std::vector<std::string> lista;
		auto it = mapAlumnosProfesor.find(profesor);

		if (it != mapAlumnosProfesor.end()) {
			for (auto a : it->second) {
				if (mapPuntuaciones[a] >= N) {
					lista.push_back(a);
				}
			}
		}
		else {
			mapAlumnosProfesor.insert({ profesor, {} });
		}

		std::sort(lista.begin(), lista.end());

		return lista;
	}

	//el alumno A aprueba el examen y es borrado de la autoescuela, junto con toda la
	//informacion que de el existiera.
	void aprobar(std::string alumno) {
		auto it = mapPuntuaciones.find(alumno);

		//Si el alumno no esta dado de alta, entonces se lanza una excepcion
		if (it == mapPuntuaciones.end()) {
			throw std::domain_error("El alumno " + alumno + "no esta matriculado");
		}
		else {
			mapAlumnosProfesor[mapAlumnos[alumno]].erase(mapIteradores[alumno]);
			mapIteradores.erase(alumno);
			mapPuntuaciones.erase(alumno);
			mapAlumnos.erase(alumno);
		}
	}
};
#endif