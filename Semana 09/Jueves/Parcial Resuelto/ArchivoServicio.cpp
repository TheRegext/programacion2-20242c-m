#include "Fecha.h"
#include "ArchivoServicio.h"

ArchivoServicio::ArchivoServicio(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoServicio::Guardar(Servicio servicio){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoServicio::Guardar(Servicio servicio, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Servicio) * posicion, SEEK_SET);
    bool ok = fwrite(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoServicio::Buscar(int IDServicio){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Servicio servicio;
    int i = 0;
    while(fread(&servicio, sizeof(Servicio), 1, pArchivo)){
        if(servicio.getIDServicio() == IDServicio){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Servicio ArchivoServicio::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Servicio();
    }
    Servicio servicio;
    fseek(pArchivo, sizeof(Servicio) * posicion, SEEK_SET);
    fread(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return servicio;
}

int ArchivoServicio::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Servicio);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoServicio::Leer(int cantidadRegistros, Servicio *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Servicio), 1, pArchivo);
    }
    fclose(pArchivo);
}
