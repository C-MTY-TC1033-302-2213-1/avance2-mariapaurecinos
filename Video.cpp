//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024

#include "Video.h"

Video::Video(){
    iD = "0000";
    titulo = "Paula Recinos";
    duracion = 1000;
    genero = "Femenino";
    calificacion = 100.0;
}
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// metodos de modificacion
void Video::setId(string _iD){
    iD = _iD;
}
void Video::setNombre(string _titulo){
    titulo = _titulo;
}
void Video::setGenero(string _genero){
    genero = _genero;
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

// metodos acceso
string Video::getId(){
    return iD;
}
string Video::getNombre(){
    return titulo;
}
string Video::getGenero(){
    return genero;
}
int Video::getDuracion(){
    return duracion;
}
double Video::getCalificacion(){
    return calificacion;
}

// otros métodos
// retorna los datos del objeto en
string Video::str(){
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion);
}