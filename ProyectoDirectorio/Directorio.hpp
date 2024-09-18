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

// Clase Nodo para representar un directorio
class Nodo {
public:
    string nombre;
    vector<Nodo*> hijos; // Para representar los subdirectorios

    Nodo(string _nombre);
};

// Clase Directorio que manejará el árbol de directorios
class Directorio {
private:
    Nodo* raiz;

    Nodo* buscarNodo(Nodo* actual, const string& nombre); // Buscar un nodo por su nombre
    void eliminarNodo(Nodo*& actual);                     // Eliminar un nodo y sus hijos
    void mostrarDirectorio(Nodo* actual, int nivel = 0);  // Mostrar los directorios de un nodo

public:
    Directorio(string nombreRaiz);                        // Constructor
    void agregar(const string& padre, const string& nombreNuevo); // Agregar un nuevo directorio
    string buscar(const string& nombre);                  // Buscar un directorio
    void eliminar(const string& nombre);                  // Eliminar un directorio
    void mostrar(const string& nombre);                   // Mostrar los subdirectorios de un directorio
};



#endif /* Directorio_hpp */
