#include<iostream>
#include<list>

using namespace std;
//Hacer un enum del estado del acta {abierto, cerrado}
class Jurado{
    private:
        string nombre;
    public:
        Jurado();
        Jurado(string);
};
class Autor{
    private:
        string nombre;
        int id;
    public:
        Autor();
};

class AsistenteMaestria{
    private:
        string nombre;
        int id;
    public:
        AsistenteMaestria();
        void   crearNuevaActa();

};
int main(){


}