//Nombre: Maria Paula Recinos Ríos
//Matrícula: A00840131
//Carrera: IDM
//Fecha:20-05-2024


#include "Serie.h"

// constructor
Serie::Serie():Video(){
    //solo vamos a inicializar cantidad ya que el arreglo se inicializa con el constructor default de la clase
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo,int _duracion,  string _genero, double _calificacion)
: Video(_iD, _titulo, _duracion, _genero, _calificacion){

}


// métodos de modificación
// sirve para agregar un episodio al arreglo de episodios que pertenecen a un objeto serie 
void Serie::setEpisodio(int posicion, Episodio episodio){
    // primero validar que exista ese episodio
    if (posicion < cantidad && posicion>=0){
        episodios[posicion] = episodio;
    };
} 

// sirve para establecer la cantidad de episodios en el arreglo de objetos de clase episodio
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}



// métodos de acceso
Episodio Serie::getEpisodio(int posicion){
    // crea un objeto y lo inicializa con el default
    Episodio epi;
    // validar que exista el episodio solicitado
    if (posicion < cantidad && posicion>=0){
        return episodios[posicion];
        }
    // si no existe se retorna un default
    return epi;
}

int Serie::getCantidad(){
    return cantidad;
}


// otros métodos

// calcula el promedio de la calificacion de la serie por cada episodio
double Serie::calculaPromedio(){
    double acum = 0;
    for(int index =0; index<cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }
    
    //validar que tenga episodios
    if(cantidad>0){
        return acum/cantidad;
    }
    else{
        return 0;
    }
}

//overriding del métodos str() de la clase base
string Serie::str(){
    string resultado;
    resultado = iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + ' ' + to_string(cantidad) + '\n';
   
   
   if (cantidad>0){
    for(int index = 0; index<cantidad; index++){
    resultado += episodios[index].str() + '\n';
    }
   }
   return resultado;
}

//agrega episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad<5){
        episodios[cantidad++] = episodio; //si le pongo ++ despues primero usa el valor y luego lo incrementa
    }
}

// calcula el atributo duración de video sumando las temporadas de cada episodio
void Serie::calculaDuracion(){
    int cantidadTemporadas = 0;
    for(int index = 0; index<cantidad; index++){
        cantidadTemporadas += episodios[index].getTemporada();
    }
    duracion = cantidadTemporadas;
}