#ifndef POSGSOFT_PERSONA_H
#define POSGSOFT_PERSONA_H
#include<iostream>

using namespace std;
class Persona{
private:
    string nombre;
    string id;
public:
    Persona();
    Persona(string, string);
    string getName();
};
#endif //POSGSOFT_PERSONA_H
