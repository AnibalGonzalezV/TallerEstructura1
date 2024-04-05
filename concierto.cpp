#include "eventos.h"
#include "concierto.h"

Concierto::Concierto(string id, string ubicacion, int duracion, int capacidad, string artista) 
: Evento(id,ubicacion,duracion,capacidad) {
    this->artista = artista;
}

Concierto::~Concierto(){}

string Concierto::mostrarInformacion()  {
    return "Concierto | Artista invitado: " + artista;
}

string Concierto::mostrarInformacionCompleta() {
    return "Tipo: Concierto, Ubicacion: " + ubicacion + ", duracion: " + to_string(duracion) + ", capacidad: " + to_string(capacidad) + ", Artista invitado: " + artista;
}

string Concierto::informacionParaArchivo() {
    return id + "/Concierto/" + ubicacion + "/" + to_string(duracion) + "/" + to_string(capacidad) + "/" + artista;
}