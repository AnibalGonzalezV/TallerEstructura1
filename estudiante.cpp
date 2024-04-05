#include "estudiante.h"
using namespace std;


Estudiante::Estudiante(string nombre, string dni, int edad, string carrera, string institucion) : Asistente(nombre, dni, edad) {
    this->carrera = carrera;
    this->institucion = institucion;
}

Estudiante::~Estudiante(){}

string Estudiante::mostrarInformacion()
{
    return "Nombre: " + nombre + ", edad: " + to_string(edad) + " años. DNI: "+ dni + ", Estudiante de " + carrera + " en " + institucion; 
}