#ifndef POSGSOFT_JURADO_H
#define POSGSOFT_JURADO_H
#include<iostream>

class Jurado: public Persona{
private:
    vector <string> vectorNombreJurado;
    vector <string> vectorIdJurado;
public:
    Jurado();
    Jurado(string, string);
    void calificarCriterios();
    void ingresarComentariosAdicionales();
};
#endif //POSGSOFT_JURADO_H
