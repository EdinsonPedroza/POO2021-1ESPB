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

Director::Director(string nombre, int id): Persona(nombre, id) {
    this->vectorNombreDirector.push_back(nombre);
    this->vectorIdDirector.push_back(id);
}
