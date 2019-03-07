//PABLO AGUDO BRUN

#include "queue_eda.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

template <class T>
class ListaDuplicada : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:
	void print()const{
		Nodo * nodo = this->prim;

		for(int i = 0; i < this->nelems; i++){
			if(i == 0){
				std::cout << nodo->elem;

			}else{
				std::cout << " " << nodo->elem;
			}

			nodo = nodo->sig;
		}
	}

	void duplica(){
		Nodo * nodo = this->prim;
		int n = this->nelems;

		for(int i = 0; i < n; i++){
			Nodo * nodoSig = nodo->sig;
			nodo->sig = new Nodo(nodo->elem, nodoSig);
			nodo = nodoSig;
			this->nelems++;
		}
	}
};
