#include "E16.h"

bool resuelveCaso() {
	int max, min, nPersonas, edad;
	std::string nombre;

	std::cin >> nPersonas >> min >> max;

	//Se acaba la entrada
	if (nPersonas == 0 && min == 0 && max == 0)
		return false;

	Lista<Persona> l;

	for (int i = 0; i < nPersonas; i++) {
		std::cin >> edad;
		//Si no incluimos el ignore, el getline va a coger un espacio en blanco
		std::cin.ignore();
		std::getline(std::cin, nombre);


		Persona p(edad, nombre);
		//Introducimos la persona en la lista
		l.push_back(p);
		//Comprobamos si esta última persona debe estar incluida en la lista
		
	}
	l.remove_if([min, max](Persona p) { return (p.getE() >= min && p.getE() <= max); });
	//Sacamos por pantalla la lista
	l.print();

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