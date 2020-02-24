#include "stack_eda.h"

#include <iostream>
#include <fstream>
#include <string>

bool resuelveCaso(){
	std::string cadena;
	stack<char> pila;

	std::getline(std::cin, cadena);
	if (!std::cin){
		return false;
	}

	int i = 0;
	while (i < cadena.size()){
		//Si el caracter que viene es uno de apertura se incluye directamente en la pila
		if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{'){
			pila.push(cadena[i]);
		}
		//Si el caracter que viene es uno que cierra debemos comprobar si el anterior
		//es uno del mismo tipo que abre, para poder quitarlo de la pila
		else if (cadena[i] == ')'){
			if (!pila.empty() && pila.top() == '('){
				pila.pop();
			}
			else {
				pila.push(cadena[i]);
			}
		}
		else if (cadena[i] == ']'){
			if (!pila.empty() && pila.top() == '['){
				pila.pop();
			}
			else {
				pila.push(cadena[i]);
			}
		}
		else if(cadena[i] == '}'){
			if (!pila.empty() && pila.top() == '{'){
				pila.pop();
			}
			else {
				pila.push(cadena[i]);
			}
		}
		i++;
	}

	if (pila.empty()){
		std::cout << "SI" << std::endl;
	}
	else{
		std::cout << "NO" << std::endl;
	}

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