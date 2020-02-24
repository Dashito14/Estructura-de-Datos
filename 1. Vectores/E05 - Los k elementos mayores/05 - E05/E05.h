//
// conjunto.h
//
#ifndef E05_H
#define E05_H
#include <stdexcept> // std::domain_error
#include <utility> // std::move
#include<functional>
template <class T>
class set {
public:
	set(int tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T>& operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T const & e) const;
	void erase(T e);
	bool empty() const;
	int size() const;
	T const& min() const {
		return datos[contador - 1];
	};
	void erase_min() {
		--contador;
	};
	T get_datos(int i) const;
private:
	const static int TAM_INICIAL = 8;
	int contador;
	int capacidad;
	T* datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
};
template <class T>
set<T>::set(int tam) : contador(0), capacidad(tam), datos(new
	T[capacidad]) {}
template <class T>
set<T>::~set() {
	libera();
}
template <class T>
void set<T>::libera() {
	delete[] datos;
}
/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}
/** Operador de asignación */
template <class T>
set<T>& set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}
template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (int i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}
template <class T>
void set<T>::insert(T e) {
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();
		/*-*/
		int p = contador;
		while (p > 0 && datos[p - 1] < e) {
			datos[p] = datos[p - 1];
			--p;
		}
		/*-*/
		datos[p] = e;
		++contador;
	}
}
template <class T>
bool set<T>::contains(T const &e) const {
	
	auto pos = std::lower_bound(datos, datos + contador + 1, e, std::greater<T>());
	/*
	
	int i = 0;
	while (i < contador && datos[i] != e)
	++i;
	return i < contador;
	*/
	return pos != datos + contador + 1 && *pos == e;
	
}
template <class T>
void set<T>::amplia() {
	T* nuevos = new T[2 * capacidad];
	for (int i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}
template <class T>
void set<T>::erase(T e) {
	auto pos = std::lower_bound(datos, datos + contador, e);
	if (pos != datos + contador) {
		int i = pos - datos;
		while (i < contador - 1) {
			datos[i] = datos[i + 1];
			++i;
		}
	}
	else
		throw std::domain_error("El elemento no esta");
}
template <class T>
bool set<T>::empty() const {
	return contador == 0;
}
template <class T>
int set<T>::size() const {
	return contador;
}
template <class T>
T set<T>::get_datos(int i) const {
	return datos[i];
}
#endif // conjunto_h