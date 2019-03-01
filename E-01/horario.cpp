#include "horario.h"

#include <iostream>
#include <iomanip>


horario::horario(int hora, int min, int seg): hora(hora), min(min), seg(seg){
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
			if (other.seg >= seg) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void horario::print() {
	std::cout << std::setw(2) << std::setfill('0') << hora << ":" << std::setw(2) << std::setfill('0') << min << ":" << std::setw(2) << std::setfill('0') << seg << "\n";
}
