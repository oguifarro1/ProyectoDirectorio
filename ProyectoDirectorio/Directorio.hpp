//
//  Directorio.hpp
//  ProyectoDirectorio
//
//  Created by Oscar Guifarro on 18/9/24.
//

#ifndef Directorio_hpp
#define Directorio_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nodo {
public:
    string nombre;
    vector<Nodo*> hijos;
    Nodo(string _nombre);
};

class Directorio {
private:
    Nodo* raiz;

    Nodo* buscarNodo(Nodo* actual, const string& nombre);
    void eliminarNodo(Nodo*& actual);
    void mostrarDirectorio(Nodo* actual, int nivel = 0);

public:
    Directorio(string nombreRaiz);
    void agregar(const string& padre, const string& nombreNuevo);
    string buscar(const string& nombre);
    void eliminar(const string& nombre);
    void mostrar(const string& nombre);                   
};



#endif /* Directorio_hpp */
