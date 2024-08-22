///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarVector(int *v,int tam );
void mostrarVector(int *v,int tam );
void ordenarVector(int *v, int tam);

int main(){
    int v[5];
    cargarVector(v,5);
    cout<<endl<<endl;
    mostrarVector(v,5);
    cout<<endl<<endl;
    ordenarVector(v,5);
    mostrarVector(v,5);
	cout<<endl;
	system("pause");
	return 0;
}

void cargarVector(int *v,int tam ){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }

}
void mostrarVector(int *v,int tam ){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }

}

void ordenarVector(int *v, int tam){
    int i, j;
    int aux, posMin;
    for(i=0;i<tam-1;i++){
        posMin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posMin])posMin=j;
        }
        aux=v[i];
        v[i]=v[posMin];
        v[posMin]=aux;
    }
}
