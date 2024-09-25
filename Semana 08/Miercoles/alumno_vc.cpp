///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>


using namespace std;

#include "alumno.h"

bool altaRegistro();
bool bajaRegistro();
bool modificacionRegistro();
void listadoRegistros();

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS"<<endl;
        cout<<"1. ALTA REGISTRO"<<endl;
        cout<<"2. BAJA REGISTRO"<<endl;
        cout<<"3. MODIFICACION REGISTRO"<<endl;///modificar fecha de nacimiento
        cout<<"4. LISTADO DE REGISTROS"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"*********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1: if(altaRegistro()) cout<<"SE AGREGO EL REGISTRO"<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
        case 2: if(bajaRegistro()) cout<<"EL REGISTRO FUE BORRADO "<<endl;
                else cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                break;
        case 3: if(modificacionRegistro()) cout<<"REGISTRO MODIFICADO"<<endl;
                else cout<<"NO SE PUDO MODIFICAR EL REGISTRO "<<endl;
                break;
        case 4: listadoRegistros();
                break;
        case 0: return 0;
                break;
        default: cout<<"OPCION INCORRECTA";
                break;
        }
        system("pause");


    }


    cout<<endl;
    system("pause");
	return 0;
}

bool altaRegistro(){
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL REGISTRO DEL ALUMNO A DAR DE ALTA ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo,TODOS);///puede ser que se haya encontrado o no el registro
    if(pos!=-1){
        cout<<"YA HAY UN REGISTRO DE ALUMNO CON ESE LEGAJO"<<endl;
        return false;
    }
    reg.Cargar(legajo);
    if(archi.grabarRegistro(reg))return true;
    return false;
    return true;
}

bool bajaRegistro(){
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL REGISTRO DEL ALUMNO A DAR DE BAJA ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo, ACTIVOS);///puede ser que se haya encontrado o no el registro
    if(pos==-1){
        cout<<"NO HAY REGISTROS DE ALUMNO CON ESE LEGAJO"<<endl;
        return false;
    }
    reg=archi.leerRegistro(pos);///se lee el registro y se lo copia en reg
    reg.setEstado(false);
    if(archi.modificarRegistro(reg,pos))return true;
    return false;
}

bool modificacionRegistro(){
    Fecha nueva;
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESAR LEGAJO DEL REGISTRO DEL ALUMNO A MODIFICAR ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo, ACTIVOS);///puede ser que se haya encontrado o no el registro
    if(pos==-1){
        cout<<"NO HAY REGISTROS DE ALUMNO CON ESE LEGAJO"<<endl;
        return false;
    }
    reg=archi.leerRegistro(pos);///se lee el registro y se lo copia en reg
    cout<<"INGRESE LA FECHA DE NACIMIENTO ";
    nueva.Cargar();
    reg.setFechaNacimiento(nueva);
    if(archi.modificarRegistro(reg,pos))return true;
    return false;
}


void listadoRegistros(){
    Alumno reg;
    ArchivoAlumnos archi;
    archi.listarRegistros();
}










































