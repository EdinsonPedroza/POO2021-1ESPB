#ifndef POSGSOFT_ACTA_H
#define POSGSOFT_ACTA_H
#include<iostream>
#include<vector>
#include "Criterio.h"
#include "Persona.h"
#include "Director.h"
#include "Jurado.h"
#include "Asistente.h"

using namespace std;
enum EstadoActa{CERRADA=0, ABIERTA=1};
enum tipoPersona{ESTUDIANTE=0,JURADO=1,DIRECTOR=2};
enum Estadotrabajo{REPROBADO=0,APROBADO=1};

class Acta{
private:
    string fecha;
    int numeroActa, idEstudiante, idDirector;
    string nombreEstudiante, nombreDir, code, workName;
    int cantTrabajos;
    vector<int> trabajoPorDirector;
    string descripcionTrabajo;
    vector<string>nombreTrabajo;
    string tipoTrabajo;
    vector<string>criterios;
    vector<string>listaID;
    vector<double>calificacionesJ1;
    vector<double>calificacionesJ2;
    vector<string>comentariosJ1;
    vector<string>comentariosJ2;
    vector<string>listaJurados;
    vector <string> tipoTrabajoAplicado;
    vector <string> tipoTrabajoInvestigacion;
    EstadoActa estado;
    Estadotrabajo estadotrabajo;
    string comentariosAdicionalesJ1;
    string comentariosAdicionalesJ2;
    vector <string> trabajosRechazados;
    vector <string> trabajosAprobados;
    double promedio;
public:
    Acta();
    void crearDatos();
    void crearFecha();

    void agregarPersonal();
    void agregarEstudiante();
    void agregarJurado();
    void agregarDirector();
    void asignarCriterios();

    void recibirComentariosAdicionales(string, string);
    void mostrarComentariosAdicionales();

    void mostrarTrabajosAplicados();
    void mostrarTrabajosdeInvestigacion();
    void mostrartrabajosDirigidos();

    void mostrarListaJurados();
    void mostrarListaAprobados();
    void mostrarListaRechazados();

    void recibirCalificaciones(vector<double>, vector<double>, vector<string>, vector<string>);
    void recibirPromedio(double);

    void enviarDatos();
};
#endif //POSGSOFT_ACTA_H
