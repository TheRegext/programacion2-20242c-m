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
         ///   cout<<"SE MURIO EL OBJETO!! VIVA EL OBJETO!!!"<<endl;
        }
        /*void CargarVector(Fecha *vec, int tam){///NO VA DENTRO DE LA CLASE.
            int i;
            for(i=0;i<tam;i++){
                vec[i].Cargar();
            }
        }

        void MostrarVector(Fecha *vec, int tam){
            int i;
            for(i=0;i<tam;i++){
                vec[i].Mostrar();
            }
        } LA CLASE DEBE PROPORCIONAR TODAS LAS HERRAMIENTAS QUE NECESITA 1 OBJETO DE LA CLASE*/

};

void Fecha::Mostrar(){
        cout<<this->dia<<"/"<<mes<<"/"<<anio<<endl;
}

///FUNCIONES GLOBALES PARA CARGAR Y MOSTRAR EL VECTOR
void CargarVector(Fecha *vec, int tam){
            int i;
            for(i=0;i<tam;i++){
                ///vec[i].Cargar();
                /*vec->Cargar();
                vec++;*/
                (*(vec+i)).Cargar();

            }
        }

        void MostrarVector(Fecha *vec, int tam){
            int i;
            for(i=0;i<tam;i++){
                vec[i].Mostrar();
            }
        }


int main(){
    Fecha vdias[5], obj, *pObj;
    int v[5];

    pObj=&obj;
    cout<<pObj<<endl;
    (*pObj).Mostrar();
    pObj->Mostrar();
    //cout<<sizeof(Fecha)<<endl;
    //cout<<sizeof(int)<<endl;
    //cout<<sizeof vdias<<endl;
    /*cout<<"DISTANCIA EN BYTES ENTRE LA POSICION 1 Y LA 0 DEL VECTOR DE FECHAS ";
    cout<<sizeof(Fecha)*((vdias+1)-vdias)<<endl<<endl;
    cout<<"DISTANCIA EN BYTES ENTRE LA POSICION 1 Y LA 0 DEL VECTOR DE ENTEROS ";
    cout<<sizeof(int)*((v+1)-v)<<endl;

    CargarVector(vdias,3);
    MostrarVector(vdias,3);*/
	system("pause");
	return 0;
}

