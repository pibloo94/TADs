//PABLO AGUDO BRUN

#include "bintree_eda.h"

#include <iostream>
#include <fstream>

using namespace std;

struct tSolucion {
	int nodos;
	int hojas;
	int altura;
};


template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	int altura() {
		return altura(this->raiz);
	}

	void datos(tSolucion& solucion) {
		solucion.nodos = contarNodos(this->raiz);
		solucion.hojas = contarHojas(this->raiz);
		solucion.altura = contarAltura(this->raiz);
	}

	// lee un árbol binario de la entrada estándar
	// Transparencia 10 del tema "Tipos de datos arborescentes" 
	template <typename U>
	bintree_ext<U> leerArbolext(U vacio) {
		U raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un árbol vacío
			return {};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbolext(vacio);
			auto dr = leerArbolext(vacio);
			return { iz, raiz, dr };
		}
	}

private:
	int contarNodos(Link raiz) {
		if (raiz != nullptr) {
			return 1 + contarNodos(raiz->left) + contarNodos(raiz->right);
		}
		else {
			return 0;
		}
	}

	int contarHojas(Link raiz) {
		if (raiz == nullptr) {
			return 0;
		}
		else if (raiz->left == nullptr && raiz->right == nullptr) {
			return 1;
		}
		else {
			return contarHojas(raiz->left) + contarHojas(raiz->right);
		}
	}

	int contarAltura(Link raiz) {
		if (raiz != nullptr) {
			return 1 + std::max(contarAltura(raiz->left), contarAltura(raiz->right));
		}
		else {
			return 0;
		}
	}
};