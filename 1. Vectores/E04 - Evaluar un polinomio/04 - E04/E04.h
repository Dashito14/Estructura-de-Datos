#ifndef E04_H
#define E04_H

#include <vector>
#include <iostream>
#include <utility>
#include <math.h>
#include <algorithm>

typedef std::pair<int, int> monomio;

class Polinomio {
private:



public:

	std::vector<monomio> v_monomios;

	void anadirMonomio(monomio m) {
		int pos = 0;

		if (m.first == 0)
			return;

		if (v_monomios.size() != 0){
			if (existeExponente(m.second, 0, v_monomios.size(), pos)) {
				sumaExponentes(m.first, pos);
			}
			else {
				insertar(m);
			}
		}
		else {
			insertar(m);
		}
	};

	bool existeExponente(int e, int inicio, int fin, int &pos) {
		/*
		auto pos = std::lower_bound(v_monomios.begin(), v_monomios.end(), e);
		*/
		int i = (fin - inicio) / 2;
		if (fin <= inicio){
			return false;
		}
		if (v_monomios[i].second == e){
			pos = i;
			return true;
		}
		if (v_monomios[i].second > e){
			return existeExponente(e, i, fin - 1, pos);
		}
		else {
			return existeExponente(e, inicio, i, pos);
		}
		/*
		int i = 0;

		if (v_monomios.size() == 0){o
			return false;
		}

		while (i < v_monomios.size()
			&& e > v_monomios[i].second) {
			i++;
		}

		if (i == v_monomios.size()){
			return false;
		}
		return e == v_monomios[i].second;*/
	};

	void sumaExponentes(int m, int pos) {
		this->v_monomios[pos].first += m;
	}

	void insertar(monomio m) {
		int i = this->v_monomios.size();
		bool ins = false;

		while ( i > 0 && !ins) {
			if (v_monomios[i - 1].second < m.second) {
				if (i == this->v_monomios.size()){
					v_monomios.push_back(v_monomios[i - 1]);
				}
				else {
					v_monomios[i] = v_monomios[i - 1];
				}
				i--;
			}
			else {
				ins = true;
			}
			
		}
		if (v_monomios.size() == i){
			v_monomios.push_back(m);
			return;
		}
		v_monomios[i] = m;
	}

	int resolverPolinomio(int x) const {
		int i = 0;
		int c, s;
		s = 0;
		while (i < v_monomios.size()) {
			c = pow(x, v_monomios[i].second);
			s += c * v_monomios[i].first;
			i++;
		}
		return s;
	}
};

#endif