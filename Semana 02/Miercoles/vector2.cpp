///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;


int main(){
    int mat[5][5];
    int (*m)[5];
    m=mat;
    cout<<&mat[2]-m<<endl;
    system("pause");


    cout<<"TAMANIO DEL TIPO int "<<sizeof(long int)<<endl;
    cout<<"TAMANIO DE mat "<<sizeof mat<<endl<<endl;
    system("pause");
    cout<<mat<<endl;
    cout<<&mat[0]<<endl;
    cout<<&mat[0][0]<<endl;
    cout<<&mat[0][1]<<endl;
    cout<<&mat[0][2]<<endl;
    system("pause");
    system("cls");
    mat[1][0]=123;
    cout<<"muestro mat[1][0] "<<mat[1][0]<<endl;
    cout<<"muestro mat[0][5] "<<mat[0][5]<<endl;


	cout<<endl;
	system("pause");
	return 0;
}
