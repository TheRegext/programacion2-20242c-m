#include <iostream>

using namespace std;

int main(){
    int valorAcumulado, valorIncremento, cantidadIncrementos;
    bool opcion;
    
    valorAcumulado = 0;
    cantidadIncrementos = 0;
    
    valorIncremento = 10;
    
    cout << "Quiere incrementarlo? 1- Si 0-No"<<endl;
    cin >> opcion;
    
    while(opcion){
      valorAcumulado += valorIncremento;
      cantidadIncrementos++; 
    
      cout << "Quiere incrementarlo? 1- Si 0-No"<<endl;
      cin >> opcion;    
    }
    
    valorIncremento = 15;
    
    valorAcumulado -=valorIncremento;
    cantidadIncrementos++; 

    
    cout << "Valor final: " << valorAcumulado << endl;
    cout << "Cantidad incrementos: " << cantidadIncrementos << endl;
    
    return 0;
}
