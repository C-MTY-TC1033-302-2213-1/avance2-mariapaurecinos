#ifndef Polimorfismo_h
#define Polimorfismo_h
#include "Video.h"
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*¿Qué aprendí en el desarrollo de esta clase? En esta clase utilicé arreglos de apuntadores y aprendí que sirven para 
poder utilizar una clase base pero hacer que cada objeto ejecute la función a la que se le hizo overriding
para que utilice la de la clase de dicho objeto */ 

const int MAX_VIDEOS = 100;

class Polimorfismo{
    private:
        Video *arrPtrVideos[MAX_VIDEOS];
        int cantidad;

    public:
    //constructor
    Polimorfismo();

    //leer archivo
    void leerArchivo(string _nombre);

    //metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //metodos de acceso
    Video *getPtrVideo(int index);
    int getCantidad();

    // otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};





#endif /*Polimorfismo_h*/