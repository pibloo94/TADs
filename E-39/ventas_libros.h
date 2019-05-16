//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

class ventas_libros{

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

};

