#ifndef POSGSOFT_ESTUDIANTE_H
#define POSGSOFT_ESTUDIANTE_H
#include<iostream>
#include<vector>
class Estudiante: public Persona{
private:
public:
    Estudiante();
    Estudiante(string, string);
    void getEstudiante();
};
#endif //POSGSOFT_ESTUDIANTE_H