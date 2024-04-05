#pragma once
#include <iostream>
#include <vector>
#include "asistente.h"

using namespace std;

class Evento{
    protected:
    string ubicacion, id;
    int duracion, capacidad;
    vector<Asistente*> listadoAsistentes;
    public:
    Evento(string id,string ubicacion, int duracion, int capacidad);
    ~Evento();
    virtual string mostrarInformacion() = 0;
    virtual string mostrarInformacionCompleta() = 0;
    virtual string informacionParaArchivo() = 0;
    string getId();
    string getUbicacion();
    int getDuracion();
    int getCapacidad();



    bool agregarAsistente(Asistente *asistente);

};