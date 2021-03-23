#ifndef POSGSOFT_JURADO_H
#define POSGSOFT_JURADO_H
#include<iostream>
#include<vector>
#include "Persona.h"
#include "Acta.h"
#include "Criterio.h"

using namespace std;
class Jurado: public Persona{
private:
    vector <string> vectorNombreJurado;
    vector <string> vectorIdJurado;
    int nota;
    vector<double> vectorCriterioJ1, vectorCriterioJ2;
    vector<string> vectorComentJ1, vectorComentJ2;
    string comentJ1,comentJ2;
public:
    Jurado();
    Jurado(string, string);
    void calificarCriterios(vector<string>);
    void ingresarComentariosAdicionales();
};
#endif //POSGSOFT_JURADO_H
