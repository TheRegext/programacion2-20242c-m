#pragma once
#include <string>
#include "Servicio.h"

class ArchivoServicio{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoServicio(std::string nombreArchivo);
        bool Guardar(Servicio servicio);
        bool Guardar(Servicio servicio, int posicion);
        int Buscar(int IDServicio);
        Servicio Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Servicio *vector);
};
