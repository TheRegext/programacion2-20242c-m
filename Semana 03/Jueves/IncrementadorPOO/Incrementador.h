#pragma once

class Incrementador
{
  public:
    Incrementador(int valorInicial, int valorIncremento);
    void incrementar();
    int getValor();
    int getCantidadIncrementos();

  private:
    int _valor;
    int _valorIncremento;
    int _cantidadIncrementos;
};
