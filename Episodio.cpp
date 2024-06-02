//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024

#include "Episodio.h"
#include "Video.h"

// constructores
Episodio::Episodio(){
    titulo = "-";
    temporada = 0;
    calificacion = 0;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// metodos de modificacion
void Episodio::setTitulo(string _tituloEpi){
    titulo = _tituloEpi;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

// metodos de acceso
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

// otros metodos
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}