#include<iostream>
#include<string>
#include "Persona.h"
using namespace std;

Persona::Persona() {
}
Persona::Persona(string nombre, int id) {
    this->vectorNombrePersona.push_back(nombre);
    this->vectorIdPersona.push_back(id);
}
void Persona::mostrarPersona() {
    int i;
    for(i=0;i< this->vectorIdPersona.size();i++) {
        cout << "El nombre es: " << this->nombre << endl;
        cout << "El codigo es: " << this->id << endl;
    }
}