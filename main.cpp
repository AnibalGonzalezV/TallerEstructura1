#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "eventos.h"
#include "asistente.h"
#include "conferencia.h"
#include "concierto.h"
#include "profesional.h"
#include "estudiante.h"

using namespace std;

/*
    FUNCION PARA SEPARAR LA LINEA DEL ARCHIVO, Y ENTREGAR LAS PARTES.....
*/
vector<string> split(const string& linea, char separador) {
    vector<string> partes;
    stringstream ss(linea);
    string parte;
    while (getline(ss, parte, separador)) {
        partes.push_back(parte);
    }
    return partes;
}



/*
    FUNCION PARA GUARDAR EVENTOS DESDE ARCHIVO HACIA VECTOR EVENTOS.
*/
void cargarEventos(const string& archivo, vector<Evento*>& eventos) {
    ifstream file(archivo);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            vector<string> partes = split(linea, '/');
            string ID = partes[0];
            string tipo = partes[1];
            string ubicacion = partes[2];
            int duracion = stoi(partes[3]);
            int capacidad = stoi(partes[4]);
            Evento* evento;
            if (tipo == "Conferencia") {
                evento = new Conferencia(ID, ubicacion, duracion, capacidad, partes[5], partes[6]);
            } else if (tipo == "Concierto") {
                evento = new Concierto(ID, ubicacion, duracion, capacidad, partes[5]);
            } else {
                // Tipo de evento no reconocido
                continue;
            }
            eventos.push_back(evento);
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
    }
}
/*
    FUNCION PARA AGREGAR MANUALMENTE EVENTOS HACIA VECTOR EVENTOS.
*/

void agregarEventoManualmente(vector<Evento*>& eventos) {
    string ID, tipo, ubicacion, duracionStr, capacidadStr, detalleAdicional;
    int duracion, capacidad;
    
    cout << "Ingrese el ID del evento: " << endl;
    cin >> ID;
    cout << "Ingrese el tipo de evento (Conferencia o Concierto): " << endl;
    cin >> tipo;
    cout << "Ingrese la ubicacion del evento: " << endl;
    cin >> ubicacion;
    cout << "Ingrese la duracion del evento (en minutos): " << endl;
    cin >> duracionStr;
    cout << "Ingrese la capacidad del evento: " << endl;
    cin >> capacidadStr;
    duracion = stoi(duracionStr);
    capacidad = stoi(capacidadStr);
    Evento* nuevoEvento;

    if (tipo == "Conferencia") {
        string orador, tema;
        cout << "Ingrese el nombre del orador: " << endl;
        cin >> orador;
        cout << "Ingrese el tema de la conferencia: " << endl;
        cin >> tema;
        nuevoEvento = (new Conferencia(ID, ubicacion, duracion, capacidad, orador, tema));
        cout << "Evento Conferencia creado correctamente!." << endl;
    } else if (tipo == "Concierto") {
        string artista;
        cout << "Ingrese el nombre del artista invitado: " << endl;
        cin >> artista;
        nuevoEvento = (new Concierto(ID, ubicacion, duracion, capacidad, artista));
        cout << "Evento Concierto creado correctamente!." << endl;
    } else {
        cout << "Tipo de evento no reconocido. No se pudo agregar el evento." << endl;
        return;
    }
    eventos.push_back(nuevoEvento);

    ofstream file("eventos.txt", ios::app);                                 
    if(file.is_open()){
        file << nuevoEvento->informacionParaArchivo() << "\n";               //SECCION DE GUARDADO EN ARCHIVO, QUEDA VER EL SALTOD DE LINEA
        file.close();
        cout << "Informacion Guardada" << endl;
    } else{
        cout << "No se puede abrir el archivo." << endl;
    }

}   
/*
    FUNCION PARA AGREGAR UN ASISTENTE AL SISTEMA
*/
void agregarAsistenteManualmente(vector<Asistente*>& asistentes) {
    string profesion, nombre, dni, edadStr;
    int edad;
    
    cout << "Ingrese la Ocupacion del Asistente (Profesional o Estudiante): ";
    cin >> profesion;
    cin.ignore(); // Limpiar el búfer de nueva línea antes de getline()

    cout << "Ingrese el Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese el DNI (Sin puntos ni guion): ";
    cin >> dni;
    cin.ignore(); // Limpiar el búfer de nueva línea después de cin

    cout << "Ingrese la Edad: ";
    cin >> edadStr;
    edad = stoi(edadStr);
    cin.ignore(); // Limpiar el búfer de nueva línea después de cin

    if (profesion == "Profesional") {
        string ocupacion, empresa;
        cout << "Ingrese la Profesion: ";
        getline(cin, ocupacion);

        cout << "Ingrese la Empresa: ";
        getline(cin, empresa);

        asistentes.push_back(new Profesional(nombre, dni, edad, ocupacion, empresa));
        cout << "Asistente Profesional agregado correctamente!" << endl;
    } else if (profesion == "Estudiante") {
        string carrera, institucion;
        cout << "Ingrese la Carrera de estudio: ";
        getline(cin, carrera);

        cout << "Ingrese la Institucion: ";
        getline(cin, institucion);

        asistentes.push_back(new Estudiante(nombre, dni, edad, carrera, institucion));
        cout << "Asistente Estudiante agregado correctamente!" << endl;
    } else {
        cout << "Tipo de Profesion no reconocido." << endl;
    }
}
/*
    FUNCION PARA GUARDAR ASISTENTES DESDE ARCHIVO HACIA VECTOR ASISTENTES
*/
void cargarAsistentes(const string& archivo, vector<Asistente*>& asistentes) {
    ifstream file(archivo);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            vector<string> partes = split(linea, '/');
            string tipo = partes[0];
            string nombre = partes[1];
            string dni = partes[2];
            int edad = stoi(partes[3]);
            Asistente* asistente;
            if (tipo == "Profesional") {
                asistente = new Profesional(nombre, dni, edad, partes[4], partes[5]);
            } else if (tipo == "Estudiante") {
                asistente = new Estudiante(nombre, dni, edad, partes[4], partes[5]);
            } else {
                // Tipo de asistente no reconocido
                continue;
            }
            asistentes.push_back(asistente);
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: " << archivo << endl;
    }
}



