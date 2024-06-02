#include "Polimorfismo.h"

Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

void Polimorfismo::leerArchivo(string nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada; //se usa para manipular archivos, para leer y escribirlos
    string row[7]; // para almacenar los datos de la linea de archivo ya separados
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in); //abrir archivo
    
    while(getline(entrada,line)){
        stringstream s(line);
        iR= 0;

            //ciclo que extrae caracteres de s y los almacena en word hasta que encuentra una coma
            while(getline(s,word, ',')){
                row[iR++] = word;
            }

            // determinar si es pelicula, serie o episodio
            if(row[0] == "P"){
                arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
                //cout<<"Pelicula"<<arrPtrPeliculas[cantidadPeliculas]->str() <<endl;
                cantidadPeliculas++;
            }
            else if(row[0] == "S"){
                arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
                cantidadSeries++;
            }
            else if( row[0] == "E"){
                index = stoi(row[1]) - 500;
                arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            }
    }

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio();
        arrPtrSeries[index] -> setCalificacion(promedio);
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
        arrPtrSeries[index]->calculaDuracion();
    }

    
    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /*for(int index = 0; index<cantidad; index++){
        cout<<index<<" "<<arrPtrVideos[index]->str()<<endl;
    }*/

    entrada.close();
}


//metodos modificadores
    void Polimorfismo::setPtrVideo(int index, Video *video){
        //validar index
        if(index >= 0 && index < cantidad){
            //modificar apuntador
            arrPtrVideos[index] = video;
        }
}


//cambia el valor del atributo cantidad
    void Polimorfismo::setCantidad(int _cantidad){
        // cantidad debe estar entre 0 a MAX_VIDEOS -1
        if(_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
            cantidad = _cantidad;
        }
}


//metodos de acceso
    Video* Polimorfismo::getPtrVideo(int index){
        //validar que exista el index
        if(index >= 0 && index < cantidad){
            return arrPtrVideos[index];
        }
        //Si no existe
        return nullptr;
}

//regresa cantidad    
    int Polimorfismo::getCantidad(){
        return cantidad;
}


// otros metodos

    // sirve para obtener la cantidad de Peliculas y series
    void Polimorfismo::reporteInventario(){
        //declaracion
        int cantidadPelis, cantidadSeries;

        //inicializar 
        cantidadPelis = 0;
        cantidadSeries = 0;

        //recorrer todo el arreglo de ptr usando un for
        for(int index = 0; index < cantidad; index++){
            cout<<arrPtrVideos[index] -> str()<<endl;

            if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                cantidadPelis++;
            }
            else if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
                cantidadSeries++;
            }
        }
        cout<< "Peliculas = " << cantidadPelis << endl;
        cout<< "Series = " << cantidadSeries << endl;
    }


    // sirve para devolver las películas y series que tengan la calificacion que se ingresa
    void Polimorfismo::reporteCalificacion(double _calificacion){
        //contador total
        int total;
        total = 0;

        for(int index = 0; index < cantidad ; index++){
            //verificar si tiene la calificacion == _calificacion
            if(arrPtrVideos[index] -> getCalificacion() == _calificacion){
                cout<< arrPtrVideos[index] -> str() << endl;
                total++;
            }
        }
        //fuera del for
        cout << "Total = " << total <<endl;
    }

    // sirve para obtener las peliculas y series de un determinado género
    void Polimorfismo::reporteGenero(string _genero){
        int cantidadGenero = 0;

        for(int index = 0; index < cantidad; index++){
            if(arrPtrVideos[index]->getGenero() == _genero){
                cout<< arrPtrVideos[index] -> str() << endl;
                cantidadGenero++;
            }
        }
        cout << "Total = " << cantidadGenero << endl;

    }


    // sirve para obtener las peliculas y el total de peliculas en el arreglo arrPtrVideos
    void Polimorfismo::reportePeliculas(){
        int totalPelis = 0;
        
        for(int index = 0; index < cantidad; index++){
            if(typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                cout << arrPtrVideos[index] -> str() << endl;
                totalPelis++;
            }
        }
        
        if(totalPelis > 0){
            cout << "Total Peliculas = " << totalPelis << endl;}
        else{
            cout << "No Peliculas" << endl;
        }
    }


    // sirve para obtener las series con sus episodios y el total de peliculas en el arreglo arrPtrVideos
    void Polimorfismo::reporteSeries(){
        int totalSeries = 0;

        for(int index = 0; index < cantidad; index++){
            if(typeid(*arrPtrVideos[index]) == typeid(Serie)){
                cout << arrPtrVideos[index] -> str() << endl;
                totalSeries++;
            }
        }
        if(totalSeries > 0){
            cout << "Total Series = " << totalSeries << endl;}
        else{
            cout << "No series" << endl;}
    }

    