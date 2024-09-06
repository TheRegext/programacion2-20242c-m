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

void cargarVectorEnteros(int *v, int tam){}
void mostrarVectorEnteros(int *v,int tam){}

void cargarVectorFechas(Fecha *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Cargar();
    }
}

void mostrarVectorFechas(Fecha *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Mostrar();
    }
}

int main(){
    int v[3];
    ///cargarVectorEnteros(v,3);
    ///mostrarVectorEnteros(v,3);


    Fecha vDias[3];
    cargarVectorFechas(vDias,3);
    mostrarVectorFechas(vDias,3);


	cout<<endl;
	system("pause");
	return 0;
}
