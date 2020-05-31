#ifndef E46_H
#define E46_H

#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

using puntos = int;
using dni = std::string;

const int MAX = 15;

class carnet_puntos {
private:
	std::unordered_map<dni, puntos> carnet;
	std::vector<int> vec;

public:
	carnet_puntos() : vec(MAX + 1, 0) {};

	void nuevo(dni n) {
		auto it = carnet.find(n);

		if (it == carnet.end()) {
			carnet.insert({ n, 15 });
			vec[15]++;
		}
		else {
			throw std::domain_error("ERROR: Conductor duplicado");
		}
	}

	void quitar(dni n, puntos p) {
		auto it = carnet.find(n);

		if (it != carnet.end()) {
			vec[it->second] -= 1;

			it->second -= p;

			if (it->second < 0)
				it->second = 0;

			vec[it->second] += 1;
		}
		else {
			throw std::domain_error("ERROR: Conductor inexistente");
		}
	}

	puntos consultar(dni n) {
		auto it = carnet.find(n);

		if (it != carnet.end()) {
			return it->second;
		}
		else {
			throw std::domain_error("ERROR: Conductor inexistente");
		}
	}

	int cuantos_con_puntos(puntos p) {
		if (p >= 0 && p < 16) {
			return vec[p];
		}
		else {
			throw std::domain_error("ERROR: Puntos no validos");
		}
	}
};


#endif