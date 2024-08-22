#include "Incrementador.h"

Incrementador::Incrementador(int valorInicial, int valorIncremento){
  _valor = valorInicial;
  _valorIncremento = valorIncremento;
  
  _cantidadIncrementos = 0;
}

void Incrementador::incrementar(){
  _valor += _valorIncremento;
  _cantidadIncrementos++;
}

int Incrementador::getValor(){
  return _valor;
}

int Incrementador::getCantidadIncrementos(){
  return _cantidadIncrementos;
}
