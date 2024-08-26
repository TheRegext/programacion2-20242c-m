///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;


int main(){
    string palabra, otra;
    getline(cin,palabra);
    /*otra=palabra;
    if(otra==palabra){
        cout<<"IGUALES";
    }
    else{
        cout<<"DISTINTAS";
    }
    */
    char cadena[20];
    //cout<<palabra.c_str()<<endl;
    strcpy(cadena,palabra.c_str());
    cout<<cadena;
	cout<<endl;
	system("pause");
	return 0;
}
