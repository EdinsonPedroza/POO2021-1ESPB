#ifndef POSGSOFT_ASISTENTE_H
#define POSGSOFT_ASISTENTE_H
#include "Persona.h"
#include "Acta.h"

class Asistente: public Persona{
    private:
        vector<Acta>actas;
        vector<string>estudiante;
        vector<string>jurado;
        vector<string>director;
    public:
        Asistente();
        void crearNuevaActa();
        void mostrarActa();
};
#endif //POSGSOFT_ASISTENTE_H