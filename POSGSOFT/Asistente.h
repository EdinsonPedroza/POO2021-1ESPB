#ifndef POSGSOFT_ASISTENTE_H
#define POSGSOFT_ASISTENTE_H
#include "Persona.h"
#include <vector>
#include <string>
#include "Acta.h"

using namespace std;

class Asistente: public Persona{
    private:
        vector<int>numeroActa;
        vector<string>estudiante;
        vector<string>nombreTrabajo;
        vector<string>jurado;
        vector<string>director;
        vector<int>idEstudiante;
        vector<string>idJurado;
        vector<int>idDirector;
        vector<string>criterios;
        vector<double>notas;
        vector<string>comentarios;
        vector<string>comentariosAdicionales;
        vector<double>promedio;
        vector<int>aprobacion;
        vector<string> fecha;
        vector<string>tipoTrabajo;
    public:
        Asistente();
        void crearNuevaActa();
        void mostrarActa();
        void recibirDatos(string, string, vector<string>, int, int, int, vector<string>,
                          int, vector<string>, vector<double>, vector<double>, vector<string>,
                          vector<string>, string, string,
                           double, string, string, string);
};
#endif //POSGSOFT_ASISTENTE_H