//Daniel Ibañez Padial
//A38

//El coste del programa logaritmico, estan comentados los costes de las funciones a lo largo de todo el programa. Al tener funciones como
//find(), end() u operator[] de la clase map. Todas estas tienen coste logaritmico y aunque el resto de funciones de la clase vector como
//push_back u operator[] son constantes, el programa es logaritmico

#include "EvaContinua.h"

bool resuelveCaso() {
	int N, M, a;
	//Un diccionario con un string con el nombre del sensor y un vector con las horas de forma ordenada
	std::map<sensor, std::vector<hora>> r; //Crear un diccionario tiene coste constante

	sensor nombre;
	hora h;

	//Introducimos el numero de sensores que han llegado
	std::cin >> N;

	//Si no se escribe no hay mas casos de prueba y se acaba
	if (!std::cin)
		return false;

	//Introducimos el numero de sensores que se quieren consultar para despues
	std::cin >> M;

	int i = 0;

	//Minetras se hayan dado menos vueltas que el numero de sensores que han llegado entramos
	//Este bucle inserta los sensores en el diccionario con sus horas correspondientes
	while (i < N) {
		//Escribimos el nombre del sensor y la hora de llegada
		std::cin >> nombre >> h;

		//Si no encontramos el nombre del sensor es que es nuevo y por tanto debemos insertarlo
		if (r.find(nombre) == r.end()) { //find en map tiene complejidad logaritmica por tamaño //end() tiene complejidad constante
			//Insertamos el sensor con el vector vacio
			r.insert({ nombre, {} }); //insert() es logaritmica en tamaño

			//Insertamos la primera hora en el vector correspondiente
			r[nombre].push_back(h); //operator[] coste logaritmico //push_back constante
		}
		else {
			//Si el sensor ya existia simplemente introducimos el valor
			r[nombre].push_back(h); //operator[] coste logaritmico //push_back constante
		}

		i++;
	}

	i = 0;

	//Mientras no hayamos dado tantas vueltas como consultas se quieren realizar entramos en el bucle
	//Este bucle muestra por pantalla la informacion requerida
	while (i < M) {
		//Introducimos el nombre que queremos consultar y que numero ordinal
		std::cin >> nombre >> a;

		//Si no existe el sensor que queremos consultar mostramos los guiones
		if (r.find(nombre) == r.end()) { //find() en map tiene complejidad logaritmica por tamaño
			std::cout << "-- ";	
		}
		else {
			//Si el numero ordinal del sensor es mas grande que el numero de elementos que tenemos en el vector tambien escribimos guiones
			if (a > r[nombre].size()) { //operator[] coste logaritmico
				std::cout << "-- ";
			}
			else {
				//Si no se cumple lo anterior escribimos la hora asociada al ordinal del sensor que queremos mostrar
				std::cout << r[nombre][a - 1] << " "; //operator[] coste logaritmico //operator[] vector constante
			}
		}
		i++;
	}

	std::cout << std::endl;

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
