//PABLO AGUDO BRUN

#include "bintree_eda.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

protected:
	// puntero a la ra�z del �rbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

public:
	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	// consultar si el �rbol est� vac�o
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la ra�z
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree_ext left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree_ext(raiz->left);
	}

	// consultar el hijo derecho
	bintree_ext right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree_ext(raiz->right);
	}

	// calcular el minimo elemento
	T calcularMinElem() {
		if (this->right().empty() && this->left().empty())
			return this->root();
		else {
			if (this->right().empty() && this->left().empty()) {
				return std::min(this->left().calcularMinElem(), this->root());
			}
			else if (this->right().empty() && this->left().empty()) {
				return std::min(this->right().calcularMinElem(), this->root());
			}
			else {
				T minimo = std::min(this->right().calcularMinElem(), this->left().calcularMinElem());

				return std::min(minimo, this->root());
			}
		}
	}

};

// lee un �rbol binario de la entrada est�ndar
template <typename T>
bintree_ext<T> leerArbolext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un �rbol vac�o
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolext(vacio);
		auto dr = leerArbolext(vacio);
		return { iz, raiz, dr };
	}
}*/