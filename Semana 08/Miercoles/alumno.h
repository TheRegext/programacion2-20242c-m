
const bool ACTIVOS=true;
const bool TODOS=false;


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
    bool estado; ///propiedad que vamos a utilizar para definir si el registro está o no activo (borrado)
public:
    int getLegajo(){return legajo;}
    void setLegajo(int l){legajo=l;}

    bool getEstado(){return estado;}
    void setEstado(bool e){estado=e;}

    void setFechaNacimiento(Fecha aux){
          fechaNacimiento=aux;
    }

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}

    int getCodigoCarrera(){return codigoCarrera;}
    void Cargar(int leg=0);
    void Mostrar();
};
///Métodos de alumno
void Alumno::Cargar(int leg){
    if(leg==0){
        cout<<"LEGAJO ";
        cin>>legajo;
    }
    else legajo=leg;
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
    estado=true;
}

void Alumno::Mostrar(){
    if(estado==true){
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
}


class ArchivoAlumnos{
private:
    char nombre[50];
    int tamanioRegistro;
public:
    ArchivoAlumnos(const char *n="alumnos.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(Alumno);
    }
    bool grabarRegistro(Alumno reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int escribio=fwrite(&reg,tamanioRegistro,1,pAlumno);
        fclose(pAlumno);
        return escribio;

    }

    bool leerRegistroAlumno(Alumno &reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"rb" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
        fclose(pAlumno);
        return leyo;
    }

    bool listarRegistros(){
        FILE *pAlu;
        Alumno reg;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&reg,tamanioRegistro,1,pAlu)==1){
            reg.Mostrar();
            cout<<endl;
        }

        fclose(pAlu);
        return true;
    }

    int buscarRegistro(int leg, bool queHago){
        FILE *pAlu;
        Alumno reg;
        int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        if(queHago==true){
           while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg &&reg.getEstado()){
                fclose(pAlu);
                return pos;
                }
            pos++;
            }
        fclose(pAlu);
        return -1;
        }
        else{
           while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg){
                fclose(pAlu);
                return pos;
                }
            pos++;
            }
        fclose(pAlu);
        return -1;
        }
    }
    Alumno leerRegistro(int ubicacion){
        FILE *pAlu;
        Alumno reg;
        reg.setLegajo(-1);
        ///int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return reg;
        }
        int cuanto=ubicacion*tamanioRegistro;
        int desde_donde=0;
        fseek(pAlu,cuanto, desde_donde);
        fread(&reg, tamanioRegistro,1, pAlu);
        fclose(pAlu);
        return reg;
    }
    int contarRegistros(){
        FILE *pAlu;
        Alumno reg;

        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -1;
        }
        fseek(pAlu,0, 2);///se ubica el puntero al final del archivo
        int cantByte=ftell(pAlu);///ftell() me dice cuántos bytes hay desde el inicio hasta la posición actual
        fclose(pAlu);
        return cantByte/tamanioRegistro;///son los registros totales. No diferencia si están o no borrados los registros
    }

    bool modificarRegistro(Alumno reg,int pos){
        FILE *pAlu;
        pAlu=fopen(nombre, "rb+");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }
        fseek(pAlu,pos*tamanioRegistro, 0);
        bool escribio=fwrite(&reg, tamanioRegistro,1, pAlu);
        fclose(pAlu);
        return escribio;

    }
};
