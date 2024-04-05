#include "profesional.h"

using namespace std;


Profesional::Profesional(string nombre, string dni ,int edad, string ocupacion, string empresa) : Asistente(nombre, dni, edad) {
    this->ocupacion = ocupacion;
    this->empresa = empresa;
}

Profesional::~Profesional(){}

string Profesional::mostrarInformacion()
{
   return "Nombre: " + nombre + ", edad: " + to_string(edad) + " años. DNI: " + dni + ", Trabaja de " + ocupacion + " en " + empresa; 
}