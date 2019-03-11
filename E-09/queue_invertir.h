//PABLO AGUDO BRUN

#include "queue_eda.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


template <class T>
class ListaInvertir : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:

	void print() {
		Nodo * nodo = this->prim;
		if (this->nelems > 0) {
			for (int i = 0; i < this->nelems; i++) {
				if (i == 0) {
					std::cout << nodo->elem;
				}
				else {
					std::cout << " " << nodo->elem;
				}

				nodo = nodo->sig;
			}
		}
		std::cout << "\n";

	}

	void invertir() {
		Nodo * nodoSig = this->prim->sig;
		Nodo * aux = this->prim;
		Nodo * nodo;

		//actualizo primero a ultimo
		this->prim->sig = nullptr;

		for (int i = 0; i < this->nelems - 1; i++) {
			nodo = nodoSig->sig;
			nodoSig->sig = aux;
			aux = nodoSig;
			nodoSig = nodo;
		}

		//actualizo ultimo a primero
		aux = this->prim;
		this->prim = this->ult;
		this->ult = aux;
	}
};