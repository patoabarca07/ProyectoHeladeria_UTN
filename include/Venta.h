#ifndef VENTA_H
#define VENTA_H
#include "Helado.h"
#include "Envase.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Fecha.h"
#include <iostream>
#include <libxl.h>



class Venta
{
    public:
        Venta();
        Fecha getFecha();
        Helado getHelado1();
        Helado getHelado2();
        Helado getHelado3();
        Cliente getcliente();
        Empleado getEmpleado();
        Envase getEnvase();
        int getCantBochas();
        float getEnvio();
        float getTotal();

        void setFecha(Fecha);
        void setHelado1(Helado);
        void setHelado2(Helado);
        void setHelado3(Helado);
        void setCliente(Cliente);
        void setEmpleado(Empleado);
        void setEnvase(Envase);
        void setCantBochas(int);
        void setEnvio(float);
        void setTotal(float);

        void CalcularVentaLocal();
        void CalcularVentaDomicilio();
        bool Grabar(Venta);
        void MostrarFactura();
        int ContarVentasPorCliente(char *);
        void ordenarPorApellido(char*,int);
        int obtenerCantidadRegistros();
        void ObtenerRecaudacionMensual();
        void ObtenerRecaudacionAnual();

        void ObtenerRecaudacionCliente();
        void ObtenerCantidadBochas();
        void ObtenerRecaudacionLocal();
        void ObtenerRecaudacionDomicilio();
        void ObtenerRecaudacionMesPorMes();
        void MostrarRecaudacionMesPorMes(float*);

        void realizarBackUp();
        void RestaurarArchivoVenta();
        void CargarExcelVentas();



    protected:

    private:
    Fecha _fecha;
    Helado _helado1;
    Helado _helado2;
    Helado _helado3;
    Cliente _cliente;
    Empleado _empleado;
    Envase _envase;
    int _cantBochas;
    float _envio;
    float _total;


};

#endif // VENTA_H
