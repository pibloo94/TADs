//PABLO AGUDO BRUN

#include "queue_eda.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <class T>
class ListaAfortunado : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void print() {
		std::cout << this->front() << "\n";
	}

	void afortunado(const int& numero) {
		int cont = 0;

		while (this->size() > 1) {
			if (cont == numero) { 
				this->pop();
				cont = 0;
			}
			else {
				this->push(this->front());
				this->pop();
				cont++;
			}
		}

		this->print();
	}
};