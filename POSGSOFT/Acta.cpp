#include "Acta.h"

Acta::Acta(){}

void Acta::crearDatos(){
    this->estado = EstadoActa::ABIERTA;
    cout<<"Ingrese el numero del acta: ";
    cin>>this->numeroActa;
    crearFecha();
    agregarPersonal();
    asignarCriterios();
    Jurado jurado;
    jurado.calificarCriterios(this->criterios);
    if (this->promedio>3.5){
        this->estadotrabajo= APROBADO;
        this->trabajosAprobados.push_back(this->workName);
    }else{
        this->estadotrabajo= REPROBADO;
        this->trabajosAprobados.push_back(this->workName);
    }
    this->estado = EstadoActa::CERRADA;
    cout<<this->promedio<<endl;
    cout<<this->estadotrabajo<<endl;
    cout<<this->trabajosAprobados[0]<<endl;
    enviarDatos();
}

void Acta::agregarPersonal(){
    int n, addEst=0, addJur=0, addDir=0;
    do {
        cout<<"0.Estudiante\n1.Jurado\n2.Director\n3.Salir: "<<endl;
        cout<<"Ingrese el tipo de persona a agregar: ";
        cin>>n;
        switch (n) {
            case tipoPersona::ESTUDIANTE :
                if(addEst<1){
                    agregarEstudiante();
                    addEst+=1;
                    cout<<"----estudiante registrado----"<<endl;
                }else{
                    cout<<"----El estudiante ya fue registrado----"<<endl;
                }break;

            case tipoPersona::JURADO:
                if(addJur<2){
                    agregarJurado();
                    addJur+=1;
                    cout<<"----jurado registrado----"<<endl;
                }else{
                    cout<<"----Los jurados ya fueron registrados----"<<endl;
                }break;
            case tipoPersona::DIRECTOR:
                if(addDir<1){
                    agregarDirector();
                    addDir+=1;
                    cout<<"----director registrado----"<<endl;
                }else{
                    cout<<"----El director ya fue registrado----"<<endl;
                }break;
        }
    }while(addDir<1 || addJur<2 || addEst<1);
}

void Acta::agregarEstudiante() {
    int code;
    string descripcion;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,this->nombreEstudiante);
    cout<<"Ingrese su ID: ";
    cin>>code;
    cin.ignore();
    cout<<"Ingrese su tipo de trabajo:"<<endl;
    cout<<"0.Aplicado\n1.Investigacion:"<<endl;
    getline(cin,this->tipoTrabajo);
    cout<<"Ingrese el nombre de su trabajo:"<<endl;
    getline(cin,this->workName);
    this->nombreTrabajo.push_back(this->workName);
    cout<<"Ingrese la descripcion de su trabajo:"<<endl;
    getline(cin,descripcion);


    if(this->tipoTrabajo=="Aplicado" || this->tipoTrabajo=="aplicado" || this->tipoTrabajo=="APLICADO" ||
            this->tipoTrabajo=="0"){
        this->tipoTrabajoAplicado.push_back(this->workName);
    }
    else if(this->tipoTrabajo=="Investigacion" || this->tipoTrabajo=="investigacion" || this->tipoTrabajo=="INVESTIGACION" ||
            this->tipoTrabajo=="1"){
        this->tipoTrabajoInvestigacion.push_back(this->workName);
    }
    mostrarTrabajosAplicados();
    mostrarTrabajosdeInvestigacion();
}

void Acta::agregarJurado() {
    string name;
    string code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    this->listaJurados.push_back(name);
    getline(cin,code);
    Jurado jurado(name,code);

}

void Acta::agregarDirector() {
    string name,code;
    cin.ignore();
    cout<<"Ingrese su nombre: ";
    getline(cin,name);
    cout<<"Ingrese su ID: ";
    getline(cin,code);
    this->trabajoPorDirector.push_back(1);
    this->listaID.push_back(code);
    Director director(name,code);
    mostrartrabajosDirigidos();
}


void Acta::mostrarComentariosAdicionales() {
    cout<<this->comentariosAdicionalesJ1<<endl;
    cout<<this->comentariosAdicionalesJ2<<endl;
}

void Acta::recibirComentariosAdicionales(string comentariosAdicionalesJ1, string comentariosAdicionalesJ2) {
    this->comentariosAdicionalesJ1=std::move(comentariosAdicionalesJ1);
    this->comentariosAdicionalesJ2=std::move(comentariosAdicionalesJ2);
}


