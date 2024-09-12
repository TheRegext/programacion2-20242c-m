# include<iostream>
# include<cstdlib>
# include<cstdio>
# include<cstring>
#include <windows.h>
#include <ctime>

using namespace std;


///DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color{
    cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el número 15

void ocultarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x, short y){ ///UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
///ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto=15, int colorFondo=0){
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES


///CLASE PUNTO
class Punto {
    private:
        int x;
        int y;
        int color;
    public:
        Punto(int a=0, int b=0, int nuevoColor=cNEGRO){
            x=a;
            y=b;
            color=nuevoColor;
        }
        void Mostrar(){
            textcolor(color, 15);
            gotoxy(x,y);
            cout<<(char)219;
        }
        void MostrarValores();
        void Ocultar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void setX(int valor){
            if(valor>=0 && valor<=166)  x=valor;
        }
        void setY(int valor){
            if(valor>=0)  y=valor;
        }
        void setColor(int nuevo){
            if(nuevo>0 && nuevo<=15){
                color=nuevo;
            }else{
                color=nuevo%16;
            }
        }
        int getX(){return x;}
        int getY(){return y;}
        int getColor(){return color;}
        ~Punto(){///DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su alcance.
            textcolor(cBLANCO,cNEGRO);
        }
};

void Punto::MostrarValores(){
        cout<<x<<endl;
        cout<<y<<endl;
        cout<<color<<endl;
    }



void punto1(){
    Punto obj(10,5, cAZUL);
    obj.Mostrar();

}

int main() {
    srand(time(NULL));
    ocultarCursor();
    textcolor(0,15);
    int opc;
    while(true){
        textcolor(0,15);
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"<<endl;
        cout<<"2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE Y DEFINIDA"<<endl;
        cout<<"3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X DEFINIDA"<<endl;
        cout<<"4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"<<endl;
        cout<<"6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<"7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE LA PANTALLA "<<endl;
        cout<<" Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE DISTINTOS COLORES "<<endl;
        cout<<" AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 DE Y "<<endl;
        cout<<"12. DIBUJAR UNA LLUVIA DE PUNTOS"<<endl;
        cout<<"13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                punto1();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 0:
                return 0;

        }
        system("pause>nul");

    }
    return 0;
}

