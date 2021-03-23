#ifndef POSGSOFT_CRITERIO_H
#define POSGSOFT_CRITERIO_H
#include<string>
#include<vector>
#include "Acta.h"
#include "Jurado.h"

using namespace std;

class Criterio{
private:
    vector<double>calificacionesJ1;
    vector<double>calificacionesJ2;
    vector<double>sumaCriterios;
    vector<double>ponderado;
    vector<double> promedio;
    vector<string>comentariosJ1;
    vector<string>comentariosJ2;
    double promedioFinal;

public:
    Criterio();
    void recibirCriterios(vector<double>, vector<double>, vector<string>, vector<string>);
    void mostrarCalificacionesCriterios();
    void crearPonderado();
    void generarEstadoActa();
    void mostrarComentarios();
};
#endif //POSGSOFT_CRITERIO_H
