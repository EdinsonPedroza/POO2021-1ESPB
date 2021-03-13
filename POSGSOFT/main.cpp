#include<iostream>
#include<list>
#include<string>

using namespace std;
enum class EstadoActa{cerrada, abierta};
enum class tipoTrabajo{aplicado, investigacion};
enum class tipoPersona{Estudiante,Jurado,Director};

class Acta{
private:
    int numeroActa;
    string fecha, nombreTrabajo;
    tipoTrabajo tipo_Trabajo;
    EstadoActa estado;
public:
    Acta();//fecha, el número del acta,
    //nombre del estudiante, nombre del trabajo, tipo de trabajo, director, codirector (si existe), jurado 1 y jurado 2
    void crearFechaActa();
    void crearNuevaActa();
    void agregarPersonal();

    void agregarEstudiante();

    void agregarJurado();

    void agregarDirector();
};
class Persona{
    private:
        string nombre;
        int id;
    public:
        Persona(string, int);
        void mostrarPersona();

};
class Director: public Persona{
    private:

    public:
        Director();
        Director(string, int);
};

class Jurado: public Persona{
    private:

    public:
        Jurado();
        Jurado(string, int);
        void calificarActa();
};
class Estudiante: public Persona{
    private:
    public:
        Estudiante();
        Estudiante(string,int);
        void crearProyecto();
        void mostrarEstudiante();
};
Persona::Persona(string nombre, int id) {
    this->nombre=nombre;
    this->id=id;
}
void Persona::mostrarPersona() {
    cout<<"El nombre es: "<<nombre<<endl;
    cout<<"El codigo es: "<<id<<endl;
}
Estudiante::Estudiante(string nombre, int id): Persona(nombre,id) {
}
void Estudiante::mostrarEstudiante() {
    mostrarPersona();
}
Acta::Acta(){}

void Acta::crearNuevaActa(){
    int dia,mes,year, cEst;
    cout<<"Ingrese el numero del acta: ";
    cin>>this->numeroActa;
    agregarPersonal();
    cout<<"Ingrese el dia: ";
    cin>>dia;
    cout<<"Ingrese el mes: ";
    cin>>mes;
    printf("Ingrese el A%co: ",164);
    cin>>year;
    agregarPersonal();
    cout<<"Ingrese su ID: ";
    cin>>cEst;
    string name;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);

    Estudiante estudiante1(name,cEst);
    estudiante1.mostrarEstudiante();

    this->estado = EstadoActa::abierta;
    cout<<"Acta #"<<this->numeroActa<< " creada ";

}

void Acta::agregarPersonal(){
    int n;
    cout<<"(1.Estudiante\n2.Jurado\n3.Director): "<<endl;
    cout<<"Ingrese el tipo de persona a agregar: ";
    cin>>n;
    tipoPersona tipo = tipoPersona::Estudiante;
    switch (tipo) {
        case tipoPersona::Estudiante:
            agregarEstudiante();break;
        case tipoPersona::Jurado:
            agregarJurado();break;
        case tipoPersona::Director:
            agregarDirector();break;
    }

}

void Acta::agregarEstudiante() {
    string name, *vectorEst;
    int code,i, cantEstudiantes, *vectorCod;
    cout<<"Digite la cantidad de estudiantes: ";
    cin>>cantEstudiantes;
    vectorEst=new string[cantEstudiantes];
    vectorCod=new int[code];
    for(i=0;i<cantEstudiantes;i++){
        cin.ignore();
        cout<<"Ingrese su nombre: ";
        getline(cin,name);
        vectorEst[i]=name;
        cout<<"Ingrese su ID: ";
        cin>>code;
        vectorCod[i]=code;
    }
    for(i=0;i<cantEstudiantes;i++){
        cout<<"Estudiante: "<<vectorEst[i]<<" Codigo: "<<vectorCod[i]<<endl;
    }
}

void Acta::agregarJurado() {

}

void Acta::agregarDirector() {

}

void agregarEstudiante();

int main(){

    Acta acta1;
    acta1.crearNuevaActa();
    return 0;
}

