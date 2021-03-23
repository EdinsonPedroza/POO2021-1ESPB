#include "Criterio.h"

using namespace std;

void Criterio::recibirCriterios(vector<double> vectorCriterioJ1, vector<double> vectorCriterioJ2,
                                vector<string> vectorComentJ1, vector<string> vectorComentJ2){
    this->calificacionesJ1=vectorCriterioJ1;
    this->calificacionesJ2=vectorCriterioJ2;
    this->comentariosJ1=vectorComentJ1;
    this->comentariosJ2=vectorComentJ2;

}

void Criterio::mostrarCalificacionesCriterios() {
    for (int i = 0; i < this->calificacionesJ1.size(); i++){
        cout << "Nota " <<i+1 << " de Jurado 1: " << this->calificacionesJ1[i] << endl << "Nota " << i + 1 << " de Jurado 2: "
        << this->calificacionesJ2[i] << endl;
    }
}

void Criterio::generarEstadoActa(){
    double promedi;
    cout<<this->calificacionesJ1[0];
    for (int i = 0; i < this->calificacionesJ1.size(); i++) {
        this->sumaCriterios.push_back(((this->calificacionesJ1[i] + this->calificacionesJ2[i]) / 2) * (this->ponderado[i]));
    }
    this->promedio.push_back((this->sumaCriterios[0] + this->sumaCriterios[1] + this->sumaCriterios[2] + this->sumaCriterios[3] +
                              this->sumaCriterios[4] + this->sumaCriterios[5] + this->sumaCriterios[6] + this->sumaCriterios[7]));
    cout<<this->promedio[0];
    cout<<this->calificacionesJ1[0];
    this->promedioFinal=promedio[0];
    Acta acta;
    acta.recibirPromedio(promedioFinal);
}

void Criterio::crearPonderado() {
    this->ponderado.push_back(0.20);
    this->ponderado.push_back(0.15);
    this->ponderado.push_back(0.10);
    this->ponderado.push_back(0.10);
    this->ponderado.push_back(0.20);
    this->ponderado.push_back(0.10);
    this->ponderado.push_back(0.075);
    this->ponderado.push_back(0.075);
}


void Criterio::mostrarComentarios() {
    int i;
    for (i=0;i<this->comentariosJ1.size();i++){
        if(i==0) {
            cout << "Los comentarios del jurado 1 son:" << endl;
        }
        if(i>=0){
            cout<<this->comentariosJ1[i]<<endl;
        }
    }
    for (i=0;i<this->comentariosJ2.size();i++){
        if(i==0) {
            cout << "Los comentarios del jurado 2 son:" << endl;
        }
        if(i>=0){
            cout<<this->comentariosJ2[i]<<endl;
        }
    }
}

Criterio::Criterio() {

}



