#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <cstdio>
#include <libxl.h>


class Empleado:public Persona
{
    public:
        Empleado();
    char* getCodEmpleado();
    void setCodEmpleado(char*);

    void Cargar();
    bool GrabarAlta(Empleado);
    int Modificar(char*);
    int DardeBaja(char*);
    void Mostrar();
    void Listar();
    int obtenerCantidadRegistros();
    void ListarPorApellido();
    void leerRegistrosEmpleados(Empleado*);
    void ordenarPorApellido(Empleado*,int);
    void listarOrdenado(Empleado*,int);

    void realizarBackUp();
    void RestaurarArchivoEmpleado();
    void CargarExcelEmpleados();

    protected:

    private:
        char _codEmpleado[6];

};

#endif // EMPLEADO_H
