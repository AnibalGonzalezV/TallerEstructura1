#include "eventos.h"

Evento::Evento(string id, string ubicacion, int duracion, int capacidad) {
    this->id = id;
    this->ubicacion = ubicacion;
    this->duracion = duracion;
    this->capacidad = capacidad;
    listadoAsistentes = vector<Asistente*>();
}

Evento::~Evento(){}

string Evento::getId(){return id;}
string Evento::getUbicacion(){return ubicacion;}
int Evento::getDuracion(){return duracion;}
int Evento::getCapacidad(){return capacidad;}

bool Evento::agregarAsistente(Asistente *asistente) {
    if(listadoAsistentes.size() < capacidad) { listadoAsistentes.push_back(asistente); return true; }
    return false;
}
