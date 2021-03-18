#include<string>
#include "Persona.h"
#include "Estudiante.h"

using namespace std;

Estudiante::Estudiante(string nombre, int id, string tipoTrabajo, string nombreTrabajo,
                       string descripcion): Persona(nombre,id) {
    this->vectorNombreEstudiante.push_back(nombre);
    this->vectorIdEstudiante.push_back(id);
    this->tipoTrabajo.push_back(tipoTrabajo);
    this->nombreTrabajo.push_back(nombreTrabajo);
    this->descripcionTrabajo.push_back(descripcion);
}

void Estudiante::mostrarEstudiante() {
    mostrarPersona();
}