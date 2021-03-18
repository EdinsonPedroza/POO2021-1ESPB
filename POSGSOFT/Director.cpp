#include<string>
#include "Persona.h"
#include "Director.h"
using namespace std;

Director::Director(string nombre, int id): Persona(nombre, id) {
    this->vectorNombreDirector.push_back(nombre);
    this->vectorIdDirector.push_back(id);
}
