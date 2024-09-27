
///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include <cstring>

using namespace std;

#include "modeloparcial.h"

class Punto1{
private:
    int numeroCompra, numeroProveedor;
    float importe;
public:
    int getNumeroCompra(){return numeroCompra;}
    int getNumeroProveedor(){return numeroProveedor;}
    float getImporte(){return importe;}

    void setNumeroCompra(int nc){numeroCompra=nc;}
    void setNumeroProveedor(int np){numeroProveedor=np;}
    void setImporte(float i){importe=i;}
};

class ArchivoPunto1{
    private:
        char nombre[30];
    public:
        ArchivoPunto1(const char *n="punto1.dat"){
            strcpy(nombre,n);
        }
        bool CrearDeCero(){
            FILE *p=fopen(nombre,"wb");
            if(p==NULL){
                return false;
            }
            fclose(p);
            return true;
        }
        Punto1 leerRegistro(int pos){
            Punto1 reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Punto1);
            fclose(p);
            return cant;
        }
        bool grabarRegistro(Punto1 reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

void punto1();
void punto2();
void punto3();

int main(){
    punto1();
    punto2();
    punto3();
	cout<<endl;
	system("pause");
	return 0;
}

///1) Generar un archivo con las compras realizadas este año.
///Cada registro debe tener el número de compra, el número de proveedor
///y el importe (5 puntos).

void punto1(){
    Compra reg;
    ArchivoCompras archiCompras("compras.dat");
    Punto1 aux;
    ArchivoPunto1 archiP1;
    archiP1.CrearDeCero();
    int cantReg=archiCompras.contarRegistros();
    if(cantReg==0){
        cout<<"ELA ARCHIVO NO TIENE REGISTROS"<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        reg=archiCompras.leerRegistro(i);
        ///verificar si la compra es de este año
        if(reg.getFechaCompra().getAnio()==2024){
            ///copio los valores correspondientes
            ///aux=reg; si se sobrecarga el = en la clase Punto1
            aux.setNumeroCompra(reg.getNumeroCompra());
            aux.setNumeroProveedor(reg.getNumeroproveedor());
            aux.setImporte(reg.getImporte());
            ///grabo el registro
            archiP1.grabarRegistro(aux);
        }
    }

}

int maximoVector(int *v, int tam){return 0;}

///2) Informar la provincia con más proveedores (3 puntos).
void punto2(){
    Proveedor  reg;
    ArchivoProveedores archiPro("proveedores.dat");
    int vProv[24]={0};
    int cantReg=archiPro.contarRegistros();
    for(int i=0;i<cantReg;i++){
            reg=archiPro.leerRegistro(i);
            vProv[reg.getProvincia()-1]++;
    }
    cout<<"PROVINCIA CON MAS PROVEEDORES "<<maximoVector(vProv, 24)+1<<endl;
}


void punto3(){}

bool buscarComprasAnio(int numeroProveedor,int anio){
    Compra reg;
    ArchivoCompras archiCompras("compras.dat");
    int cantReg=archiCompras.contarRegistros();
    if(cantReg==0){
        cout<<"ELA ARCHIVO NO TIENE REGISTROS"<<endl;
        return false;
    }
    for(int i=0;i<cantReg;i++){
        reg=archiCompras.leerRegistro(i);
        ///verificar si la compra es de este año
        if(reg.getFechaCompra().getAnio()==anio){
                if(reg.getNumeroproveedor()==numeroProveedor)
                    return true;
        }
    }
    return false;
}

void asignarComprasaProveedores(bool *vproveedores){
    Compra reg;
    ArchivoCompras archiCompras("compras.dat");
    int cantReg=archiCompras.contarRegistros();
    if(cantReg==0){
        cout<<"ELA ARCHIVO NO TIENE REGISTROS"<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        reg=archiCompras.leerRegistro(i);
        if(reg.getFechaCompra().getAnio()==2024)
            vproveedores[reg.getNumeroproveedor()-1]=true;
    }
 }


void punto2ConCompras2024(){
    Proveedor  reg;
    ArchivoProveedores archiPro("proveedores.dat");
    int vProv[24]={0};
    int cantReg=archiPro.contarRegistros();
    for(int i=0;i<cantReg;i++){
            reg=archiPro.leerRegistro(i);
            bool seCompro=buscarComprasAnio(reg.getNumeroProveedor(),2024);
            if(seCompro){
                vProv[reg.getProvincia()-1]++;
            }
    }
    cout<<"PROVINCIA CON MAS PROVEEDORES "<<maximoVector(vProv, 24)+1<<endl;
}

void otropunto2ConCompras2024(){
    Proveedor  reg;
    ArchivoProveedores archiPro("proveedores.dat");
    int vProv[24]={0};
    bool vproveedores[60]={0};
    asignarComprasaProveedores(vproveedores);
    int cantReg=archiPro.contarRegistros();
    for(int i=0;i<cantReg;i++){
            reg=archiPro.leerRegistro(i);
            bool seCompro=vproveedores[reg.getNumeroProveedor()-1];
            if(seCompro){
                vProv[reg.getProvincia()-1]++;
            }
    }
    cout<<"PROVINCIA CON MAS PROVEEDORES "<<maximoVector(vProv, 24)+1<<endl;
}
