//PABLO AGUDO BRUN

#include <fstream>
#include <iostream>

#include "bintree_eda.h"

using namespace std;


struct tSolucion {
	bool cumple = true;
	int izq = 0;
	int der = 0;
};

template <class T>
class BintreeEj2 : public bintree <T> {

	using Link = typename bintree<T>::Link;

public:

	BintreeEj2() : bintree<T>() {};
	
	BintreeEj2(BintreeEj2<T> const& l, T const& e, BintreeEj2<T> const& r) : bintree<T>(l, e, r){};

	template <typename U>
	BintreeEj2<U> leerArbol_ext(U vacio) {
		U raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un árbol vacío
			return {};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbol_ext(vacio);
			auto dr = leerArbol_ext(vacio);
			return { iz, raiz, dr };
		}
	}

	void completo(tSolucion& solucion) {
		calcularCompleto(this->raiz, solucion);
	}

	void calcularCompleto(Link raiz, tSolucion& solucion) {

		if (raiz != nullptr) { //si el arbol esta vacio
			if (raiz->left != nullptr && raiz->right != nullptr) { //hay izq y der
				solucion.izq++;
				solucion.der++;
				calcularCompleto(raiz->left, solucion);
				calcularCompleto(raiz->right, solucion);
			}
			else if (raiz->left != nullptr && raiz->right == nullptr) { //hay izq
				solucion.izq++;
				solucion.cumple = false;
				calcularCompleto(raiz->left, solucion);
			}
			else if (raiz->left == nullptr && raiz->right != nullptr) { //hay der
				solucion.der++;
				solucion.cumple = false;
				calcularCompleto(raiz->right, solucion);
			}
			else if (raiz->left == nullptr && raiz->right == nullptr) { //estamos en hoja
				if (solucion.izq == solucion.der) {
					solucion.cumple = true;
				}
				else {
					solucion.cumple = false;
				}
			}
		}
		else {
			solucion.cumple = false;
		}
	}
};