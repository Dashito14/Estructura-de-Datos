#include "E38.h"
#include <vector>

bool resuelveCaso(int& casos) {
	if (casos == 0)
		return false;

	casos--;

	//Declaramos los dos diccionarios que tensmo por caso de prueba
	std::map<titulo, val> viejoDic;
	std::map<titulo, val> nuevoDic;

	//Declaramos un vector por cada tipo que tenemos
	//mas: se ha anadido un par al nuevo diccionario
	//menos: se ha eliminado un par en el nuevo diccionario
	//mult: se ha sumado en algun par existente
	std::vector<titulo> mas;
	std::vector<titulo> menos;
	std::vector<titulo> mult;

	//Lectura de los diccionarios utilizando sstream
	std::string cadena, cadena2;

	std::getline(std::cin, cadena); //Lee la linea del viejo diccionario
	std::getline(std::cin, cadena2); //Lee la linea del nuevo diccionario

	std::stringstream s1(cadena); //Copia la cadena en ss
	std::stringstream s2(cadena2); //Copia la cadena en ss

	std::string letra; int valor;

	s1 >> letra >> valor;  // obtiene de s1 letra y valor
	while (s1) { // Mientras no se acabe la linea
		viejoDic[letra] = valor;
		s1 >> letra >> valor;
	}



	s2 >> letra >> valor;
	while (s2) {
		nuevoDic[letra] = valor;
		s2 >> letra >> valor;
	}

	//Inicializamos un iterador al inicio del viejo diccionario
	auto itV = viejoDic.begin();

	//Mientras no llegue al final del diccionario entramos en el bucle
	while (itV != viejoDic.end()) {
		//Buscamos en el nuevo diccionario la clave del viejo diccionario por el que va el iterador
		auto act = nuevoDic.find(itV->first);

		//Si el iterador apunta al final es que no esta en el nuevo diccionario, por eso lo almacenamos en el vector menos
		if (act == nuevoDic.end()) {
			menos.push_back(itV->first);
		}

		//Si no apunta al final es que si que esta
		else {
			//Si los valores de las mismasa claves en los dos diccionarios son distintas se anade al vector mult
			if (itV->second != act->second) {
				mult.push_back(itV->first);
			}

			//Borramos el par del nuevo diccionario para comprobar los valores nuevos que se han anadido
			nuevoDic.erase(act);
		}

		itV++;
	}

	//Se declara un iterador al inicio del nuevo diccionario
	auto itN = nuevoDic.begin();

	//Mientras no se llegue al final del diccionario sera valores que no estaban en el diccionario antoguo
	while (itN != nuevoDic.end()) {
		mas.push_back(itN->first);
		itN++;
	}

	//Si todos los vectores estan vacios es que no hay cambios
	if (mas.empty() && mult.empty() && menos.empty()) {
		std::cout << "Sin cambios" << std::endl;
	}
	else {
		//Si hay valores en el vector mas
		if (!mas.empty()) {
			std::cout << '+';

			int i = 0;

			while (i < mas.size()) {
				std::cout << " " << mas[i];
				i++;
			}

			std::cout << std::endl;
		}
		//si hay valores en el vector menos
		if (!menos.empty()) {
			std::cout << '-';

			int i = 0;

			while (i < menos.size()) {
				std::cout << " " << menos[i];
				i++;
			}

			std::cout << std::endl;
		}
		//si hay valores en el vector mult
		if (!mult.empty()) {
			std::cout << '*';

			int i = 0;

			while (i < mult.size()) {
				std::cout << " " << mult[i];
				i++;
			}

			std::cout << std::endl;
		}
	}

	std::cout << "---" << std::endl;
	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos;
	std::cin >> casos;
	std::cin.ignore();

	while (resuelveCaso(casos));
	system("PAUSE");
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
