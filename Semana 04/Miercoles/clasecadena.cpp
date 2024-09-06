///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;


class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *cad){///pedimos memoria en el constructor
         tam=strlen(cad)+1;
         p=new char[tam];
         if(p==nullptr)exit(1);
         strcpy(p,cad);
         p[tam-1]='\0';
    }
    ///set?

    ///gets
    char *getP(){return p;}
    int getTam(){return tam;}
    void Mostrar(){
        cout<<p<<endl;
    }

    ~Cadena(){///devolvemos la memoria en el destructor
        delete []p;
    }
};

///hacer un método aMayusculas() que ponga a todos los caracteres de tipo letra en mayúsculas
///hacer un método aMinusculas() que ponga a todos los caracteres de tipo letra en minúsculas
///hacer un método primeraMayuscula() que ponga al primer caracter de tipo letra en mayúsculas

int main(){
    /*Cadena palabra("HOLA A TODOS/AS LOS/LAS QUE ME CONOCEN!");
    cout<<palabra.getP()<<endl;
    palabra.Mostrar();
    cout<<endl;

    cout<<"TAMANIO "<<palabra.getTam();*/
    cout<<"ASCII de a "<<(int)'a'<<endl;
    cout<<"ASCII de z "<<(int)'z'<<endl;

    cout<<"ASCII de A "<<(int)'A'<<endl;
    cout<<"ASCII de Z "<<(int)'Z'<<endl;
    cout<<endl;
	system("pause");
	return 0;
}

