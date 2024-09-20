///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///SOBRECARGA DE OPERADORES
        bool operator==(Fecha aux);
        bool operator==(const char *valorMes);
        bool operator!=(Fecha aux);
        void operator +=(int d);



        ///FIN SOBRECARGA DE OPERADORES

        ///DESTRUCTOR
        ~Fecha(){

        }

};
 ///fin de la definición de la clase
///desarrollo de los métodos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}

///SOBRECARGAS
bool Fecha::operator==(Fecha aux){
   if(dia!=aux.dia) return false;
   if(mes!=aux.mes) return false;
   if(anio!=aux.anio) return false;
   return true;
}

bool Fecha::operator!=(Fecha aux){
    if (dia!=aux.dia || mes!=aux.mes || anio!=aux.anio)return true;
    return false;
}
///OTRA FORMA
/*
bool operator!=(Fecha aux){
            return !(*this==aux);-> *this es el objeto que llama al método
        }
*/

bool Fecha::operator==(const char *valorMes){
    string meses[12]={"ENERO","FEBRERO","DICIEMBRE"};

    return true;
}

void Fecha::operator +=(int d){
    int sumaMeses=d/30;
    int sumaDias=d%30;
    dia+=sumaDias;
    mes+=sumaMeses;

    int sumaAnio=mes/12;
    anio+=sumaAnio;
    mes=mes%12;

}
///FIN SOBRECARGAS
/// fin desarrollo de los métodos de Fecha

///SOBRECARGA DE OPERADORES: permite agregarle funcionalidad a los operadores del lenguaje.Esto se logra escribiendo el
///código correspondiente dentro de la clase, siguiendo las reglas establecidas para ello.

int main(){
    Fecha var(1,10,2024), obj1(11,9,2024);
    cout<<"ANTES DE SUMAR DIAS ";
    var.Mostrar();
    cout<<endl;
    cout<<"DESPUES DE SUMAR 1 DIA ";
    var+=95;
    var.Mostrar();
    /*if(var.getDia()==obj1.getDia() && var.getMes()==obj1.getMes() && var.getAnio()==obj1.getAnio()){
        cout<<"FECHAS IGUALES "<<endl<<endl;
    }

    ///if(var.operator==(obj1)){
    if(var!=obj1){
            cout<<"FECHAS DISTINTAS ";
    }
    else  cout<<"FECHAS IGUALES ";

    ///if(var=="ENERO")

    //if(var!=obj1){}
    obj1+=5;///que le sume 5 días al valor que el objeto tiene
	*/
	cout<<endl;
	system("pause");
	return 0;
}



