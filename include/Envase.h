#ifndef ENVASE_H
#define ENVASE_H
#include <cstdio>


class Envase
{
    public:
        Envase();

    char* getCodEnvase();
    int getTipo();
    int getStock();
    bool getEstado();

    void setCodEnvase(char*);
    void setTipo(int);
    void setStock(int);
    void setEstado(bool);

    void Cargar();
    bool GrabarAlta(Envase);
    int Modificar(char *);
    int DardeBaja(char*);

    void ActualizarStockLocal(char*);
    void Mostrar();
    void Listar();



    protected:

    private:
    char _codEnvase[6];
    int _tipo;
    int _stock;
    bool _estado;



};

#endif // ENVASE_H
