///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Fecha{
    private:///sólo es accesible dentro de la clase
        int dia, mes, anio;///propiedades->variables de la clase
    public:///puede ser accedido tanto dentro como fuera de la clase
         Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
         }

         void Cargar(){ ///métodos o funciones de la clase
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }
         void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }
        ///setter
        bool setDia(int dia){
             if(dia>=1 &&dia<=31){
                    this->dia=dia;
                    return true;
             }
             this->dia=0;
             return false;
        }
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        ///DESTRUCTOR
        ~Fecha(){

        }
};
///EN HERENCIA clase DERIVADA es clase BASE
///EN COMPOSICION clase TIENE como propiedad un OBJETO DE OTRA CLASE

class Persona{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    Fecha fechaNacimiento;///COMPOSICION: SE USA UN OBJETO DE UNA CLASE COMO PROPIEDAD DE OTRA CLASE
    ///completar con los métodos de la presentación
public:
    void Cargar();
    void Mostrar();
};

void Persona::Cargar(){
    cout<<"DNI ";
    cin>>DNI;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"DNI "<<DNI<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Mostrar();
}


class Alumno:Persona{
private:
        int legajo;
        Fecha fechaInscripcion;
public:
        void Cargar(){
            Persona::Cargar();
            cout<<"LEGAJO ";
            cin>>legajo;
            cout<<"FECHA DE INSCRIPCION ";
            fechaInscripcion.Cargar();
        }
        void Mostrar(){
            Persona::Mostrar();
            cout<<"LEGAJO "<<legajo<<endl;
            cout<<"FECHA DE INSCRIPCION "<<endl;
            fechaInscripcion.Mostrar();
        }


};

int main(){
    Alumno obj;
    obj.Cargar();
    obj.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
