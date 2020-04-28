#ifndef E36_h
#define E36_h

#include <string>
#include <map>
#include <iostream>

using nombre = std::string;

class evaluacion {
private:
	std::map<nombre, int> alum;
public:
	evaluacion() {};

	void ver_solucion(nombre n, std::string sol) {
		if (sol == "CORRECTO") {
			++alum[n];
		}
		else {
			--alum[n];
		}
	}

	void mostrar() {
		for (auto const& par : alum) {
			if (par.second != 0) {
				std::cout << par.first << ", " << par.second << std::endl;
			}
		}
	}
};

#endif