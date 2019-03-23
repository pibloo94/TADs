//PABLO AGUDO BRUM

#include "queue_eda.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <class T>
class ListaMezclar : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void print(const int& nTotal) {
		Nodo * nodo = this->prim;

		for (int i = 0; i < nTotal; i++) {
			std::cout << " " << nodo->elem;
			nodo = nodo->sig;
		}
	}

	void mezclar(ListaMezclar<int>& lista2) {
		Nodo * nodo = this->prim;
		Nodo * aux = lista2.prim;
		Nodo * menor;

		int nelemsLista1 = this->nelems;
		int nelemsLista2 = lista2.nelems;
		int nTotal = this->nelems + lista2.nelems;

		if (nodo == nullptr) {
			this->prim = lista2.prim;
		}
		else if (aux != nullptr) {
			if (nodo->elem <= aux->elem) {
				menor = nodo;
				nodo = nodo->sig;
				nelemsLista1--;
			}
			else {
				this->prim = aux;
				menor = aux;
				aux = aux->sig;
				nelemsLista2--;
			}

			while (nodo != nullptr && aux != nullptr) {
				if (nodo->elem <= aux->elem) {
					menor->sig = nodo;
					menor = menor->sig;
					nodo = nodo->sig;
					nelemsLista1--;
				}
				else {
					menor->sig = aux;
					menor = menor->sig;
					aux = aux->sig;
					nelemsLista2--;
				}
			}

			if (nelemsLista1 > 0) {
				menor->sig = nodo;
			}
			else if (nelemsLista2 > 0) {
				menor->sig = aux;
			}
		}
		
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;

		print(nTotal);
	}
};