#include "asistente.h"
#include <iostream>

using namespace std;

Asistente::Asistente(string nombre, string dni, int edad) {
    this->nombre = nombre;
    this->dni = dni;
    this->edad = edad;
}

Asistente::~Asistente(){}

string Asistente::getDni(){return dni;}

string Asistente::getNombre(){return nombre;}

int Asistente::getEdad(){return edad;}



