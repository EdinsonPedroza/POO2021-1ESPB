#include "Jurado.h"

Jurado::Jurado() {
}
Jurado::Jurado(string nombre, string id): Persona(nombre,id) {
    this->vectorNombreJurado.push_back(nombre);
    this->vectorIdJurado.push_back(id);
}
void Jurado::calificarCriterios(vector<string> criterios) {
    int i;
    for (i=0;i<16;i++){
        if(i<8){
            cout<<criterios[i];
            cout<<"Jurado 1:";
            cout<<"Ingrese la nota del criterio #"<<i+1<<": ";
            cin>>this->nota;
            this->vectorCriterioJ1.push_back(this->nota);
            cin.ignore();
            cout<<"Ingrese su comentario del criterio #"<<i+1<<":\n";
            getline(cin, this->comentJ1);
            this->vectorComentJ1.push_back(this->comentJ1);

        }else{
            cout<<criterios[i-8];
            cout<<"Jurado 2:";
            cout<<"Ingrese la nota del criterio #"<<i-7<<": ";
            cin>>this->nota;
            this->vectorCriterioJ2.push_back(this->nota);
            cin.ignore();
            cout<<"Ingrese su comentario del criterio # "<<i-7<<":\n";
            getline(cin,this->comentJ2);
            this->vectorComentJ2.push_back(this->comentJ2);
        }
    }
    Criterio mandarCriterios;
    mandarCriterios.recibirCriterios(this->vectorCriterioJ1, this->vectorCriterioJ2,
                                     this->vectorComentJ1, this->vectorComentJ2);
    mandarCriterios.mostrarCalificacionesCriterios();
    mandarCriterios.crearPonderado();
    mandarCriterios.generarEstadoActa();
    mandarCriterios.mostrarComentarios();
    ingresarComentariosAdicionales();

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
                comentarioJ1="N/A";
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
                comentarioJ2="N/A";
            }
    }
    Acta acta;
    acta.recibirCalificaciones(this->vectorCriterioJ1, this->vectorCriterioJ2,
                               this->vectorComentJ1, this->vectorComentJ2);
    acta.recibirComentariosAdicionales(comentarioJ1,comentarioJ2);
    acta.mostrarComentariosAdicionales();
}