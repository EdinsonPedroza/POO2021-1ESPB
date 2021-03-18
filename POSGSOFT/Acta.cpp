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

Acta::Acta(){}

void Acta::crearNuevaActa(){
    this->estado = EstadoActa::ABIERTA;
    int dia,mes,year, cEst;
    cout<<"Ingrese el numero del acta: ";
    cin>>this->numeroActa;
    cout<<"Ingrese el dia: ";
    cin>>dia;
    cout<<"Ingrese el mes: ";
    cin>>mes;
    printf("Ingrese el A%co: ",164);
    cin>>year;
    agregarPersonal();
    Jurado jurado;
    jurado.calificarCriterios();
    cout<<"Acta #"<<this->numeroActa<< " creada ";

}

void Acta::agregarPersonal(){
    int n, addEst=0, addJur=0, addDir=0;
    do {
        cout<<"0.Estudiante\n1.Jurado\n2.Director\n3.Salir: "<<endl;
        cout<<"Ingrese el tipo de persona a agregar: ";
        cin>>n;
        switch (n) {
            case tipoPersona::ESTUDIANTE :
                if(addEst<1){
                    agregarEstudiante();
                    addEst+=1;
                    cout<<"----estudiante registrado----"<<endl;
                }else{
                    cout<<"----El estudiante ya fue registrado----"<<endl;
                }break;

            case tipoPersona::JURADO:
                if(addJur<2){
                    agregarJurado();
                    addJur+=1;
                    cout<<"----jurado registrado----"<<endl;
                }else{
                    cout<<"----Los jurados ya fueron registrados----"<<endl;
                }break;
            case tipoPersona::DIRECTOR:
                if(addDir<1){
                    agregarDirector();
                    addDir+=1;
                    cout<<"----director registrado----"<<endl;
                }else{
                    cout<<"----El director ya fue registrado----"<<endl;
                }break;
        }
    }while(addDir<1 || addJur<2 || addEst<1);
}

void Acta::agregarEstudiante() {
    string name, descripcion, workName;
    int code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    cin>>code;
    cin.ignore();
    cout<<"Ingrese su tipo de trabajo:"<<endl;
    cout<<"1.Aplicado\n2.Investigacion:"<<endl;
    getline(cin,this->tipoTrabajo);
    cout<<"Ingrese el nombre de su trabajo:"<<endl;
    getline(cin,workName);
    cout<<"Ingrese la descripcion de su trabajo:"<<endl;
    getline(cin,descripcion);

    if(this->tipoTrabajo=="Aplicado" || this->tipoTrabajo=="aplicado" || this->tipoTrabajo=="APLICADO" ||
            this->tipoTrabajo=="1"){
        this->tipoTrabajoAplicado.push_back(workName);
    }
    else if(this->tipoTrabajo=="Investigacion" || this->tipoTrabajo=="investigacion" || this->tipoTrabajo=="INVESTIGACION" ||
            this->tipoTrabajo=="2"){
        this->tipoTrabajoInvestigacion.push_back(workName);
    }
    mostrarTrabajosAplicados();
    mostrarTrabajosdeInvestigacion();

    Estudiante estudiante(name,code,this->tipoTrabajo, workName, descripcion);
    Persona persona(name,code);


}

void Acta::agregarJurado() {
    string name;
    int code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    cin>>code;
    Jurado jurado(name,code);
    Persona persona(name,code);

}

void Acta::agregarDirector() {
    string name;
    int code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    cin>>code;
    Director director(name,code);
    Persona persona(name,code);
}

void Acta::recibirCriterios(vector<double> vectorCriterioJ1, vector<double> vectorCriterioJ2, vector<string> vectorComentJ1,
                            vector<string> vectorComentJ2){
    this->criterio1=std::move(vectorCriterioJ1);
    this->criterio2=std::move(vectorCriterioJ2);
    this->comentariosJ1=std::move(vectorComentJ1);
    this->comentariosJ2=std::move(vectorComentJ2);

}

void Acta::mostrarCalificacionesCriterios() {
    for (int i = 0; i < this->criterio1.size(); i++){
        cout <<"Nota "<<i+1<<" de Jurado 1: "<<this->criterio1[i] << endl <<"Nota "<<i+1<<" de Jurado 2: "<< this->criterio2[i]<< endl;
    }
}

void Acta::generarEstadoActa(){
    for (int i = 0; i < this->criterio1.size(); i++) {
        this->criterioFinal.push_back(((this->criterio1[i]+this->criterio2[i])/2) * (this->ponderado[i]));
    }
    this->promedio.push_back((this->criterioFinal[0]+this->criterioFinal[1]+this->criterioFinal[2]+this->criterioFinal[3]+
                              this->criterioFinal[4]+this->criterioFinal[5]+this->criterioFinal[6]+this->criterioFinal[7]));
    cout<<this->promedio[0];
}

void Acta::crearPonderado() {
    int i=0;
    switch (i) {
        case 0:
            this->ponderado.push_back(0.20);
        case 1:
            this->ponderado.push_back(0.15);
        case 2:
            this->ponderado.push_back(0.10);
        case 3:
            this->ponderado.push_back(0.10);
        case 4:
            this->ponderado.push_back(0.20);
        case 5:
            this->ponderado.push_back(0.10);
        case 6:
            this->ponderado.push_back(0.075);
        case 7:
            this->ponderado.push_back(0.075);
    }
}

void Acta::definirEstadoTrabajo() {
    if (this->promedio[0]>3.5){
        this->estadotrabajo= APROBADO;
    }else{
        this->estadotrabajo= REPROBADO;
    }
    this->estado = EstadoActa::CERRADA;
}

void Acta::mostrarComentariosAdicionales() {
    cout<<this->comentariosAdicionalesJ1<<endl;
    cout<<this->comentariosAdicionalesJ2<<endl;
}

void Acta::recibirComentariosAdicionales(string comentariosAdicionalesJ1, string comentariosAdicionalesJ2) {
    this->comentariosAdicionalesJ1=std::move(comentariosAdicionalesJ1);
    this->comentariosAdicionalesJ2=std::move(comentariosAdicionalesJ2);
}

void Acta::mostrarComentarios() {
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

void Acta::mostrarTrabajosAplicados() {
    int i;
    for(i=0;i<this->tipoTrabajoAplicado.size();i++){
        cout<<this->tipoTrabajoAplicado[i]<<endl;
    }
}

void Acta::mostrarTrabajosdeInvestigacion() {
    int i;
    for(i=0;i<this->tipoTrabajoInvestigacion.size();i++){
        cout<<this->tipoTrabajoInvestigacion[i]<<endl;
    }
}

