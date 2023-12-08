#ifndef HELADO_H
#define HELADO_H
#include "Fecha.h"
#include <cstdio>
#include <libxl.h>



class Helado
{
    public:
        Helado();

    char* getCodHelado();
    char* getGusto();
    int getTipo();
    float getPrecio();
    int getStock();
    bool getEstado();

    void setCodHelado(char*);
    void setGusto(char*);
    void setTipo(int );
    void setPrecio(float );
    void setStock(int );
    void setEstado(bool);

    void Cargar();

    bool GrabarAlta(Helado);
    int Modificar(char*);
    int DardeBaja(char*);

    float BuscarPrecio(char*);
    void ActualizarStockLocal(char*, int);
    void Mostrar();
    void Listar();
    bool BuscarCodigo(char*);
    bool BuscarGusto(char*);
    int MostrarStock(char*);

    int obtenerCantidadRegistros();
    void leerRegistrosHelados(Helado*);
    void ordenarPorTipo(Helado*, int);
    void listarOrdenado(Helado*, int);
    void ListarPorTipo();
    void ordenarPorStock(Helado*, int);
    void ListarPorStock();

    void realizarBackUp();
    void RestaurarArchivoHelados();
    void CargarExcelHelados();



    protected:

    private:

        char _codHelado[10];
        char _gusto[20];
        int _tipo;
        float _precio;
        int _stock;
         bool _estado;

};

#endif // HELADO_H
