#pragma once
#include <iostream>
#include "asistente.h"

using namespace std;

class Profesional : public Asistente{
    private:
    string ocupacion;
    string empresa;
    public:
    Profesional(string, string, int, string, string);
    ~Profesional();
    string mostrarInformacion();
    string informacionParaArchivo();

};