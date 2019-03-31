//PABLO AGUDO BRUN

#include "bintree_eda.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	// lee un árbol binario de la entrada estándar
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

	void print(std::vector<int>& solFrontera) {
		for (int i = 0; i < solFrontera.size(); i++) {
			if (i == 0) {
				std::cout << solFrontera[i];
			}
			else {
				std::cout << " " << solFrontera[i];
			}
		}

		std::cout << "\n";
	}

	void frontera(std::vector<int>& solFrontera) {
			calcularFrontera(solFrontera, this->raiz);
			print(solFrontera);
	}

private:

	void calcularFrontera(std::vector<int>& solFrontera, Link raiz) {
		if (raiz == nullptr) {
			return;
		}
		else if (raiz->left == nullptr && raiz->right == nullptr) {
			solFrontera.push_back(raiz->elem);
		}
		else {
			calcularFrontera(solFrontera, raiz->left);
			calcularFrontera(solFrontera, raiz->right);
		}
	}
};