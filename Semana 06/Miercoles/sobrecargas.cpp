bool Fecha::operator!=(Fecha aux){
   if((dia==aux.dia) && (mes==aux.mes) && (anio==aux.anio)) return false;
   return true;
}

bool Fecha::operator!=(Fecha aux){
   if(dia!=aux.dia) return true;
   if(mes!=aux.mes) return true;
   if(anio!=aux.anio) return true;
   return false;
}	

bool Fecha::operator!=(Fecha aux){
   if(dia!=aux.dia) return true;
   if(mes!=aux.mes) return true;
   if(anio!=aux.anio) return true;
   return false;


bool Fecha::operator!=(Fecha aux)
{
    return !(*this==aux);
} 


bool operator!=(Fecha aux);
bool Fecha::operator!=(Fecha aux){
    if (dia!=aux.dia || mes!=aux.mes || anio!=aux.anio)return true;
    return false;
}

