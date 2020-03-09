#pragma once
#ifndef E03_H
#define E03_H

#include <math.h>
#include <fstream>
#include <iostream>

class Complejo {
private:
	float real, imaginaria;

public:
	Complejo() {};
	Complejo(float r, float i) : real(r), imaginaria(i) {};

	//(a+bi) + (c+di) = (a+c) + (b+d)i
	Complejo operator+(Complejo const& other) const {
		float re = real + other.real;
		float im = imaginaria + other.imaginaria;

		Complejo c(re, im);
		return c;
	};

	//(a + bi) * (c + di) = (a*c - b * d) + (a*d + c * b)i
	Complejo operator*(Complejo const& other) const {
		float re = (real * other.real) - (imaginaria * other.imaginaria);
		float im = (real * other.imaginaria) + (other.real * imaginaria);

		Complejo c(re, im);
		return c;
	};

	float get_real() const { return real; };
	float get_imaginaria() const { return imaginaria; };
};

//mod(a + bi) = sqrt(a2 + b2)
int mod(Complejo const& other) {
	return sqrt(pow(other.get_real(), 2) + pow(other.get_imaginaria(), 2));
};

#endif