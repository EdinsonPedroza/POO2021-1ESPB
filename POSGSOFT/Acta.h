#ifndef POSGSOFT_ACTA_H
#define POSGSOFT_ACTA_H
#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
enum class EstadoActa{CERRADA=0, ABIERTA=1};
enum tipoPersona{ESTUDIANTE=0,JURADO=1,DIRECTOR=2};
enum Estadotrabajo{REPROBADO=0,APROBADO=1};
class Acta{
private:
    int numeroActa;
    vector<int>posicionActa;
    string fecha;
    vector <string> descripcionTrabajo;
    vector<string> nombreTrabajo;
    string tipoTrabajo;
    vector <string> tipoTrabajoAplicado;
    vector <string> tipoTrabajoInvestigacion;
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
    void mostrarTrabajosAplicados();
    void mostrarTrabajosdeInvestigacion();
};
#endif //POSGSOFT_ACTA_H