/*
    FUNCION PARA MOSTRAR EL LISTADO DE LOS EVENTOS
*/
void mostrarEventos(const vector<Evento*>& eventos) {
    cout << "Listado de Eventos Programados:" << endl;
    for (const auto& evento : eventos) {
        cout << evento->mostrarInformacionCompleta() << endl;
    }
}
/*
    FUNCION PARA MOSTRAR LOS ASISTENTES EN EL SISTEMA.  
*/
void mostrarAsistentesEnSistema(const vector<Asistente*>& Asistentes){
    cout << "Listado de Asistentes en el Sistema: " << endl;
    for (const auto& asistente : Asistentes){
        cout << asistente->mostrarInformacion() << endl;
    }
}

/*
    FUNCION PARA MOSTRAR LA LISTA DE ASISTENTES POR EVENTOS
*/
void mostrarAsistentesEnEvento(const vector<Evento*>& eventos, const vector<Asistente*>& asistentes, const string& archivoListaAsistencia) {
    ifstream file(archivoListaAsistencia);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            vector<string> partes = split(linea, '/');
            string eventoID = partes[0];
            for (const auto& evento : eventos) {
                if (evento->getId() == eventoID) {
                    cout << "Asistentes registrados para el evento " << eventoID << ", de tipo " << evento->mostrarInformacion() << endl;
                    for (int i = 1; i < partes.size(); ++i) {
                        string asistenteID = partes[i];
                        bool encontrado = false;
                        for (const auto& asistente : asistentes) {
                            if (asistente->getDni() == asistenteID) {
                                cout << "    *Nombre: " << asistente->getNombre() << ", DNI: " << asistenteID << endl;
                                encontrado = true;
                                break;
                            }
                        }
                        if (!encontrado) {
                            cout << "    *Nombre: Asistente con ID " << asistenteID << " no encontrado." << endl;
                        }
                    }
                    break;
                }
            }
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: " << archivoListaAsistencia << endl;
    }
}

int main() {
    vector<Evento*> eventos;
    vector<Asistente*> asistentes;

    cargarEventos("eventos.txt", eventos);
    cargarAsistentes("asistentes.txt", asistentes);
    cout << "****Bienvenido al Sistema de Eventos****" << endl;
    int opcion;
    do {
        cout << "Ingrese la opcion deseada: " << endl;  
        cout << "1) Listado de Eventos programados."<< endl; //Listo
        cout << "2) Listado de Asistentes registrados en un evento." << endl; //Listo
        cout << "3) Listado de Asistentes en el sistema." << endl; //Listo
        cout << "4) Ingresar un nuevo Evento manualmente." << endl; //Listo
        cout << "5) Ingresar un nuevo Asistente manualmente." << endl; //Listo
        cout << "6) Ingresar un Asistente a un Evento." << endl;  //FALTA Y SOBREESCRIBIR TXT´S
        cout << "7) Generar Informes." << endl;
        cout << "8) Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEventos(eventos);
                break;
            case 2:
                mostrarAsistentesEnEvento(eventos, asistentes, "listaAsistencia.txt");
                break;
            case 3:
                mostrarAsistentesEnSistema(asistentes);
                break;
            case 4:
                agregarEventoManualmente(eventos);
                break;
            case 5:
                cout << "Logica para Crear un nuevo Asistente" << endl;
                agregarAsistenteManualmente(asistentes);
                break;
            case 6:
                cout << "Registrar un asistente a un evento." << endl;
                break;
            case 7:
                cout << "Logica para Generar informes deseados." << endl;
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opción valida." << endl;
                break;
        }
    } while (opcion != 8);

/*
    AL FINALIZAR, SE LIMPIA LA MEMORIA.
*/
    for (auto& evento : eventos) {
        delete evento;
    }
    for (auto& asistente : asistentes) {
        delete asistente;
    }

    return 0;
}
