///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>///istream ostream
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
    friend void soyAmiga(Cadena obj);

    friend ostream& operator<<(ostream &salida,Cadena obj);
	friend istream& operator>>(istream &entrada,Cadena &obj);

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

ostream& operator<<(ostream &salida,Cadena obj)
	{
	cout<<obj.p;
	return salida;
	}

istream& operator>>(istream &entrada,Cadena &obj)
	{
	char palabra[50];///ojo!! se establece un límite para el tamaño de la cadena
	entrada.getline(palabra, 50);
	delete obj.p;
	obj.tam=strlen(palabra)+1;
	obj.p=new char[obj.tam];
	if(obj.p==NULL) exit(1);
	strcpy(obj.p,palabra);
	return entrada;
	}

///FIN SOBRECARGAS
///fin métodos


void soyAmiga(Cadena obj){
     cout<<obj.p<<endl;
     cout<<obj.tam<<endl;
    }

int main(){
    Cadena palabra("Prueba"), otra(" "),nombre("Kloster");
    //soyAmiga(palabra);

    cin>>palabra;
    cout<<palabra;
    cout<<endl;
	system("pause");
	return 0;
}
