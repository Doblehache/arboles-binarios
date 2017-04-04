#include <cassert>
#include "Abin_enla.h"

//Número de nodos del árbol
template <typename T>
int numNodos(const Abin<T>& A) {
    return numNodos(A.raizB(), A);
}

template <typename T>
int numNodosRec(typename Abin<T>::nodo n, const Abin<T>& A) {
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodosRec(A.hijoIzqdoB(n), A) + numNodosRec(A.hijoDrchoB(n), A);
}

//Altura del árbol binario
template <typename T>
int altura(const Abin<T>& A) {
    return alturaRec(A.raizB(), A);
}

template <typename T>
int alturaRec(typename Abin<T>::nodo n, const Abin<T>& A) {
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + (max(alturaRec(A.hijoIzqdoB(n), A), alturaRec(A.hijoDrchoB(n), A)));
}

//Profundidad de un nodo
template <typename T>
int profundidad(typename Abin<T>::nodo n) {
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + profundidad(padre(n));
}

//Nivel de desequilibrio
template <typename T>
int desequilibrio(const Abin<T>& A) {
    return desequilibrioRec(A.raizB(), A);
}

template <typename T>
int desequilibrioRec(typename Abin<T>::nodo n, const Abin<T>& A) {
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else {
        return max(abs(alturaRec(hijoIzqdoB(n), A) - alturaRec(hijoDrchoB(n), A)),
        max(desequilibrioAbinRec(A.hijoIzqdoB(n), A), desequilibrioAbinRec(A.hijoDrchoB(n), A)));
    }
}

//Pseudocompleto
template <typename T>
bool esPseudocompleto(Abin<T>& A) {
    if (A.arbolVacioB() || (A.hijoIzqdoB(A.raizB()) == Abin<T>::NODO_NULO &&
                            A.hijoDrchoB(A.raizB()) == Abin<T>::NODO_NULO))
        return true;
    else
        return esPseudocompletoRec(A.raizB(), A);
}

template <typename T>
bool esPseudocompletoRec(typename Abin<T>::nodo n, const Abin<T>& A) {
    int altIzq, altDer;
    if (n == Abin<T>::NODO_NULO)
        return A.hijoIzqdoB(A.raizB()) != Abin<T>::NODO_NULO && A.hijoDrchoB(A.raizB()) != Abin<T>::NODO_NULO;
    else {
        altIzq = alturaAbinRec(A.hijoIzqdoB(A.raizB()), A);
        altDer = alturaAbinRec(A.hijoDrchoB(A.raizB()), A);

        if (altIzq > altDer)
            return esPseudocompletoRec(A.hijoIzqdoB(A.raizB()), A);
        else if (altIzq < altDer)
            return esPseudocompletoRec(A.hijoDrchoB(A.raizB()), A);
        else
            return esPseudocompletoRec(A.hijoIzqdoB(A.raizB()), A) && esPseudocompletoRec(A.hijoDrchoB(A.raizB()), A);
    }
}

//Buscar nodos
template <typename T>
typename Abin<T>::nodo buscarNodo(const T& e, const Abin<T>& A) {
    return buscarNodoRec(e, A.raizB(), A);
}

template <typename T>
typename Abin<T>::nodo buscarNodoRec(const T& e, typename Abin<T>::nodo n, const Abin<T>& A) {
    if (elemento(n) == e)
        return n;
    else {
        buscarNodoRec(e, A.hijoIzqdoB(n), A);
        buscarNodoRec(e, A.hijoDrchoB(n), A);
    }
}





















//
