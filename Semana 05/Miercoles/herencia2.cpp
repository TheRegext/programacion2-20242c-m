///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Fecha{
    private:///s�lo es accesible dentro de la clase
        int dia, mes, anio;///propiedades->variables de la clase
    public:///puede ser accedido tanto dentro como fuera de la clase
         Fecha(int d=1, int m=2, int a=3){
            dia=d;
            mes=m;
            anio=a;
         }

         void Cargar(){ ///m�todos o funciones de la clase
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

///Especificadore de acceso
    ///private: s�lo accesible dentro de la clase
    ///public: accesible dentro y fuera de la clase
    ///protected: la misma protecci�n que private, pero permite el acceso directo a las propiedades
    /// en las clases derivadas
class Persona{
protected:
    int DNI;
    char nombre[30];
    char apellido[30];
    Fecha fechaNacimiento;///COMPOSICION: SE USA UN OBJETO DE UNA CLASE COMO PROPIEDAD DE OTRA CLASE
    ///completar con los m�todos de la presentaci�n
public:
    void Cargar();
    void Mostrar();
    void setDNI(int d){DNI=d;}
    int getDNI(){return DNI;}
    void setDia(int d){fechaNacimiento.setDia(d);}
    int getDia(){return fechaNacimiento.getDia();}

    Fecha getFechaNacimiento(){return fechaNacimiento;}
    void setFechaNacimiento(Fecha aux){fechaNacimiento=aux;}
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

///FORMAS DE HEREDAR
    ///si no se pone nada (defecto) o se pone private, la herencia en de manera privada
    ///Al herederar de manera privada TODO lo que tiene la clase base PASA a la parte privada de la derivada

    ///si se hereda de manera p�blica (public) lo que est� en privado de la clase base, pasa a la parte privada
    ///de la derivada, y lo p�blico pasa a la parte p�blica
class Alumno:public Persona{
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
        int getDNI2(){return getDNI();}
        void setDNI2(int x){setDNI(x);}

        void otroSetDeDNI(int valor){DNI=valor;} ///no se puede hacer porque se rompe el principio m�s elemental
        ///  ya que DNI esta declarado de manera privada en la clase base
};

int main(){
    Alumno obj;
  //  obj.Cargar();
 //   obj.Mostrar();
    //obj.setDia(12);
    //cout<<obj.getDia();
	Fecha aux;
	aux=obj.getFechaNacimiento();
	aux.Mostrar();
	cout<<endl;

	obj.getFechaNacimiento().Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
