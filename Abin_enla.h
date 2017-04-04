/**
Declaración de la clase Árbol Binario.
*/

#ifndef ABIN_H
#define ABIN_H
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Abin {
	struct celda; // declaración adelantada privada
public:
	typedef celda* nodo;
	static const nodo NODO_NULO;
	Abin(); // constructor
	void insertarRaizB(const T& e);
	void insertarHijoIzqdoB(nodo n, const T& e);
	void insertarHijoDrchoB(nodo n, const T& e);
	void eliminarHijoIzqdoB(nodo n);
	void eliminarHijoDrchoB(nodo n);
	void eliminarRaizB();
	int profundidadNodo(typename Abin<T>::nodo n);
	~Abin(); // destructor
	bool arbolVacioB() const;
	const T& elemento(nodo n) const; // acceso a elto, lectura
	T& elemento(nodo n); // acceso a elto, lectura/escritura
	nodo raizB() const;
	nodo padreB(nodo n) const;
	nodo hijoIzqdoB(nodo n) const;
	nodo hijoDrchoB(nodo n) const;
	Abin(const Abin<T>& a); // ctor. de copia
	Abin<T>& operator =(const Abin<T>& a); //asignación de árboles
private:
	struct celda {
		T elto;
		nodo padre, hizq, hder;
		celda(const T& e, nodo p = NODO_NULO): elto(e), padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
	};
	nodo r; // nodo raíz del árbol
	void destruirNodos(nodo& n);
	nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);
