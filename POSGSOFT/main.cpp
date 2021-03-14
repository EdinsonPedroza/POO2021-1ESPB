#include<iostream>
#include<list>
#include<string>
#include<vector>

using namespace std;
enum class EstadoActa{cerrada=0, abierta};
enum class tipoTrabajo{aplicado=0, investigacion};
enum tipoPersona{ESTUDIANTE=0,JURADO=1,DIRECTOR=2};

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
        int id, cantPersonas=0;
        vector <string> vectorNombrePersona;
        vector <int> vectorIdPersona;
    public:
        Persona();
        Persona(string, int);
        void mostrarPersona();
};
class Director: public Persona{
    private:
        vector <string> vectorNombreDirector;
        vector <int> vectorIdDirector;
    public:
        Director();
        Director(string, int);
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
Persona::Persona(string nombre, int id) {
    this->vectorNombrePersona.push_back(nombre);
    this->vectorIdPersona.push_back(id);
}
void Persona::mostrarPersona() {
    int i;
    for(i=0;i< vectorIdPersona.size();i++) {
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

int main(){
    int i;
    vector<Acta> acta;
    Acta acta1;
    acta.push_back(acta1);
    acta1.crearNuevaActa();
    system("pause");
    Persona persona1;
    persona1.mostrarPersona();

    return 0;
}

