#ifndef POSGSOFT_ASISTENTE_H
#define POSGSOFT_ASISTENTE_H
#include "Persona.h"

class Asistente: public Persona{
    private:
        vector<string>estudiante;
        vector<int>id;
        vector<string>jurado;
        vector<string>director;


public:
    Asistente();
    void crearNuevaActa();
};

#endif //POSGSOFT_ASISTENTE_H
