/*
 * conjunto.h
 *
 *  Created on: 26 feb. 2019
 *      Author: pablo
 */
#ifndef complejo_h
#define complejo_h

#include <iostream>
#include <algorithm>


class complejo {
private:
	float real;
	float imaginaria;
public:
	complejo(float r, float i); // constructor
	complejo(); //constructor por defecto
	~complejo(); //destructor
	complejo operator+(const complejo& other);
	complejo operator*(const complejo& other);
	complejo pow(const complejo& other);
	float module() const;
};

#endif
