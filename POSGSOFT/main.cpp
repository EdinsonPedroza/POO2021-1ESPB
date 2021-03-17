#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include "Persona.h"
#include "Acta.h"
#include "Director.h"
#include "Jurado.h"
#include "Estudiante.h"
using namespace std;
/*
void escribir(){
    ofstream archivo;
    string nombreArchivo, mensaje;

    cout<<"Ingrese el nombre del archivo: "<<endl;
    getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo  :("<<endl;
        exit(1);
    }

    cout<<"Ingrese el mensaje del archivo: "<<endl;
    getline(cin, mensaje);
    archivo<<mensaje<< endl;



    archivo.close();
}
void leer() {
    ifstream archivoLectura;
    string texto;
    archivoLectura.open("ewfewf", ios::in);

    if (archivoLectura.fail()) {
        cout << "No se pudo abrir el archivo  :(" << endl;
        exit(1);
    }

    while (!archivoLectura.eof()) {  //mientras no se acabe el archivo
        getline(archivoLectura, texto); //leer archivo
        cout << texto << endl;

    }

    archivoLectura.close();
}
*/
int main(){
    //escribir();
    //leer();
    Acta acta;
    acta.crearNuevaActa();
    cout<<"ya";
    system("pause");
    return 0;
}