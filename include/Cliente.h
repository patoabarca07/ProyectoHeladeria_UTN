#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <cstdio>
#include <libxl.h>



class Cliente : public Persona
{
    public:
        Cliente();

    char* getGustoPreferido();
    void  setGustoPreferido(char*);

    void Cargar();
    bool GrabarAlta(Cliente);
    int DardeBaja(char*);
    int Modificar(char*);

    Cliente BuscarCliente(char*);
    void BuscarClienteporGusto(char*);
    void Mostrar();
    void Listar();
    void ListarPorApellido();
    int obtenerCantidadRegistros();
    void leerRegistrosClientes(Cliente*);
    void ordenarPorApellido(Cliente*,int);
    void listarOrdenado(Cliente*,int);

    void realizarBackUp();
    void RestaurarArchivoCliente();
    void CargarExcelClientes();


    protected:

    private:
    char _gustoPreferido[20];

};

#endif // CLIENTE_H
