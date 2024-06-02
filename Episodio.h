//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024
/*¿Qué aprendí en el desarrollo de esta clase? repase la declaración de una clase en POO*/ 


#ifndef Episodio_h
#define Episodio_h
#include <string>
using namespace std;

class Episodio
{
    private:
        string titulo;
        int temporada;
        int calificacion;
    public:
        //constructores
        Episodio();
        Episodio(string _titulo, int _temporada, int _calificacion);

        // metodos de modificacion
        void setTitulo(string _titulo);
        void setTemporada(int _temporada);
        void setCalificacion(int _calificacion);

        // metodos de acceso
        string getTitulo();
        int getTemporada();
        int getCalificacion();

        // otros metodos
        string str();


};



#endif /*Episodio_h*/