#include <iostream>
using namespace std;

class Persona{
  public:       
    Persona(string,int); //constructor
    string nombre;
    int edad;
    ~Persona(); //destructor
    virtual void mostrar(); //función de polimorfismo va en la clase padre
};

Persona::Persona(string _nombre, int _edad)
{
    nombre=_nombre;
    edad=_edad;
};

Persona::~Persona(){ };

void Persona::mostrar()
{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
};

class Alumno : public Persona
{
    public:
        Alumno (string,int,float); //constructor de Alumno
        void mostrar();
        float notaFinal;
};

Alumno::Alumno(string _nombre,int _edad, float _notaFinal) : Persona (_nombre,_edad)
{
    notaFinal=_notaFinal;
};

class Profesor : public Persona{
    private:
        string materia;
    public:
        Profesor(string,int,string);
        //~Profesor();
        void mostrar();
};

Profesor::Profesor(string _nombre, int _edad, string _materia) : Persona(_nombre,_edad){
    materia = _materia;
};

void Profesor::mostrar(){
    Persona::mostrar();
    cout << "Materia: " << materia << endl;
}

void Alumno :: mostrar()
{
    Persona::mostrar();
    cout<<"Nota Final: "<<notaFinal<<endl;
};

int main(){
    setlocale(LC_ALL,"");
    Persona *lista[3];
    lista[0]= new Profesor("Pepe",28,"logica");
    lista[1]= new Alumno("Juan",17,3);
    lista[2]= new Alumno("Luis",45,2);

    Persona *lista2[5];
    lista2[0]= new Profesor("Cecilio",28,"Programación");
    lista2[1]= new Alumno("Carlos",17,3);
    lista2[2]= new Alumno("Luis",45,2);
    lista2[3]= new Alumno("María",36,2.5);
    lista2[4]= new Alumno("Carl",9,5);

    cout<<"Los estudiantes que perdieron con menos de 3 son: "<<endl;

    for(int i=1;i<5;i++){
        Alumno *alumno = dynamic_cast<Alumno*>(lista2[i]);
        if(alumno != nullptr && alumno->notaFinal < 3){
            cout << "Nombre: " << alumno->nombre << ", Edad: "<< alumno->edad << ", Nota Final: " << alumno->notaFinal << endl;
        }
    }
    return 0;
}
