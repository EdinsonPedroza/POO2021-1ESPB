#include "Persona.h"
#include "Acta.h"
#include "Director.h"
using namespace std;

Director::Director() {
}

Director::Director(string nombre, string id): Persona(nombre, id) {
    this->nameDir.push_back(nombre);
    this->cantTrabajos+=1;
    this->vectorCantTrabajos.push_back(cantTrabajos);
}

void Director::mostrarCantTrabajos() {
    cout<<"La cantidad de trabajos dirigidos por este director es:"
    <<this->getName()<<" "<< this->cantTrabajos;
}
