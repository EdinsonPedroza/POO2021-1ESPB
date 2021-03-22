#include<iostream>
#include<string>
#include<vector>
#include "Persona.h"
#include "Acta.h"
#include "Jurado.h"
#include "Criterios.h"

using namespace std;

Jurado::Jurado() {
}
Jurado::Jurado(string nombre, string id): Persona(nombre,id) {
    this->vectorNombreJurado.push_back(nombre);
    this->vectorIdJurado.push_back(id);
}
void Jurado::calificarCriterios() {
    int i, nota;
    vector<double> vectorCriterioJ1, vectorCriterioJ2;
    vector<string> vectorComentJ1, vectorComentJ2;
    string comentJ1,comentJ2;

    for (i=0;i<16;i++){
        if(i<8){
            cout<<"Jurado 1:";
            cout<<"Ingrese la nota del criterio #"<<i+1<<": ";
            cin>>nota;
            vectorCriterioJ1.push_back(nota);
            cin.ignore();
            cout<<"Ingrese su comentario del criterio #"<<i+1<<":\n";
            getline(cin, comentJ1);
            vectorComentJ1.push_back(comentJ1);

        }else{
            cout<<"Jurado 2:";
            cout<<"Ingrese la nota del criterio #"<<i-7<<": ";
            cin>>nota;
            vectorCriterioJ2.push_back(nota);
            cin.ignore();
            cout<<"Ingrese su comentario del criterio # "<<i-7<<":\n";
            getline(cin,comentJ2);
            vectorComentJ2.push_back(comentJ2);
        }
    }

    Criterios mandarCriterios;
    mandarCriterios.recibirCriterios(vectorCriterioJ1, vectorCriterioJ2, vectorComentJ1, vectorComentJ2);
    mandarCriterios.mostrarCalificacionesCriterios();
    mandarCriterios.crearPonderado();
    mandarCriterios.generarEstadoActa();
    mandarCriterios.mostrarComentarios();
    Jurado jurado;
    jurado.ingresarComentariosAdicionales();
    Acta acta;
    acta.definirEstadoTrabajo();

}

void Jurado::ingresarComentariosAdicionales() {
    int i=0, respuesta;
    string comentarioJ1,comentarioJ2;
    switch (i) {
        case 0:
            cout << "Jurado 1" << endl;
            cout << "Desea realizar comentarios adicionales?" << endl;
            cout << "0. No\n 1. Si" << endl;
            cin >> respuesta;
            if (respuesta == 1) {
                cin.ignore();
                cout << "Ingrese su comentario adicional:\n";
                getline(cin, comentarioJ1);

            } else {
                cout<<"N/A"<<endl;
            }
        case 1:
            cout << "Jurado 2" << endl;
            cout << "Desea realizar comentarios adicionales?" << endl;
            cout << "0. No\n 1. Si" << endl;
            cin >> respuesta;
            if (respuesta == 1) {
                cin.ignore();
                cout << "Ingrese su comentario adicional:\n";
                getline(cin, comentarioJ2);
            }else{
                cout<<"N/A"<<endl;
            }
    }
    Acta acta;
    acta.recibirComentariosAdicionales(comentarioJ1,comentarioJ2);
    acta.mostrarComentariosAdicionales();
}


