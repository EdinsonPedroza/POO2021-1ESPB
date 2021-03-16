#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;

enum class EstadoActa{cerrada=0, abierta=1};
enum class tipoTrabajo{aplicado=0, investigacion=1};
enum tipoPersona{ESTUDIANTE=0,JURADO=1,DIRECTOR=2};
enum Estadotrabajo:char{REPROBADO=0,APROBADO=1};

class Acta{
private:
    int numeroActa;
    string fecha, nombreTrabajo;
    tipoTrabajo tipoTrabajo;
    EstadoActa estado;
    Estadotrabajo estadotrabajo;
    vector<double>criterio1;
    vector<double>criterio2;
    vector<double>criterioFinal;
    vector<double> promedio;
    vector<double>ponderado;
    vector<string>comentariosJ1;
    vector<string>comentariosJ2;
    string comentariosAdicionalesJ1;
    string comentariosAdicionalesJ2;
public:
    Acta();
    void crearFechaActa();
    void crearNuevaActa();
    void agregarPersonal();
    void agregarEstudiante();
    void agregarJurado();
    void agregarDirector();
    void recibirCriterios(vector<double>, vector<double>, vector<string>, vector<string>);
    void mostrarCalificacionesCriterios();
    void crearPonderado();
    void generarEstadoActa();
    void definirEstadoTrabajo();
    void mostrarComentarios();
    void recibirComentariosAdicionales(string, string);
    void mostrarComentariosAdicionales();
};
class Persona{
    private:
        string nombre;
        int id, cantPersonas=0;
        vector <string> vectorNombrePersona;
        vector <int> vectorIdPersona;
    public:
        Persona();
        Persona(string, int);
        void mostrarPersona();
};
class Estudiante: public Persona{
private:
    vector <string> vectorNombreEstudiante;
    vector <int> vectorIdEstudiante;
public:
    Estudiante();
    Estudiante(string,int);
    void setEstudiante(string,int);
    void crearProyecto();
    void mostrarEstudiante();
};
class Jurado: public Persona{
    private:
        vector <string> vectorNombreJurado;
        vector <int> vectorIdJurado;
    public:
        Jurado();
        Jurado(string, int);
        void setJurado();
        void calificarCriterios();
        void ingresarComentariosAdicionales();
};
class Director: public Persona{
private:
    vector <string> vectorNombreDirector;
    vector <int> vectorIdDirector;
public:
    Director();
    Director(string, int);
};

Persona::Persona(string nombre, int id) {
    this->vectorNombrePersona.push_back(nombre);
    this->vectorIdPersona.push_back(id);
}
void Persona::mostrarPersona() {
    int i;
    for(i=0;i< this->vectorIdPersona.size();i++) {
        cout << "El nombre es: " << this->nombre << endl;
        cout << "El codigo es: " << this->id << endl;
    }
}

Persona::Persona() {
}

Jurado::Jurado(string nombre, int id): Persona(nombre,id) {
    this->vectorNombreJurado.push_back(nombre);
    this->vectorIdJurado.push_back(id);
}

Director::Director(string nombre, int id): Persona(nombre, id) {
    this->vectorNombreDirector.push_back(nombre);
    this->vectorIdDirector.push_back(id);
}

Estudiante::Estudiante(string nombre, int id): Persona(nombre,id) {
    this->vectorNombreEstudiante.push_back(nombre);
    this->vectorIdEstudiante.push_back(id);
}

void Estudiante::mostrarEstudiante() {
     mostrarPersona();
}
Acta::Acta(){}

void Acta::crearNuevaActa(){
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
    this->estado = EstadoActa::abierta;
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
    string name;
    int code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    cin>>code;
    Estudiante estudiante(name,code);
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

    Acta mandarCriterios;
    mandarCriterios.recibirCriterios(vectorCriterioJ1, vectorCriterioJ2, vectorComentJ1, vectorComentJ2);
    mandarCriterios.mostrarCalificacionesCriterios();
    mandarCriterios.crearPonderado();
    mandarCriterios.generarEstadoActa();
    mandarCriterios.mostrarComentarios();
    Jurado jurado;
    jurado.ingresarComentariosAdicionales();

}

Jurado::Jurado() {

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
void leer(){
    ifstream archivoLectura;
    string texto;
    archivoLectura.open("ewfewf", ios::in);

    if(archivoLectura.fail()){
        cout<<"No se pudo abrir el archivo  :("<<endl;
        exit(1);
    }

    while(!archivoLectura.eof()){  //mientras no se acabe el archivo
        getline(archivoLectura, texto); //leer archivo
        cout<<texto<<endl;

    }

    archivoLectura.close();
}*/
int main(){
    //escribir();
    //leer();

    Acta acta;
    acta.crearNuevaActa();
    cout<<"ya";
    system("pause");
    return 0;
}


