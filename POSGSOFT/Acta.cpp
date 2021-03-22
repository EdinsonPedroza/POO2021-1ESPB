#include<iostream>
#include "Persona.h"
#include "Acta.h"
#include "Director.h"
#include "Jurado.h"

using namespace std;

Acta::Acta(){}

void Acta::crearDatos(){
    this->estado = EstadoActa::ABIERTA;
    cout<<"Ingrese el numero del acta: ";
    cin>>this->numeroActa;
    crearFecha();
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
    int code;
    string estudiante,descripcion;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,estudiante);
    cout<<"Ingrese su ID: ";
    cin>>code;
    cin.ignore();
    cout<<"Ingrese su tipo de trabajo:"<<endl;
    cout<<"1.Aplicado\n2.Investigacion:"<<endl;
    getline(cin,this->tipoTrabajo);
    cout<<"Ingrese el nombre de su trabajo:"<<endl;
    getline(cin,this->workName);
    this->nombreTrabajo.push_back(this->workName);
    cout<<"Ingrese la descripcion de su trabajo:"<<endl;
    getline(cin,descripcion);


    if(this->tipoTrabajo=="Aplicado" || this->tipoTrabajo=="aplicado" || this->tipoTrabajo=="APLICADO" ||
            this->tipoTrabajo=="1"){
        this->tipoTrabajoAplicado.push_back(this->workName);
    }
    else if(this->tipoTrabajo=="Investigacion" || this->tipoTrabajo=="investigacion" || this->tipoTrabajo=="INVESTIGACION" ||
            this->tipoTrabajo=="2"){
        this->tipoTrabajoInvestigacion.push_back(this->workName);
    }
    mostrarTrabajosAplicados();
    mostrarTrabajosdeInvestigacion();

}

void Acta::agregarJurado() {
    string name;
    string code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    this->listaJurados.push_back(name);
    getline(cin,code);
    Jurado jurado(name,code);

}

void Acta::agregarDirector() {
    string name,code;
    int i;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    getline(cin,code);
    this->trabajoPorDirector.push_back(1);
    this->listaID.push_back(code);
    Director director(name,code);
    mostrartrabajosDirigidos();
}


void Acta::mostrarComentariosAdicionales() {
    cout<<this->comentariosAdicionalesJ1<<endl;
    cout<<this->comentariosAdicionalesJ2<<endl;
}

void Acta::recibirComentariosAdicionales(string comentariosAdicionalesJ1, string comentariosAdicionalesJ2) {
    this->comentariosAdicionalesJ1=std::move(comentariosAdicionalesJ1);
    this->comentariosAdicionalesJ2=std::move(comentariosAdicionalesJ2);
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

void Acta::crearFecha() {
    string fechaActa;
    cin.ignore();
    cout<<"Ingrese el la fecha: DD/MM/AA: ";
    getline(cin, fechaActa);
    this->fecha=fechaActa;
    cout<<this->fecha;
}

void Acta::definirEstadoTrabajo() {
    if (this->promedio[0]>3.5){
        this->estadotrabajo= APROBADO;
        this->trabajosAprobados.push_back(this->workName);
    }else{
        this->estadotrabajo= REPROBADO;
        this->trabajosAprobados.push_back(this->workName);
    }
    this->estado = EstadoActa::CERRADA;
}

void Acta::mostrartrabajosDirigidos() {
    int i,  cont;
    string idDir;
    cout<<"Ingrese el ID del director: ";
    getline(cin,idDir);
    for (i=0;i<this->listaID.size();i++){
        if (this->listaID[i]==idDir){
            cont=trabajoPorDirector[i];
            this->trabajoPorDirector[i]+=1;
        }
    }
    cout<<"La cantidad de trabajos es de: "<<cont-1<<endl;
}

void Acta::mostrarListaJurados() {
    int i;
    for (i=0;i<this->listaJurados.size();i++){
        cout<<this->listaJurados[i]<<endl;
    }
}

void Acta::mostrarListaAprobados() {
    int i;
    cout<<"Los trabajos aprobados son:"<<endl;
    for(i=0;i<this->trabajosAprobados.size();i++){
        cout<<this->trabajosAprobados[i]<<endl;
    }
}

void Acta::mostrarListaRechazados() {
    int i;
    cout<<"Los trabajos rechazados son:"<<endl;
    for(i=0;i<this->trabajosRechazados.size();i++){
        cout<<this->trabajosRechazados[i]<<endl;
    }
}
