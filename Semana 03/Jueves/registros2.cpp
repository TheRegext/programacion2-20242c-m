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
         void setDia(int d){
             if(d>=1 &&d<=31)dia=d;
             else dia=0;
             }
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

void Fecha::Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main(){
    Fecha hoy;
    Cargar();
    hoy.Cargar();
    hoy.Mostrar();
    hoy.setDia(21);
    hoy.setMes(8);
    hoy.setAnio(2024);
    hoy.Mostrar();
	cout<<endl;
	cout<<hoy.getAnio();
	if(hoy.getMes()==8){
        cout<<"ESTAMOS EN AGOSTO"<<endl;
	}
	system("pause");
	return 0;
}

