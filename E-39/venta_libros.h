//PABLO AGUDO BRUN

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <queue>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class ventas_libros {

public:
	ventas_libros();
	~ventas_libros();
	void nuevoLibro(int n, string x);
	void comprar(string x);
	bool estaLibro(string x);
	void elimLibro(string x);
	int numEjemplares(string x);
	std::vector<std::string> top10();

private:
	std::unordered_map<std::string, int> mapLibros;
	std::unordered_map<std::string, int > mapCompras;
	std::map<int, list<std::string>> mapTop10;
	std::unordered_map<std::string, list<std::string>::iterator> mapIteradores;

};

