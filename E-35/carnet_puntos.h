//PABLO AGUDO BRUN

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std;


class carnet_puntos {
private:


public:
	void nuevo(std::string DNI);
	void quitar(std::string DNI, int puntos);
	void recuperar(std::string DNI, int puntos);
	int consultar(std::string DNI);
	std::vector<int> cuantos_con_puntos(int puntos);
	std::vector<std::string> listar_por_puntos();
};