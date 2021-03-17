#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include "Persona.h"
#include "Acta.h"
#include "Director.h"
#include "Jurado.h"
#include "Estudiante.h"
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