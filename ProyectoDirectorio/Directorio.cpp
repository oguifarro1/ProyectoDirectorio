//
//  Directorio.cpp
//  ProyectoDirectorio
//
//  Created by Oscar Guifarro on 18/9/24.
//

#include "Directorio.hpp"


Nodo::Nodo(string _nombre) : nombre(_nombre) {
}

Directorio::Directorio(string nombreRaiz) {
    raiz = new Nodo(nombreRaiz);
}

Nodo* Directorio::buscarNodo(Nodo* actual, const string& nombre) {
    if (actual->nombre == nombre) {
        return actual;
    }
    for (Nodo* hijo : actual->hijos) {
        Nodo* encontrado = buscarNodo(hijo, nombre);
        if (encontrado) return encontrado;
    }
    return nullptr;
}

void Directorio::agregar(const string& padre, const string& nombreNuevo) {
    Nodo* nodoPadre = buscarNodo(raiz, padre);
    if (nodoPadre) {
        nodoPadre->hijos.push_back(new Nodo(nombreNuevo));
        cout << "Directorio '" << nombreNuevo << "' agregado a '" << padre << "'." << endl;
    } else {
        cout << "Directorio padre '" << padre << "' no encontrado." << endl;
    }
}

string Directorio::buscar(const string& nombre) {
    Nodo* encontrado = buscarNodo(raiz, nombre);
    if (encontrado) {
        return "Directorio encontrado: " + encontrado->nombre;
    } else {
        return "Directorio no encontrado.";
    }
}

void Directorio::eliminarNodo(Nodo*& actual) {
    for (Nodo* hijo : actual->hijos) {
        eliminarNodo(hijo);
    }
    delete actual;
    actual = nullptr;
}

void Directorio::eliminar(const string& nombre) {
    Nodo* nodoEliminar = buscarNodo(raiz, nombre);
    if (nodoEliminar) {
        eliminarNodo(nodoEliminar);
        cout << "Directorio '" << nombre << "' y sus subdirectorios han sido eliminados." << endl;
    } else {
        cout << "Directorio '" << nombre << "' no encontrado." << endl;
    }
}

void Directorio::mostrarDirectorio(Nodo* actual, int nivel) {
    for (int i = 0; i < nivel; ++i) {
        cout << "\t";
    }
    cout << actual->nombre << endl;
    for (Nodo* hijo : actual->hijos) {
        mostrarDirectorio(hijo, nivel + 1);
    }
}

void Directorio::mostrar(const string& nombre) {
    Nodo* nodoMostrar = buscarNodo(raiz, nombre);
    if (nodoMostrar) {
        mostrarDirectorio(nodoMostrar);
    } else {
        cout << "Directorio '" << nombre << "' no encontrado." << endl;
    }
}
