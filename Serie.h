//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024
/*¿Qué aprendí en el desarrollo de esta clase? Aprendí el concepto de herencia y como declarar clases bases.
La sintaxis de los consrtuctores y overriding en la función str() */ 

#ifndef Serie_h
#define Serie_h
#include "Video.h"
#include "Episodio.h"
#include <string>

using namespace std;

class Serie : public Video{

    private:
        Episodio episodios[5];
        int cantidad;

    public:
        // constructres
        Serie();
        Serie(string _iD, string _titulo,int _duracion,  string _genero, double _calificacion);
    

        // métodos de modificación
        void setEpisodio(int posicion, Episodio episodio); //no llevan guión bajo porque no son atributos de la clase
        void setCantidad(int _cantidad);


        // métodos de acceso
        Episodio getEpisodio(int posicion);
        int getCantidad();



        // otros métodos
        double calculaPromedio();

        string str();

        void agregaEpisodio(Episodio episodio);
        
        void calculaDuracion(); 
};




#endif /*Serie_h*/