void Acta::mostrarTrabajosAplicados() {
    int i;
    for(i=0;i<this->tipoTrabajoAplicado.size();i++){
        cout<<this->tipoTrabajoAplicado[i]<<endl;
    }
}

void Acta::mostrarTrabajosdeInvestigacion() {
    int i;
    for(i=0;i<this->tipoTrabajoInvestigacion.size();i++){
        cout<<this->tipoTrabajoInvestigacion[i]<<endl;
    }
}

void Acta::crearFecha() {
    string fechaActa;
    cin.ignore();
    cout<<"Ingrese el la fecha: DD/MM/AA: ";
    getline(cin, fechaActa);
    this->fecha=fechaActa;
    cout<<this->fecha;
}



void Acta::mostrartrabajosDirigidos() {
    int i,  cont;
    string idDir;

    cout<<"Ingrese el ID del director: ";
    getline(cin,idDir);
    for (i=0;i<this->listaID.size();i++){
        if (this->listaID[i]==idDir){
            cont=trabajoPorDirector[i];
            this->trabajoPorDirector[i]+=1;
        }
    }
    cout<<"La cantidad de trabajos es de: "<<cont-1<<endl;
}

void Acta::mostrarListaJurados() {
    int i;
    for (i=0;i<this->listaJurados.size();i++){
        cout<<this->listaJurados[i]<<endl;
    }
}

void Acta::mostrarListaAprobados() {
    int i;
    cout<<"Los trabajos aprobados son:"<<endl;
    for(i=0;i<this->trabajosAprobados.size();i++){
        cout<<this->trabajosAprobados[i]<<endl;
    }
}

void Acta::mostrarListaRechazados() {
    int i;
    cout<<"Los trabajos rechazados son:"<<endl;
    for(i=0;i<this->trabajosRechazados.size();i++){
        cout<<this->trabajosRechazados[i]<<endl;
    }
}

void Acta::recibirPromedio(double promedio) {
    this->promedio=promedio;
}


void Acta::asignarCriterios() {
    this->criterios.emplace_back("1. Desarrollo y profundidad en el tratamiento del tema:\n");
    this->criterios.emplace_back("2. Desafio academico y cientifico del tema:\n");
    this->criterios.emplace_back("3. Cumplimiento de los objetivos propuestos:\n");
    this->criterios.emplace_back("4. Creatividad e innovacion de las soluciones y desarrollos propuestos:\n");
    this->criterios.emplace_back("5. Validez de los resultados y conclusiones:\n");
    this->criterios.emplace_back("6. Manejo y procesamiento de la informacion y bibliografia:\n");
    this->criterios.emplace_back("7. Calidad y presentacion del documento escrito:\n");
    this->criterios.emplace_back("8. Presentación oral:\n");
}

void Acta::enviarDatos() {
    if (this->tipoTrabajo=="1"){
        this->tipoTrabajo="INVESTIGACION";
    }else{
        this->tipoTrabajo="APLICADO";
    }
    cout<<calificacionesJ1[0]<<endl;
    cout<<"LLEGUEEEEEEEEE\n";
    cout<<this->nombreEstudiante<< this->nombreDir<< this->listaJurados[0]<< this->numeroActa
    <<this->idEstudiante<< this->idDirector<< this->listaID[0]<<
            this->estadotrabajo<< this->criterios[0]<< this->calificacionesJ1[0]<< this->calificacionesJ2[0]<<
            this->comentariosJ1[0]<<this->comentariosJ2[0]<< this->comentariosAdicionalesJ1<<
            this->comentariosAdicionalesJ2<< this->promedio<< this->fecha<< this->workName<< this->tipoTrabajo;
    Asistente asistente;
    cout<<"LLEGUEEEEEEEEE\n";
    asistente.recibirDatos(this->nombreEstudiante, this->nombreDir, this->listaJurados, this->numeroActa,
            this->idEstudiante, this->idDirector, this->listaID,
            this->estadotrabajo, this->criterios, this->calificacionesJ1, this->calificacionesJ2,
            this->comentariosJ1,this->comentariosJ2, this->comentariosAdicionalesJ1,
            this->comentariosAdicionalesJ2, this->promedio, this->fecha, this->workName, this->tipoTrabajo);
}

void Acta::recibirCalificaciones(vector<double>calificacionesJ1, vector<double>calificacionesJ2,
                                 vector<string>comentariosJ1, vector<string>comentariosJ2) {
    this->calificacionesJ1=calificacionesJ1;
    this->calificacionesJ2=calificacionesJ2;
    this->comentariosJ1=comentariosJ1;
    this->comentariosJ2=comentariosJ2;
}
