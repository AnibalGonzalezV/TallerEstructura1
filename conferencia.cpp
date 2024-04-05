#include "conferencia.h"

Conferencia::Conferencia(string id, string ubicacion, int duracion, int capacidad, string orador, string tema) 
: Evento(id,ubicacion,duracion,capacidad){
    this->orador = orador;
    this->tema = tema;
}

string Conferencia::mostrarInformacion(){
    return "Conferencia | Orador: "+ orador + ", Tema: " +tema;
}
string Conferencia::mostrarInformacionCompleta() {
    return "Tipo: Conferencia, Ubicacion: " + ubicacion + ", duracion: " + to_string(duracion) + ", capacidad: " + to_string(capacidad) + ", Orador: " + orador + ", Tema a Hablar: " + tema;
}

string Conferencia::informacionParaArchivo() {
    return id + "/Conferencia/" + ubicacion + "/" + to_string(duracion) + "/" + to_string(capacidad) + "/" + orador + "/" + tema;
}