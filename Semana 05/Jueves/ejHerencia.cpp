///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;


class MiBase{
///private:///lo que es privado no es accesible bajo ninguna acción
        /// fuera de la clase donde fue declarado
protected:
    int num1, num2;
public:
    int getNum1(){return num1;}
    int getNum2(){return num2;}

    void setNum1(int n){num1=n;}
    void setNum2(int n){num2=n;}
};


///class Derivada1: ESPECIFICADOR DE ACCESO MiBase
///class Derivada1: MiBase por defecto (no pongo nada es private)

///class Derivada1: private MiBase ->todo lo de MiBase pasa a la parte
///privada de Derivada1

///class Derivada1: public MiBase ->la parte privada de MiBase pasa
///a la parte privada de Derivada1,y lo mismo pasa con lo público


class Derivada1:public MiBase{
private:
    string nombre;
public:
    string getNombre(){return nombre;}
    void setNombre(string n){nombre=n;}

    void duplicarNum1(){num1=num1*2;}///num1*=2;
    ///void duplicarNum1(){setNum1(getNum1()*2);}///num1*=2;
};

///Resultado de derivar Derivada1 de MiBase de manera privada queda
/*
class Derivada1{
private:
    int num1, num2;
    string nombre;
    int getNum1(){return num1;}
    int getNum2(){return num2;}

    void setNum1(int n){num1=n;}
    void setNum2(int n){num2=n;}
public:
    string getNombre(){return nombre;}
    void setNombre(string n){nombre=n;}


};
*/
///Resultado de derivar Derivada1 de MiBase de manera publica queda
/*
class Derivada1{
private:
    int num1, num2;
    string nombre;

public:
    string getNombre(){return nombre;}
    void setNombre(string n){nombre=n;}
    ///vienen de MiBase
    int getNum1(){return num1;}
    int getNum2(){return num2;}
    void setNum1(int n){num1=n;}
    void setNum2(int n){num2=n;}

};

 */

int main(){
    Derivada1 obj;
    obj.setNum1(5);
    obj.setNum2(5);
    obj.setNombre("prueba");
    obj.duplicarNum1();
    cout<<obj.getNum1();
	cout<<endl;
	system("pause");
	return 0;
}
