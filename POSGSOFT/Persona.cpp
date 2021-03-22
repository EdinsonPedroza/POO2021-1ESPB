#include "Persona.h"
using namespace std;

Persona::Persona() {
}

Persona::Persona(string, string) {

}

string Persona::getName() {
    cout<<this->nombre;
    return this->nombre;
}
