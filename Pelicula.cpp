//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024


#include "Pelicula.h"

Pelicula::Pelicula():Video(){
    oscares = 111;
}
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares)
:Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscares = _oscares;
}

// metodos de modificacion
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

// métodos de acceso
int Pelicula::getOscares(){
    return oscares;
}

// otros
string Pelicula::str(){
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(oscares);
}
