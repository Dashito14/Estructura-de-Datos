#include "E37.h"

void resuelveCaso(std::map<capitulos, posicion> s) {
	//Declaramos todas las variables que vamos a utilizar
	int caps, nCap;
	int max = 0;
	int ini = 0;
	int fin = 0;
	int actual;

	//Escribimos el numero de capitulos
	std::cin >> caps;

	//Damos una vuelta por cada capitulo
	for (int j = 0; j < caps; j++) {
		//Introducimos el numero del capitulo
		std::cin >> nCap;

		//Si el capitulo ya estaba en la lista
		if (s.count(nCap) > 0) {
			//Si el contador de inicio se encuentra por detras de la posicion en la que se encuentra este capitulo
			if (ini < s.at(nCap) + 1) {
				//Ponemos el contador en el capitulo que se emitio el dia despues al que se repite
				ini = s.at(nCap) + 1;
			}
			//Sustituimos el valor asociado a la clave con el numero de capitulo, la j es cada dia de emision por eso lo utilizamos como posicion
			s.at(nCap) = j;
		}
		else {
			//Si no estaba en la lista insertamos el par con el numero del capitulo y el dia que se emitio desde que empezo a contar
			s.insert(std::pair<capitulos, posicion>(nCap, j));
		}
		//Ponemos el fin al dia actual
		fin = j;
		//La racha actual de capitulos sin repeticion es el dia en el que estamos, menos en el que tenemos el posicionamiento ini más 1
		actual = fin - ini + 1;
		//Si la racha actual es mayor que la máxima la cambiamos
		if (actual > max) {
			max = actual;
		}
	}

	//Mostramos por pantalla
	std::cout << max << std::endl;
	//Limpiamos el map
	s.clear();
	
}


bool se(int s) {
	//Declaramos el map
	std::map<capitulos, posicion> sr;
	//Damos una vuelta por cada caso, es decir por cada serie
	for (int i = 0; i < s; i++) {
		resuelveCaso(sr);
	}
	//Cuando acabemos se acaba el programa
	return false;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int series;
	std::cin >> series;
	while (se(series));
	system("PAUSE");
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}