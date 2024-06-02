//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024
/*¿Qué aprendí en el desarrollo de esta clase? Aprendí el concepto de herencia y como declarar clases bases.
La sintaxis de los consrtuctores y overriding en la función str() */ 

#ifndef Pelicula_h
#define Pelicula_h
#include "Video.h"
#include <string>
using namespace std;

// clase película es derivada de video

class Pelicula : public Video{

    private:
        int oscares;


    public:
    // constructores
        Pelicula();
        Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int oscares);


    // metodos de modificacion 
        void setOscares(int _oscares);


    // métodos de acceso
        int getOscares();


    //otros
        string str();
    
};



#endif /*Pelicula_h*/