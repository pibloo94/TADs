//PABLO AGUDO BRUN

#include "venta_libros.h"

ventas_libros::ventas_libros() {}

ventas_libros::~ventas_libros() {}

//Anade n ejemplares de un libro x al sistema. 
void ventas_libros::nuevoLibro(int n, string x) {
	auto it = mapLibros.find(x);
	
	if (it == mapLibros.end()) {
		//Si n toma el valor cero significa que el libro esta en el sistema, aunque no se tienen ejemplares disponibles.
		if (n == 0) {
			mapLibros[x] = 0;
		}
		else {
			mapLibros[x] = n;
		}
	}	
	//Si el libro ya esta en el sistema se anaden los ejemplares.
	else {
		mapLibros[x] += n;
	}
}

//Un usuario compra un libro x.
void ventas_libros::comprar(string x) {
	auto it = mapLibros.find(x);

	//Si el libro no esta dado de alta en el sistema se produce un error 
	if (it == mapLibros.end()) {
		throw std::invalid_argument("Libro no existente");
	}
	else {
		//Si no existen ejemplares disponibles del libro x se produce un error
		if (it->second == 0) {
			throw std::out_of_range("No hay ejemplares");
		}
		else {
			auto itC = mapCompras.find(x);

			if (itC == mapCompras.end()) {
				mapTop10[1].push_front(x);
				mapIteradores[x] = mapTop10[1].begin();
			}
			else {
				mapTop10[itC->second].erase(mapIteradores[x]); //elimino libro de mi top 10 ventas
				mapTop10[itC->second++].push_front(x); //actualizo su posicion en top 10
				mapIteradores.erase(x); //elimino el iterador
				mapIteradores[x] = mapTop10[itC->second].begin(); //actualizo el puntero
			}

			mapLibros[x]--;
			mapCompras[x]++;
		}
	}
}

//Indica si un libro x se ha anadido al sistema.
bool ventas_libros::estaLibro(string x) {
	auto it = mapLibros.find(x);
	bool esta = false;	//sera falso si no esta en el sistema

	//El resultado sera cierto si el libro esta en el sistema, aunque no haya ejemplares disponibles
	if (it != mapLibros.end()) {
		esta = true;
	}

	return esta;
}

//Elimina el libro x del sistema. 
void ventas_libros::elimLibro(string x) {
	auto it = mapCompras.find(x);

	//Si el libro no existe la operacion no tiene efecto.
	if (it != mapCompras.end()) {
		if (it->second > 0) {
			mapTop10[it->second].erase(mapIteradores[x]);
			mapIteradores.erase(x);
		}

		mapLibros.erase(x);
		mapCompras.erase(x);
	}
}

//Devuelve el numero de ejemplares de un libro x que hay disponibles en el sistema.
int ventas_libros::numEjemplares(string x) {
	auto it = mapLibros.find(x);
	int num;

	//Si el libro no esta dado de alta se produce un error
	if (it == mapLibros.end()) {
		throw std::invalid_argument("Libro no existente");
	}
	else {
		num = mapLibros[x];
	}

	return num;
}

//Obtiene una lista con los 10 libros que mas se han vendido.
std::vector<std::string> ventas_libros::top10() {
	/*La lista estara ordenada por numero de ventas, de mayor a menor, y los libros que se hayan 
	vendido el mismo numero de veces se ordenan del que tenga la venta mas reciente a la mas antigua, 
	hasta completar la lista de 10 libros.*/
	auto it = mapTop10.rbegin();
	std::vector<std::string> v(10);
	int i = 0;

	//Si no se han vendido 10 libros distintos se listaran todos ellos.
	while (it != mapTop10.rend() && i < 10) {
		auto itC = it->second.begin();

		while (itC != it->second.end() && i < 10) {
			v.push_back(* itC);
			i++;
			itC++;
		}

		it++;
	}

	return v;
}
