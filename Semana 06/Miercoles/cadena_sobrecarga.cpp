///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>
///Hacer una clase de nombre Cadena para almacenar palabras,
///que ajuste su tamaño a la cantidad de caracteres estrictamente necesarios

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *texto="NADA"){
        tam=strlen(texto)+1;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,texto);
        p[tam-1]='\0';
    }
    void Mostrar(){
        cout<<p<<endl;
    }
    int getTamanio(){return tam;}
    ///sobrecarga de operadores
    Cadena operator=(Cadena aux);
    bool operator==(Cadena aux);
    void operator+=(Cadena aux);
    char operator[](int pos);


};
///desarrollo de métodos
///SOBRECARGAS
Cadena Cadena::operator=(Cadena aux){
    delete []p;
    tam=aux.tam;
    p=new char[tam];
    if(p==nullptr)exit(1);
    strcpy(p,aux.p);
    return *this;
}

bool Cadena::operator==(Cadena aux){
    return !strcmp(p,aux.p);///0= si son iguales; 1 si la cadena primera es "mayor" que la segunda;
}                       /// -1 si la primera es menor a la segunda

void Cadena::operator+=(Cadena aux){
    Cadena temp=*this;
    delete []p;
    tam=temp.tam+aux.tam-1;
    p=new char[tam];
    if(p==NULL)exit(1);
    strcpy(p,temp.p);
    strcat(p,aux.p);

}

char Cadena::operator[](int pos){
    if(pos>=0 && pos<tam) return p[pos];
    return '\0';
}
///FIN SOBRECARGAS
///fin métodos

int main(){
    Cadena palabra("Daniel"), otra(" "),nombre("Kloster");
    cout<<palabra[3]<<endl;
    system("pause");

    ///palabra=otra=nombre;
    //cout<<"Objeto otra antes de la asignación ";
    otra.Mostrar();
    /*cout<<endl;
    cout<<"Objeto otra después de la asignación ";
    otra=palabra;
    otra.Mostrar();*/
    /*if(palabra==otra){
        cout<<"LAS CADENAS SON IGUALES ";
    }
    else{
        cout<<"LAS CADENAS SON DISTINTAS";
    } */
    palabra+=otra;
    palabra+=nombre;

    palabra.Mostrar();

    cout<<endl;
	system("pause");
	return 0;
}
