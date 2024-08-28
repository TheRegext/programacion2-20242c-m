///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

void mostrarCadenas(char *cad);
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void cargarPalabras(char palabras[10][20],int tam);
void mostrarPalabras(char palabras[][20],int tam);

int main(){
 //   char letra='c';
    char palabra[20], varias[10][20];
    char apellido[20];
    /*
///    tipo *nombreVariable;///puntero->variable que almacena direcciones.
//    cin>>numeros;
    cargarCadena(palabra,19);
    strcpy(apellido,palabra);
    cout<<apellido<<endl;
    if(strcmp(palabra,apellido)==0){
        cout<<"IGUALES";
    }
    else{
        cout<<"DISTINTAS";
    }
    cout<<endl;  */
    cargarPalabras(varias,3);
    mostrarPalabras(varias, 3);
    system("pause");
	return 0;
}

void mostrarCadenas(char *cad){
    int i=0;
    while(cad[i]!='\0'){
        cout<<cad[i];
        i++;
    }

}

///strcmp(char *n1, char *n2)
        ///si devuelve 0 n1 y n2 son iguales
        ///si devuelve <0 n1 es "menor" a n2
        ///ORDEN LEXICOGRAFICO-> más chico más cerca del principio del diccionario
        ///si devuelve mayor a 0 n1 es "mayor" que n2

///strlen()-> cantidad de caracteres de una cadena

void cargarPalabras(char (*palabras)[20],int tam){
    int i;
    for(i=0;i<tam;i++){
        cargarCadena(palabras[i], 20);
    }

}
void mostrarPalabras(char palabras[][20],int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<palabras[i]<<endl;
    }

}
