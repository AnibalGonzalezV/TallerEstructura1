#pragma once
#include <iostream>

using namespace std;

class Asistente {
    protected:
    string nombre, dni;
    int edad;
    public:
    Asistente(string nombre,string dni, int edad);
    ~Asistente();

    virtual string mostrarInformacion() = 0;
    virtual string informacionParaArchivo() = 0;

    //Getters..
    string getDni();
    string getNombre();
    int getEdad();
};