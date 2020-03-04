#include <iostream>
#include <fstream>
#include <string>
#include <stack>

#include "list_eda.h"

bool es_vocal(char const c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;

	return false;
}

void volcar_pila(std::stack<char> & pila, std::string &resultado) {
	while (!pila.empty()) {
		resultado.push_back(pila.top());
		pila.pop();
	}
}

std::string decodifica(std::string const& mensaje) {
	//Volcamos todo el mensaje en una cola doble
	deque<char> X, Y;
	int i = 0;

	std::string segfase;

	while (i < mensaje.size()){
		X.push_back(mensaje[i]);
		i++;
	}

	//Deshacemos la segunda fase
	//Segunda fase: En segundo lugar, X se transforma en la sucesión de caracteres X
	//obtenida al ir tomando sucesivamente el primer carácter de X luego el
	//último, luego el segundo, luego el penúltimo, etc.
	int cont = 0;

	//Mientras no se haya acabado la palabra
	while (!X.empty()) {
		//Ponemos el primer elemento de la cola al final de la palabra
		segfase.push_back(X.front()); 
		//Quitamos el elemento de la cola que hemos puesto en la palabra
		X.pop_front();

		//Si la cola no está vacia
		if (!X.empty()){
			//Ponemos en la cola auxiliar el siguiente elemento al que hemos puesto en la palabra
			Y.push_back(X.front());
			//Quitamos el elemento que hemos puesto en la cola auxiliar de la cola principal
			X.pop_front();
		}
	}

	//Despues de haber realizado todo el proceso anterior solo tenemos que meter todos los elementos
	//de la cola auxiliar en orden inverso a la palabra
	while (!Y.empty()){
		segfase.push_back(Y.back());
		Y.pop_back();
	}
	
	//Deshacemos la primera fase
	//Primera fase: en primer lugar, X se transforma en X reemplazando cada sucesión de caracteres
	//consecutivos que no sean vocales por su inversa
	i = 0;
	std::string resultado;
	std::stack<char> pila_consonantes;

	while (i < segfase.size()){
		if (es_vocal(segfase[i])){
			volcar_pila(pila_consonantes, resultado);
			resultado.push_back(segfase[i]);
		}
		else {
			pila_consonantes.push(segfase[i]);
		}
		i++;
	}

	//Por si aun quedara algun elemento en la pila, lo volcamos en el resultado
	if (!pila_consonantes.empty()){
		volcar_pila(pila_consonantes, resultado);
	}
	return resultado;
}

bool resuelveCaso(){
	std::string frase;

	std::getline(std::cin, frase);

	if (!std::cin)
		return false;

	std::cout << decodifica(frase) << std::endl;


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