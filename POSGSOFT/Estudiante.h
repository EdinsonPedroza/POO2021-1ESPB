#ifndef POSGSOFT_ESTUDIANTE_H
#define POSGSOFT_ESTUDIANTE_H
#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>

class Estudiante: public Persona{
private:
    vector <string> vectorNombreEstudiante;
    vector <int> vectorIdEstudiante;
    vector<string> nombreTrabajo;
    vector <string> tipoTrabajo;
    vector <string> descripcionTrabajo;
public:
    Estudiante();
    Estudiante(string, int, string, string, string);
    void setEstudiante(string,int);
    void crearProyecto();
    void mostrarEstudiante();
};
#endif //POSGSOFT_ESTUDIANTE_H