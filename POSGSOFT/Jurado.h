#ifndef POSGSOFT_JURADO_H
#define POSGSOFT_JURADO_H
#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>
class Jurado: public Persona{
private:
    vector <string> vectorNombreJurado;
    vector <int> vectorIdJurado;
public:
    Jurado();
    Jurado(string, int);
    void getJurado(const string&);
    void calificarCriterios();
    void ingresarComentariosAdicionales();
};
#endif //POSGSOFT_JURADO_H
