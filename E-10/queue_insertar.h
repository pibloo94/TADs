#pragma once

#include "queue_eda.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <class T>
class ListaInsertar : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void print(int nTotal) {
		Nodo * nodo = this->prim;

		for (int i = 0; i < nTotal; i++) {
			if (i == 0) {
				std::cout << nodo->elem;
			}
			else {
				std::cout << " " << nodo->elem;
			}

			nodo = nodo->sig;
		}
	}

	void insertar(int& p, ListaInsertar<long int>& lista2) {
		Nodo * nodo;
		Nodo * aux;
		Nodo * aux2;
		int nTotal = this->nelems + lista2.size();

		if (p == 0) {
			aux = lista2.prim;
			aux2 = this->prim;

			lista2.ult->sig = aux2;
			this->prim = aux;
		}
		else {
			nodo = this->prim;

			for (int i = 0; i < p - 1; i++) {
				nodo = nodo->sig;
			}

			aux = nodo->sig; //guardo nodo->sig en aux
			nodo->sig = lista2.prim; // nodo->sig apunta al principio de la lista2
			lista2.ult->sig = aux; // el ultimo de la lista2 apunta a nodo->sig (aux)
		
		}
		//imprimo
		print(nTotal);

		//elimino lista2
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;
	}
		
};
