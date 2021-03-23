#include<iostream>
#include "Asistente.h"

void crearMenu();

using namespace std;

/*void escribir(){
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
}*/
int main(){
    //escribir();
    //leer();
    crearMenu();

    system("pause");
    return 0;
}

void crearMenu() {
    int opc;
    Asistente asistente;
    do{
        cout<<"1. Crear acta\n"
              "2. Ver trabajos aplicados\n"
              "3. Ver trabajos de investgacion\n"
              "4. Consultar cuantos trabajos de grado ha dirigido un profesor. \n"
              "5. Consultar de cuales trabajos de grado ha sido jurado una persona\n"
              "6. Ver la lista de todos los jurados que han participado en las actas registradas\n"
              "7. Consultar las actas de los trabajos de grado aprobados y rechazados.  \n"
              "8. Consultar la lista de criterios de evaluacion\n"
              "0. Salir\n"
              "Que accion desea realizar?: ";
        cin>>opc;
        switch (opc) {
            case 1:
                asistente.crearNuevaActa();
                break;
            case 2:
                asistente.mostrarActa();
                break;
           // case 3: ;
           // case 4: ;
           // case 5: ;
           // case 6: ;
           // case 7: ;
           // case 8: ;
        }
    }while(opc!=0);
}
