///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

///PROTOTIPO O DECLARACION
void cargarVector(int *v, int tam);///*v<>v[]
void mostrarVector(int *v, int tam);
void sumarValoresVector(int *v,int tam, int &total);


int main(){
    const int TAM=5;
    int var1=TAM;

    int vec[TAM]={0};

    int *pVector;

    pVector=&var1;

    *pVector=15;

    cout<<var1<<endl;
    return 0;


    pVector=vec;
    cout<<"IMPRIMO vec[0] "<<vec[0]<<endl;
    cout<<"IMPRIMO vec "<<vec<<endl;
    cout<<"IMPRIMO pVector "<<pVector<<endl;
    cargarVector(vec,var1);
    mostrarVector(vec,var1);
    int sumaVector;
    sumarValoresVector(vec, var1, sumaVector);
    cout<<"DIRECCION sumaVector "<<&sumaVector<<endl;
    cout<<endl<<"SUMA DE LOS ELEMENTOS DEL VECTOR "<<sumaVector;


    ///cout<<"VALOR DE var1 "<<var1;
	cout<<endl;
	system("pause");
	return 0;
}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
    tam=114;///no tubo efecto sobre var1 de main()
}

void sumarValoresVector(int *v,int tam, int &total){
    cout<<"DIRECCION DE total "<<&total<<endl;
    int i;
    total=0;
    for(i=0;i<tam;i++){
        total+=v[i];
    }
}
