#ifndef POSGSOFT_PERSONA_H
#define POSGSOFT_PERSONA_H
#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
class Persona{
private:
    string nombre;
    int id, cantPersonas=0;
    vector <string> vectorNombrePersona;
    vector <int> vectorIdPersona;
public:
    Persona();
    Persona(string, int);
    void mostrarPersona();
};
#endif //POSGSOFT_PERSONA_H
