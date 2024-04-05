#pragma once
#include "eventos.h"
#include <iostream>
using namespace std;

class Concierto : public Evento{
    private:
    string artista;
    public:
    Concierto(string, string, int, int, string );
    ~Concierto();
    string mostrarInformacion();
    string mostrarInformacionCompleta();
    string informacionParaArchivo();
};