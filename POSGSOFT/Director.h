#ifndef POSGSOFT_DIRECTOR_H
#define POSGSOFT_DIRECTOR_H
#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include <utility>
#include<vector>
#include<fstream>
#include<stdlib.h>

class Director: public Persona{
private:
    vector <string> vectorNombreDirector;
    vector <int> vectorIdDirector;
public:
    Director();
    Director(string, int);
};
#endif //POSGSOFT_DIRECTOR_H
