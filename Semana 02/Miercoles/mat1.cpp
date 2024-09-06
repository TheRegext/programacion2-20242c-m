///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
     //   cin>>v[i];
        v[i]=i+1;
    }
}
///void cargarMatriz(int m[3][5], int fila, int columna){
///void cargarMatriz(int m[][5], int fila, int columna){
void cargarMatriz(int (*m)[5], int fila, int columna){
    int i, j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
             cout<<"INGRESAR NUMERO ";
             cin>>m[i][j];
        }
    }
}

void mostrarMatriz(int m[3][5], int fila, int columna){
    int i, j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++){
             cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main(){
    int mat[3][5];
///    nombre_matriz->puntero a toda una fila de n cantidad de elementos
///    si le antepongo *->*nombre_matriz->dirección del elemento [0][0] de la matriz
///    cargarMatriz(mat,3,5);
    cargarVector(*mat,15);
    mostrarMatriz(mat, 3, 5);
	cout<<endl;
	cout<<**mat<<endl;
	system("pause");
	return 0;
}
