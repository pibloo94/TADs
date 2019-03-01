/*
 * conjunto.cpp
 *
 *  Created on: 26 feb. 2019
 *      Author: pablo
 */
#include "complejo.h"

#include <iostream>
#include <algorithm>

complejo::complejo(float r, float i) {
	real = r;
	imaginaria = i;
}

complejo::complejo() {};

complejo:: ~complejo() {};

complejo complejo::operator+(const complejo& other) {
	//a+c) + (b+d)i
	real = real + other.real;
	imaginaria = imaginaria + other.imaginaria;

	complejo c = complejo(real, imaginaria);

	return c;
}

complejo complejo::operator*(const complejo& other) {
	//(a*c-b*d) + (a*d+c*b)i
	real = (real * other.real) - (imaginaria * other.imaginaria);
	imaginaria = (real * other.imaginaria) + (other.real * imaginaria);

	complejo c = complejo(real, imaginaria);

	return c;
}

float complejo::module()const {
	//sqrt(a^2 + b^2)
	float mod = sqrt((real*real) + (imaginaria*imaginaria));

	return mod;
}




