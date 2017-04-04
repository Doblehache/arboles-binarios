#include <cassert>
#include "Abin_enla.h"

//Árboles similares
template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B) {
    return similaresRec(A.raizB(), A, B.raizB(), B);
}

template <typename T>
bool similaresRec(typename Abin<T>::nodo na, const Abin<T>& A, typename Abin<T>::nodo nb, const Abin<T>& B) {
    if (na == Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO)
		return true;
	else {
		if ((na != Abin<T>::NODO_NULO && nb == Abin<T>::NODO_NULO) ||
			(na == Abin<T>::NODO_NULO && nb != Abin<T>::NODO_NULO))
			return false;
		else
			return similaresAbinRec(A.hijoIzqdoB(na), A, B.hijoIzqdoB(nb), B) &&
				   similaresAbinRec(A.hijoDrchoB(na), A, B.hijoDrchoB(nb), B);
	}
}

//Árbol reflejado
template <typename T>
Abin<T> reflejado(const Abin<T>& A) {
    Abin<T> B;
    if (!A.arbolVacioB()) {
        B.insertarRaizB(A.elemento(A.raizB()));
        reflejadoRec(A.raizB(), A, B.raizB(), B);
    }
    return B;
}

template <typename T>
void reflejadoRec(typename Abin<T>::nodo na, const Abin<T>& A, typename Abin<T>::nodo nb, Abin<T>& B) {
    if (A.hijoIzqdoB(na) != Abin<T>::NODO_NULO) {
        B.insertarHijoDrchoB(nb, A.elemento(A.hijoIzqdoB(na)));
        reflejadoRec(A.hijoIzqdoB(na), A, B.hijoDrchoB(nb), B);
    }
    if (A.hijoDrchoB(nb) != Abin<T>::NODO_NULO) {
        B.insertarHijoIzqdoB(nb, A.elemento(A.hijoDrchoB(na)));
        reflejadoRec(A.hijoDrchoB(na), A, B.hijoIzqdoB(nb), B);
    }
}

//Árbol de expresión
struct expresion {
    char operador;
    double operando;
};

template <typename T>
double calculo(const Abin<T>& A) {
    if (A.arbolVacioB())
        return 0;
    else
        return calculoRec(A.raizB(), A);
}

template <typename T>
double calculoRec(typename Abin<T>::nodo n, const Abin<T>& A) {
    double res;
    if (A.hijoIzqdoB(n) == Abin<expresion>::NODO_NULO  && A.hijoDrchoB(n) == Abin<expresion>::NODO_NULO)
        res = A.elemento(n).operando;
    else {
        switch (A.elemento(n).operador) {
            case '+':
                res = calculoRec(A.hijoIzqdoB(n), A) + calculoRec(A.hijoDrchoB(n), A);
                break;
            case '-':
                res = calculoRec(A.hijoIzqdoB(n), A) - calculoRec(A.hijoDrchoB(n), A);
                break;
            case '*':
                res = calculoRec(A.hijoIzqdoB(n), A) * calculoRec(A.hijoDrchoB(n), A);
                break;
            case '/':
                res = calculoRec(A.hijoIzqdoB(n), A) / calculoRec(A.hijoDrchoB(n), A);
                break;
        }
    }
    return res;
}











//
