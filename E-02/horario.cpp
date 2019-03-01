#include "horario.h"

#include <iostream>
#include <iomanip>

using namespace std;

horario::horario(int hora, int min, int seg) : hora(hora), min(min), seg(seg) {
	if (hora < 0 || hora >= 24 || min < 0 || min >= 60 || seg < 0 || seg >= 60) {
		throw std::domain_error("ERROR\n");
	}
};

horario::horario() {};
horario::~horario() {};

bool horario::operator<(horario const &other) {
	if (other.hora > hora) {
		return true;
	}
	else if (other.hora < hora) {
		return false;
	}
	else {
		if (other.min > min) {
			return true;
		}
		else if (other.min < min) {
			return false;
		}
		else {
			if (other.seg > seg) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool horario::operator>(horario const &other) {
	if (other.hora < hora) {
		return true;
	}
	else if (other.hora > hora) {
		return false;
	}
	else {
		if (other.min < min) {
			return true;
		}
		else if (other.min > min) {
			return false;
		}
		else {
			if (other.seg < seg) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

horario horario::operator+(horario const& other) {
	horario horaPelicula;

	min = (min + other.min + ((seg + other.seg) / 60)) % 60;
	seg = (seg + other.seg) % 60;
	hora = (hora + other.hora + (min / 60)) % 24;

	horaPelicula = horario(hora, min, seg);

	return horaPelicula;
}

void horario::print() {
	std::cout
		<< std::setw(2) << std::setfill('0') << hora << ":"
		<< std::setw(2) << std::setfill('0') << min << ":"
		<< std::setw(2) << std::setfill('0') << seg;
}

