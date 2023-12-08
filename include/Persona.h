#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
#include <cstdio>


class Persona
{
    public:
        Persona();


    char* getDni();
    char* getNombre();
    char* getApellido();
    char* getDomicilio();
    char* getTelefono();
    char* getEmail();
    bool getEstado();
    Fecha getFechadeNac();

    void setDni(char*);
    void setNombre(char*);
    void setApellido(char*);
    void setDomicilio(char*);
    void setTelefono(char*);
    void setEmail(char*);
    void setEstado(bool);
    void setFechadeNac(Fecha);


    void CargarPersona();
    void MostrarPersona();



    protected:

    private:
    char _Dni[9];
    char _nombre[30];
    char _apellido[30];
    char _domicilio[30];
    char _telefono[15];
    char _email[30];
    Fecha _fechaNac;
    bool _estado;

};

#endif // PERSONA_H
