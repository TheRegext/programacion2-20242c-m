///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>

///ASIGANACI�N DIN�MICA DE MEMORIA: ES UN MECANISMO QUE NOS PERMITE CREAR
///VARIABLES EN TIEMPO DE EJECUCI�N. EL CICLO DE VIDA DE ESA VARIABLE
/// EST� TAMBI�N DETERMINADO POR EL PROGRAMA QUE LAS CREA

using namespace std;

void cargarVector(float *v,int tam );
void mostrarVector(float *v,int tam );

int main(){
    int cantMaterias;
    cout<<"INGRESE LA CANTIDAD DE MATERIAS DE LA CARRERA A ANALIZAR ";
    cin>>cantMaterias;
    float *vImp;///float vImp[20]

    /// new tipoDato[cantidad de componentes]

    vImp=new float[cantMaterias];///pedido de memoria
    if(vImp==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return -1;
    }
    ///c�digo donde se usa el vector
    cargarVector(vImp, cantMaterias);
    mostrarVector(vImp, cantMaterias);

    ///ya no lo necesito m�s, devuelvo la memoria
    delete []vImp;///devuelve la memoria pedida

	cout<<endl;
	system("pause");
	return 0;
}

void cargarVector(float *v,int tam ){
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESAR VALOR ";
        cin>>v[i];
    }

}

void mostrarVector(float *v,int tam ){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }

}
