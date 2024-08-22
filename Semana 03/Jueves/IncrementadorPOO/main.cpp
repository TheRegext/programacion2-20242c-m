#include <iostream>
#include "Incrementador.h"
using namespace std;

void mostrarIncrementador(Incrementador obj);

int main(){
    bool opcion;
    Incrementador objIncrementador(0,10);    /// instancio el objeto
    Incrementador inc(10, 2);
    // objIncrementador.setValor(0);
    // objIncrementador.setValorIncremento(10);
    
    cout << "Quiere incrementarlo? 1- Si 0- No"<<endl;
    cin >> opcion;
    
    while(opcion){
      objIncrementador.incrementar();
      inc.incrementar();
    
      cout << "Quiere incrementarlo? 1- Si 0-No"<<endl;
      cin >> opcion;    
    }
    
    objIncrementador.incrementar();
    
    mostrarIncrementador(objIncrementador);
    mostrarIncrementador(inc);
    return 0;
}

void mostrarIncrementador(Incrementador obj){
    cout << "Valor final: " << obj.getValor() << endl;
    cout << "Cantidad incrementos: " << obj.getCantidadIncrementos() << endl;
}
