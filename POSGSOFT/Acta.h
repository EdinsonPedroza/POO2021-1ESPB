#ifndef POSGSOFT_ACTA_H
#define POSGSOFT_ACTA_H
#include<iostream>
#include<vector>

using namespace std;
enum class EstadoActa{CERRADA=0, ABIERTA=1};
enum tipoPersona{ESTUDIANTE=0,JURADO=1,DIRECTOR=2};
enum Estadotrabajo{REPROBADO=0,APROBADO=1};
class Acta{
private:
    string fecha;
    string name, code, workName;
    int cantTrabajos;
    vector<int> trabajoPorDirector;
    int numeroActa;
    string descripcionTrabajo;
    vector<string>nombreTrabajo;
    string tipoTrabajo;
    vector<string>listaJurados;
    vector<string>listaDirectores;
    vector<string> listaID;
    vector <string> tipoTrabajoAplicado;
    vector <string> tipoTrabajoInvestigacion;
    vector<double> promedio;
    EstadoActa estado;
    Estadotrabajo estadotrabajo;
    string comentariosAdicionalesJ1;
    string comentariosAdicionalesJ2;
    vector <string> trabajosRechazados;
    vector <string> trabajosAprobados;
public:
    Acta();
    void crearDatos();
    void crearFecha();

    void agregarPersonal();
    void agregarEstudiante();
    void agregarJurado();
    void agregarDirector();

    void recibirComentariosAdicionales(string, string);
    void mostrarComentariosAdicionales();
    void definirEstadoTrabajo();

    void mostrarTrabajosAplicados();
    void mostrarTrabajosdeInvestigacion();
    void mostrartrabajosDirigidos();

    void mostrarListaJurados();
    void mostrarListaAprobados();
    void mostrarListaRechazados();
};
#endif //POSGSOFT_ACTA_H
