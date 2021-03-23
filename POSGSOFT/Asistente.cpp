#include "Asistente.h"


Asistente::Asistente() {

}
void Asistente::crearNuevaActa() {
    Acta acta;
    acta.crearDatos();
}

void Asistente::recibirDatos(string nombreEstudiante, string nombreDir, vector<string> listaJurados,
                             int numeroActa, int idEstudiante, int idDirector, vector<string> listaID,
                             int estadotrabajo, vector<string> criterios, vector<double> calificacionesJ1
                             , vector<double> calificacionesJ2, vector<string> comentariosJ1,
                             vector<string> comentariosJ2, string comentariosAdicionalesJ1,
                             string comentariosAdicionalesJ2,double promedio, string fecha, string nombreTrabajo,
                             string tipoTrabajo){
    cout<<"LLEGUEEEEEEEEE\n";
    this->estudiante.push_back(nombreEstudiante);
    this->director.push_back(nombreDir);
    this->jurado.push_back(listaJurados[0]);
    this->jurado.push_back(listaJurados[1]);
    this->numeroActa.push_back(numeroActa);
    this->idEstudiante.push_back(idEstudiante);
    this->idDirector.push_back(idDirector);
    this->idJurado.push_back(listaID[0]);
    this->idJurado.push_back(listaID[1]);
    this->aprobacion.push_back(estadotrabajo);
    for (int i=0;i<criterios.size();i++){
        this->criterios.push_back(criterios[i]);
    }
    for (int i=0;i<calificacionesJ1.size();i++){
        this->notas.push_back(calificacionesJ1[i]);
        this->notas.push_back(calificacionesJ2[i]);
    }
    for (int i=0;i<comentariosJ1.size();i++){
        this->comentarios.push_back(comentariosJ1[i]);
        this->comentarios.push_back(comentariosJ1[i]);
    }
    cout<<"LLEGUEEEEEEEEE\n";
    this ->comentariosAdicionales.push_back(comentariosAdicionalesJ1);
    this->comentariosAdicionales.push_back(comentariosAdicionalesJ2);
    this->promedio.push_back(promedio);
    this->fecha.push_back(fecha);
    this->nombreTrabajo.push_back(nombreTrabajo);
    this->tipoTrabajo.push_back(tipoTrabajo);
    cout<<"LLEGUEEEEEEEEE\n";
}

void Asistente::mostrarActa() {
    int numero;
    cout<<"Ingrese el numero del acta: ";
    cin>>numero;
    cout<<numeroActa[0];
    for(int i=0;i<this->numeroActa.size();i++){
        if(numero==this->numeroActa[i]){
            cout<<"ACTA: "<< this->numeroActa[i] << "\n"<<
               "Fecha: "<<this->fecha[i]<<"\n"
               "Trabajo de grado denominado: "<<this->nombreTrabajo[i]<<"\n"
              "Autor: "<<this->estudiante[i]<<"\n"
              "ID: "<<this->idEstudiante[i]<<"\n"
              "Director: "<<this->director[i]<<"\n"
              "Co-Director: NA\n"
              "Énfasis en: Sistemas y Computación\n"
              "Modalidad: "<<this->tipoTrabajo[i]<<"\n"
              "Jurado 1: "<<this->jurado[i]<<"\n"
              "Jurado 2: "<<this->jurado[i+1]<<"\n";
        }
    }
}
