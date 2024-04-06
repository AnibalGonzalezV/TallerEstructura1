#pragma once
#include <iostream>
#include "asistente.h"

using namespace std;

class Estudiante : public Asistente{
    private:
    string carrera;
    string institucion;
    public:
    Estudiante(string nombre, string dni, int edad, string carrera, string institucion);
    ~Estudiante();
    string mostrarInformacion();
    string informacionParaArchivo();
};