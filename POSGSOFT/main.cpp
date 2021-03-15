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

class Acta{
private:
    int numeroActa;
    string fecha, nombreTrabajo;
    tipoTrabajo tipo_Trabajo;
    EstadoActa estado;
    vector<double>criterio1;
    vector<double>criterio2;
    vector<double>criterioFinal;
    vector<double> promedio;
    vector<double>ponderado;
public:
    Acta();//fecha, el número del acta,
    //nombre del estudiante, nombre del trabajo, tipo de trabajo, director, codirector (si existe), jurado 1 y jurado 2
    void crearFechaActa();
    void crearNuevaActa();
    void agregarPersonal();
    void agregarEstudiante();
    void agregarJurado();
    void agregarDirector();
    void recibirCriterios(vector<double>, vector<double>);
    void mostrarCalificacionesCriterios();
    void crearPonderado();
    void generarEstadoActa();
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
        void calificarActa();
        void calificarCriterios();
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
    jurado.calificarActa();
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
            case tipoPersona::ESTUDIANTE:
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

void Acta::recibirCriterios(vector<double> vectorCriterioJ1, vector<double> vectorCriterioJ2) {
    this->criterio1 = move(vectorCriterioJ1);
    this->criterio2= move(vectorCriterioJ2);
}

void Acta::mostrarCalificacionesCriterios() {
    for (int i = 0; i < this->criterio1.size(); i++){
        cout <<"Nota "<<i+1<<" de Jurado 1: "<<this->criterio1[i] << endl <<"Nota "<<i+1<<" de Jurado 2: "<< this->criterio2[i]<< endl;
    }
}

void Acta::generarEstadoActa() {
    cout<<"hola ";
    for (int i = 0; i < this->criterio1.size(); i++) {
        cout<<"hola ";
        this->criterioFinal.push_back((this->criterio1[i]+this->criterio2[i])/2 * (this->ponderado[i]));
        cout<<"hola ";
    }
    cout<<"hola ";
    this->promedio.push_back((this->criterioFinal[0]+this->criterioFinal[1]+this->criterioFinal[2]+this->criterioFinal[3]+
                               this->criterioFinal[4]+this->criterioFinal[5]+this->criterioFinal[6]+this->criterioFinal[0])/
                               this->criterioFinal.size());
    cout<<promedio[0];
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
    cout<< this->ponderado[7];
}

void Jurado::calificarCriterios() {
    int i, nota, n=0;
    vector<double> vectorCriterioJ1, vectorCriterioJ2;
    for (i=0;i<16;i++){
        cin.ignore();
        if(n<8){
            cout<<"Jurado 1:";
            cout<<"Ingrese la nota del criterio "<<i+1<<": ";
            cin>>nota;
            vectorCriterioJ1.push_back(nota);
        }else{
            cout<<"Jurado 2:";
            cout<<"Ingrese la nota del criterio "<<i-7<<": ";
            cin>>nota;
            vectorCriterioJ2.push_back(nota);
        }
        n++;
    }
    Acta mandarCriterios;
    mandarCriterios.recibirCriterios(vectorCriterioJ1, vectorCriterioJ2);
    mandarCriterios.mostrarCalificacionesCriterios();
}
void Jurado::calificarActa() {
    calificarCriterios();
}
Jurado::Jurado() {

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
    vector<int> a;
    vector<int> b;
    vector<int> c;
    b.push_back(3);
    c.push_back(3);
    a.push_back((b[0]*c[0])/2);
    cout<<a[0];
    Acta acta;
    acta.crearNuevaActa();
    acta.crearPonderado();
    acta.generarEstadoActa();

    cout<<"ya";
    system("pause");
    return 0;
}


