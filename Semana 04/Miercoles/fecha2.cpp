///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>

using namespace std;
///C++ lenguaje orientado a objetos
///POO (OOP) es una forma de entender la programacion -paradigma-
/// distinta de la programación estructurada

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
         void Mostrar();
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void MostrarDireccion(){
            cout<<"QUE ES this? "<<this<<endl;
            cout<<"PUNTERO OCULTO QUE CONTIENE LA DIRECCION DEL OBJETO QUE LLAMA AL METODO"<<endl;

        }
        ///DESTRUCTOR
        ~Fecha(){
            cout<<"SE MURIO EL OBJETO!! VIVA EL OBJETO!!!"<<endl;
        }
};

void Fecha::Mostrar(){
        cout<<this->dia<<"/"<<mes<<"/"<<anio<<endl;
}


int main(){
    Fecha hoy(17,8,2024);
    Fecha ayer;
    Fecha otro(5);

    hoy.Mostrar();
    ayer.Mostrar();
    otro.Mostrar();
	system("pause");
	return 0;
}

