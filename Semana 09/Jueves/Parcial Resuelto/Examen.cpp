#include <iostream>
using namespace std;

#include "Examen.h"
#include "Servicio.h"
#include "ArchivoServicio.h"

void Examen::EjemploDeListado(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}


///�Cu�ntos empleados hicieron por lo menos una reparaci�n sin hacer cambio de repuestos?
/*    Resultado: n�mero entre 0 y 20
    Tengo que contar para cada empleado cu�ntas reparaciones sin repuesto se hicieron, y luego contar cu�ntos tuvieron al menos 1
    reparaci�n sin repuestos.
    �C�mo se que es una servicio (reparaci�n) sin repuestos? getCostoRepuestos()==0
 */
/// (costo de repuestos igual a 0)


void Examen::Punto1(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;
   int vSinRepuestos[20]={0};///podr�a ser booleano

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
        registro = archivo.Leer(i);
        if(registro.getCostoRepuestos()==0){
            vSinRepuestos[registro.getIDPersonal()-1]++;
        }
   }

   int sinRepuestos=0;

   for(i=0;i<20;i++){
            if(vSinRepuestos[i]>0){
                sinRepuestos++;
            }
   }
   cout<<"CANTIDAD DE EMPLEADOS CON SERVICIOS SIN CAMBIO DE REPUESTOS "<<sinRepuestos<<endl;
   system("pause");
}


///La cantidad de servicios con fecha de entrega de este a�o con una cantidad de d�as (tiempo)
///mayor al promedio de tiempo general (sin analizar el a�o).

///* Calcular el promedio de tiempo de reparaci�n general
///* Comparar con los servicios que se realizaron este a�o
int sumarTiempos(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;
   int tiempoTotal=0;
   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
        registro = archivo.Leer(i);
        tiempoTotal+=registro.getTiempo();
   }
    return tiempoTotal;
}


void Examen::Punto2(){
    ArchivoServicio archivo("taller.dat");
    Servicio registro;
    int sumaTiempo;
    int cantidadRegistros = archivo.CantidadRegistros();
    sumaTiempo=sumarTiempos();
    float promedioTiempo=(float)sumaTiempo/cantidadRegistros;
    cout<<"PROMEDIO "<<promedioTiempo<<endl;
    system("pause");
    int lentos=0;
    for(int i = 0; i < cantidadRegistros; i++){
        registro = archivo.Leer(i);
        if(registro.getFecha().getAnio()==2024){
            if(registro.getTiempo()>promedioTiempo) lentos++;
        }
   }
   cout<<"CANTIDAD DE SERVICIOS 2024 CON TIEMPO MAYOR AL PROMEDIO "<<lentos<<endl;
   system("pause");
}

///Indicar si alguna de las siguientes ID de reparaciones recaud� m�s este a�o que el a�o pasado:
void Examen::Punto3(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;
   float vRec2023[70]={0};
   float vRec2024[70]={0};

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
        registro = archivo.Leer(i);
        if(registro.getFecha().getAnio()==2024){
            vRec2024[registro.getIDServicio()-1]+=registro.getImporte();
        }
        if(registro.getFecha().getAnio()==2023){
            vRec2023[registro.getIDServicio()-1]+=registro.getImporte();
        }
   }
   for(i=0;i<70;i++){
        if(vRec2024[i]>vRec2023[i]){
            cout<<"IDREPARACION MAYOR 2024 QUE 2023 "<<i+1<<endl;
        }
   }

}
