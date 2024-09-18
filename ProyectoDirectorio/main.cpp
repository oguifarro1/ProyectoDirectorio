//
//  main.cpp
//  ProyectoDirectorio
//
//  Created by Oscar Guifarro on 18/9/24.
//

#include <iostream>
#include "Directorio.hpp"

int main() {
    Directorio D1("C:");

    D1.agregar("C:", "Carpeta1");
    D1.agregar("C:", "Carpeta2");
    D1.agregar("C:", "Carpeta3");
    D1.agregar("Carpeta3", "Sub1");
    D1.agregar("Sub1", "otra");
    D1.agregar("otra", "otra_mas");

    D1.mostrar("C:");
    cout << D1.buscar("otra") << endl;
    D1.eliminar("Carpeta3");
    D1.mostrar("C:");

    return 0;
}

 
