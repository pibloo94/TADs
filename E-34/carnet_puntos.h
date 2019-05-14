//PABLO AGUDO BRUN	

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <map>

using namespace std;


class carnet_puntos {

private:
	std::unordered_map<std::string, int> mapConductores;
	std::vector<int> listaPuntosTotal;

public:
	carnet_puntos();
	void nuevo(std::string DNI);
	void quitar(std::string DNI, int punt);
	int consultar(std::string DNI);
	int cuantos_con_puntos(int punt);

};