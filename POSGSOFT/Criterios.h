#ifndef POSGSOFT_CRITERIOS_H
#define POSGSOFT_CRITERIOS_H
#include<string>
#include<vector>

using namespace std;

class Criterios{
private:
    vector<double>calificacionesJ1;
    vector<double>calificacionesJ2;
    vector<double>sumaCriterios;
    vector<double>ponderado;
    vector<double> promedio;
    vector<string>comentariosJ1;
    vector<string>comentariosJ2;

public:
    Criterios();
    void recibirCriterios(vector<double>, vector<double>, vector<string>, vector<string>);
    void mostrarCalificacionesCriterios();
    void crearPonderado();
    void generarEstadoActa();
    void mostrarComentarios();
};
#endif //POSGSOFT_CRITERIOS_H
