///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
///# include<cstdio>

using namespace std;

///Hace un proyecto con un menú para cargar (1 registro) y mostrar los registros de alumnos
///Usar los .h y .cpp según corresponda.



class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};
 ///fin de la definición de la clase
///desarrollo de los métodos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}
///fin de clase Fecha
///desarrollo de clase Alumno
class Alumno{
private:
    int legajo;
    char nombre[30];
    char apellido[30];
    Fecha fechaNacimiento;
    char email[50];
    int codigoCarrera;
public:
    void Cargar();
    void Mostrar();
};
///Métodos de alumno
void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"EMAIL ";
    cin>>email;
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO ";
    cout<<legajo<<endl;
    cout<<"NOMBRE ";
    cout<<nombre<<endl;
    cout<<"APELLIDO ";
    cout<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
    cout<<"EMAIL ";
    cout<<email<<endl;
    cout<<"CARRERA ";
    cout<<codigoCarrera<<endl;
}

bool grabarRegistroAlumno(Alumno reg){
	FILE *pAlumno;
	pAlumno=fopen("alumnos.dat","ab" );//si no puede hacer la apertura fopen devuelve NULL
		///modo de apertura	wb (write)-> Escritura. siempre crea un archivo nuevo
					///rb (read) -> solo lectura. El archivo tiene que existir
					///ab (append)-> Para agregar registros. Si no existe el archivo lo crea
	if(pAlumno==NULL) return false;
    int escribio=fwrite(&reg,sizeof(Alumno),1,pAlumno);
	fclose(pAlumno);
	return escribio;

}

bool leerRegistroAlumno(Alumno &reg){
	FILE *pAlumno;
	pAlumno=fopen("alumnos.dat","rb" );//si no puede hacer la apertura fopen devuelve NULL
	if(pAlumno==NULL) return false;
    int leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
	fclose(pAlumno);

	/*cout<<"ADENTRO DE LA FUNCION "<<endl;
	reg.Mostrar();
	cout<<endl;*/
	return leyo;


}

bool leerRegistroAlumno2(){
    Alumno reg;
	FILE *pAlumno;
	pAlumno=fopen("alumnos.dat","rb" );//si no puede hacer la apertura fopen devuelve NULL
	if(pAlumno==NULL) return false;
	///primera lectura
    /*int leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
	reg.Mostrar();
	cout<<"VALOR DE leyo "<<leyo;
	cout<<endl;
	system("pause");
	///segunda lectura
    leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
	reg.Mostrar();
	cout<<"VALOR DE leyo "<<leyo;
	cout<<endl;
	system("pause");
	///tercera lectura
    leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
	reg.Mostrar();
	cout<<"VALOR DE leyo "<<leyo;
	cout<<endl; */

	while(fread(&reg,sizeof(Alumno),1,pAlumno)==1){
        reg.Mostrar();
	}
    system("pause");
	fclose(pAlumno);
	return true;


}

int main(){
    Alumno reg;
    //reg.Cargar();
    //grabarRegistroAlumno(reg);
    //leerRegistroAlumno(reg);
    //reg.Mostrar();
	leerRegistroAlumno2();
	cout<<endl;
	system("pause");
	return 0;
}
