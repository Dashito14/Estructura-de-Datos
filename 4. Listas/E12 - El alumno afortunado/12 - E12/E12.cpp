#include "list_eda.h"

#include <iostream>
#include <fstream>

int alumnoPizarra(int n, int saltos){
	int alumno, r = 1;
	list <int> l;

	//Introducimos todos los alumnos en la lista
	for (int i = 0; i < n; i++){
		l.push_back(r);
		r = r + 1;		
	}

	//Colocamos el iterador al principio de la lista
	auto it = l.begin();

	//Mientras el tamaño no sea 1, seguimos recorriendo la lista para eliminar los elementos que toque
	while (l.size() != 1){
		int j = 0;

		//Hacemos el numero de saltos indicados para borrar el elemento
		while (j < saltos){

			//Si el iterador apunta al ultimo numero de la lista debemos hacer que el siguiente sea el primero
			if (*it == l.back()){
				it = l.begin();
			}
			else {
				++it;
			}
			++j;
		}

		//Si el iterador apunta al ultimo de la lista, como al borrar nos devuelve la siguiente posicion, seria nulo
		//por tanto debemos hacer que vuelva a estar al inicio de la lista
		if (*it == l.back()){
			it = l.erase(it);
			it = l.begin();
		}
		else {
			it = l.erase(it);
		}
	}

	//Sentencia que sobra pero deja mas clara la funcion
	//Igualamos el valor de retorno al elemento apuntado por el iterador, que es el unico que queda en la lista
	alumno = *it;

	return alumno;
}

bool resuelveCaso(){
	int n, saltos;

	std::cin >> n;
	std::cin >> saltos;

	if (n == 0 && saltos == 0)
		return false;

	std::cout << alumnoPizarra(n, saltos) << std::endl;

	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
	system("PAUSE");
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}
