#pragma once
#include "Fecha.h"

/* Aclaración de lo que significa cada propiedad
    _IDServicio: identificador único para cada servicio de reparación
    _IDPersonal: identifica a cada empleado. Hay 20 en total con una ID entre el 1 y el 20
    _IDReparacion: identifica a cada uno de los tipos de reparaciones que hace el taller. Son 70 y están definidas entre 1 y 70
    _tiempo: es el tiempo en días que se tardó en realizar la reparación.
    _calificacion: es el puntaje que el cliente le puso al servicio
    _costoRepuestos: es el valor del costo de los repuestos usados en el servicio. Si no se usaron repuestos el valor es 0
    _importe: es el importe que se le cobró al cliente por el servicio;
    _fecha: es la fecha de entrega del vehículo, al finalizar el servicio
*/


class Servicio{
    private:
        int _IDServicio, _IDPersonal, _IDReparacion, _tiempo;
        float _calificacion, _costoRepuestos, _importe;
        Fecha _fecha;

    public:
    Servicio();
    Servicio(int IDServicio, int IDpersonal, int IDReparacion, int tiempo, float calificacion, float costoRepuestos, float importe, Fecha fecha);

    int getIDServicio();
    int getIDPersonal();
    int getIDReparacion();
    int getTiempo();
    float getCalificacion();
    float getCostoRepuestos();
    float getImporte();
    Fecha getFecha();

    void setIDServicio(int IDServicio);
    void setIDPersonal(int IDPersonal);
    void setIDReparacion(int IDReparacion);
    void setTiempo(int tiempo);
    void setCalificacion(float calificacion);
    void setCostoRepuestos(float costoRepuestos);
    void setImporte(float Importe);
    void setFecha(Fecha fecha);

    std::string toCSV();
    void Mostrar();

};
