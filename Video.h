//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024
/*¿Qué aprendí en el desarrollo de esta clase? Logré recordar los conceptos bases de la POO mediante la creación de una clase,
para el reto me sirvió comprender el concepto de una clase base ya que todas las clases derivadas poseerán
los mismos atributos y métodos que pertenezcan a esta*/ 


#ifndef Video_h
#define Video_h
#include <string>
using namespace std;

class Video{
    
    protected:
        string iD, titulo, genero;
        int duracion;
        double calificacion;
    public:
        //constructores
        Video();
        Video(string _iD, string _titulo,int _duracion,  string _genero, double _calificacion);

        // metodos de modificacion
        void setId(string _iD);
        void setNombre(string _titulo);
        void setGenero(string _genero);
        void setDuracion(int _duracion);
        void setCalificacion(double _calificacion);

        // metodos acceso
        string getId();
        string getNombre();
        string getGenero();
        int getDuracion();
        double getCalificacion();

        // otros métodos
        virtual string str();
};


#endif /*Video_h*/