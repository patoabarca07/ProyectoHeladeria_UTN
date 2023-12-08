#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <ctime>
#include <cstdio>


class Fecha
{
    private:
    int _dia;
    int _mes;
    int _anio;


public:

    Fecha();


    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();


    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    void cargar();
    std::string toString();

protected:



};

#endif // FECHA_H
