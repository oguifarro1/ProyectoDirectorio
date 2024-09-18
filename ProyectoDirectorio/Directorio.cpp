//
//  Directorio.cpp
//  ProyectoDirectorio
//
//  Created by Oscar Guifarro on 18/9/24.
//

#include "Directorio.hpp"


// Constructor de la clase Nodo
Nodo::Nodo(string _nombre) : nombre(_nombre) {
    // No es necesario realizar ninguna acción adicional aquí
}

// Constructor de la clase Directorio
Directorio::Directorio(string nombreRaiz) {
    raiz = new Nodo(nombreRaiz);
}

// Método para buscar un nodo por su nombre
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

// Método para agregar un nuevo directorio
void Directorio::agregar(const string& padre, const string& nombreNuevo) {
    Nodo* nodoPadre = buscarNodo(raiz, padre);
    if (nodoPadre) {
        nodoPadre->hijos.push_back(new Nodo(nombreNuevo));
        cout << "Directorio '" << nombreNuevo << "' agregado a '" << padre << "'." << endl;
    } else {
        cout << "Directorio padre '" << padre << "' no encontrado." << endl;
    }
}

// Método para buscar un directorio
string Directorio::buscar(const string& nombre) {
    Nodo* encontrado = buscarNodo(raiz, nombre);
    if (encontrado) {
        return "Directorio encontrado: " + encontrado->nombre;
    } else {
        return "Directorio no encontrado.";
    }
}

// Método para eliminar un nodo y sus subdirectorios
void Directorio::eliminarNodo(Nodo*& actual) {
    for (Nodo* hijo : actual->hijos) {
        eliminarNodo(hijo);
    }
    delete actual;
    actual = nullptr;
}

// Método para eliminar un directorio y sus subdirectorios
void Directorio::eliminar(const string& nombre) {
    Nodo* nodoEliminar = buscarNodo(raiz, nombre);
    if (nodoEliminar) {
        eliminarNodo(nodoEliminar);
        cout << "Directorio '" << nombre << "' y sus subdirectorios han sido eliminados." << endl;
    } else {
        cout << "Directorio '" << nombre << "' no encontrado." << endl;
    }
}

// Método para mostrar los subdirectorios de un nodo
void Directorio::mostrarDirectorio(Nodo* actual, int nivel) {
    for (int i = 0; i < nivel; ++i) {
        cout << "\t";
    }
    cout << actual->nombre << endl;
    for (Nodo* hijo : actual->hijos) {
        mostrarDirectorio(hijo, nivel + 1);
    }
}

// Método para mostrar un directorio y sus subdirectorios
void Directorio::mostrar(const string& nombre) {
    Nodo* nodoMostrar = buscarNodo(raiz, nombre);
    if (nodoMostrar) {
        mostrarDirectorio(nodoMostrar);
    } else {
        cout << "Directorio '" << nombre << "' no encontrado." << endl;
    }
}
