#ifndef POSGSOFT_DIRECTOR_H
#define POSGSOFT_DIRECTOR_H
#include<iostream>
#include<vector>

class Director: public Persona{
private:
    int cantTrabajos=0;
    vector<int>vectorCantTrabajos;
    vector<string>nameDir;
public:
    Director();
    Director(string, string);
    void mostrarCantTrabajos();
};
#endif //POSGSOFT_DIRECTOR_H
