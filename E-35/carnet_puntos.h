//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;


class carnet_puntos {
private:
	std::unordered_map<std::string, int> mapConductores;
	std::unordered_map<int, std::list<std::string>> mapConductoresPorPuntos;
	std::unordered_map<std::string, std::list<std::string>::iterator> mapIteradores;
	std::vector<int> listaPuntos;

public:
	carnet_puntos();
	void nuevo(std::string DNI);
	void quitar(std::string DNI, int puntos);
	void recuperar(std::string DNI, int puntos);
	int consultar(std::string DNI);
	int cuantos_con_puntos(int puntos);
	std::vector<std::string> lista_por_puntos(int puntos);
};