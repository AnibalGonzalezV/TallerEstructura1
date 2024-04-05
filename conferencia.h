#pragma once
#include <iostream>
#include "eventos.h"

using namespace std;

class Conferencia : public Evento{
    private:
    string orador, tema;
    public:
    Conferencia(string,string,int,int,string,string);
    string mostrarInformacion();
    string mostrarInformacionCompleta();
    string informacionParaArchivo();
};