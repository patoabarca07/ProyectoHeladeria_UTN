#include "Fecha.h"


// CONSTRUCTOR POR DEFECTO FECHA ACTUAL
Fecha::Fecha()
{
    _dia = 1;
    _mes = 1;
    _anio = 1900;

    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    _anio=tmPtr->tm_year+1900;
    _mes=tmPtr->tm_mon+1;
    _dia=tmPtr->tm_mday;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;

}


int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

/// SETTERS
void Fecha::setDia(int dia)
{
    _dia = dia;
}
void Fecha::setMes(int mes)
{
    _mes = mes;
}
void Fecha::setAnio(int anio)
{
    _anio =anio;
}
void Fecha::cargar() {

        int d,m,a;
        std::cout<<"Ingrese dia: ";
        std::cin>>d;
        setDia(d);
        std::cout<<"Ingrese mes: ";
        std::cin>>m;
        setMes(m);
        std::cout<<"Ingrese anio: ";
        std::cin>>a;
        setAnio(a);
    }
/// OTROS METODOS
    std::string Fecha::toString()
{
    return std::to_string(_dia) + "/" + std::to_string(_mes)+ "/" + std::to_string(_anio);
}
