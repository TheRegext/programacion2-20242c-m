#include <iostream>
using namespace std;
#include "Servicio.h"


Servicio::Servicio(){
    _IDServicio = 0;
    _IDPersonal = 0;
    _IDReparacion = 0;
    _tiempo= 0;
    _calificacion = 0;
    _costoRepuestos = 0;
    _importe = 0;
    _fecha = Fecha();
}

Servicio::Servicio(int IDServicio, int IdPersonal, int IDReparacion, int tiempo, float calificacion, float costoRepuestos, float importe, Fecha fecha){
    _IDServicio = IDServicio;
    _IDPersonal = IdPersonal;
    _IDReparacion = IDReparacion;
    _tiempo = tiempo;
    _calificacion = calificacion;
    _costoRepuestos = costoRepuestos;
    _importe = importe;
    _fecha = fecha;
}

int Servicio::getIDServicio(){
    return _IDServicio;
}

int Servicio::getIDPersonal(){
    return _IDPersonal;
}

int Servicio::getIDReparacion(){
    return _IDReparacion;
}

int Servicio::getTiempo(){
    return _tiempo;
}

float Servicio::getCalificacion(){
    return _calificacion;
}

float Servicio::getCostoRepuestos(){
    return _costoRepuestos;
}

float Servicio::getImporte(){
    return _importe;
}

Fecha Servicio::getFecha(){
    return _fecha;
}

void Servicio::setIDServicio(int IDServicio){
    _IDServicio = IDServicio;
}

void Servicio::setIDPersonal(int IDPersonal){
    _IDPersonal = IDPersonal;
}

void Servicio::setIDReparacion(int IDReparacion){
    _IDReparacion = IDReparacion;
}

void Servicio::setTiempo(int tiempo){
    _tiempo = tiempo;
}

void Servicio::setCalificacion(float calificacion){
    _calificacion = calificacion;
}

void Servicio::setCostoRepuestos(float costoRepuestos){
    _costoRepuestos = costoRepuestos;
}

void Servicio::setImporte(float importe){
    _importe = importe;
}

void Servicio::setFecha(Fecha fecha){
    _fecha = fecha;
}

std::string Servicio::toCSV(){

    std::string str = std::to_string(_IDServicio) + "," + std::to_string(_IDPersonal) + "," + std::to_string(_IDReparacion) + "," + std::to_string(_tiempo) + "," + std::to_string(_calificacion) + "," + std::to_string((int) _costoRepuestos) + "," + std::to_string((int) _importe) + "," + _fecha.toString();
    return str;
}

void Servicio::Mostrar(){
    cout<<"Servicio "<<_IDServicio<<endl;
    cout<<"IDPersonal "<<_IDPersonal<<endl;
    cout<<"IDReparacion "<<_IDReparacion<<endl;
    cout<<"Tiempo "<<_tiempo<<endl;
    cout<<"Calificacion "<<_calificacion<<endl;
    cout<<"Costo repuestos "<<_costoRepuestos<<endl;
    cout<<"Importe "<<_importe<<endl;
    cout<<"Fecha de entrega "<< _fecha.toString()<<endl;


}
