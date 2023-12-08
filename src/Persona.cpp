#include "Persona.h"
#include <string.h>


Persona::Persona()
{
   strcpy(_Dni,"0");
   strcpy(_nombre,"Sin nombre");
   strcpy(_apellido,"Sin apellido");
   strcpy(_domicilio,"Sin domicilio");
   strcpy(_telefono,"Sin telefono");
   strcpy(_email,"Sin email");
   _estado=1;


}
    char* Persona::getDni(){
    return _Dni;
    }
    char* Persona::getNombre(){
    return _nombre;
    }
    char* Persona::getApellido(){
    return _apellido;
    }
    char* Persona::getDomicilio(){
    return _domicilio;
    }
    char* Persona::getTelefono(){
    return _telefono;
    }
    char* Persona::getEmail(){
    return _email;
    }
    bool Persona::getEstado(){
    return _estado;
    }
       Fecha Persona::getFechadeNac() {

        return _fechaNac;
    }


    void Persona::setDni(char *d){
    strcpy(_Dni,d);
        }
    void Persona::setNombre(char *n){
    strcpy(_nombre,n);
    }
    void Persona::setApellido(char *a){
    strcpy(_apellido,a);
                              }
    void Persona::setDomicilio(char *m){
    strcpy(_domicilio,m);
    }
    void Persona::setTelefono(char *t){
    strcpy(_telefono,t);
    }
    void Persona::setEmail(char *e){
    strcpy(_email,e);

    }
    void Persona::setEstado(bool e){

    _estado=e;
    }
     void Persona::setFechadeNac(Fecha f) {
        _fechaNac = f;
    }

     void Persona::CargarPersona(){
     char dni[9], nombre[30], apellido[30];
     char domicilio[30], telefono[15], mail[30];

     std::cout<<"Ingrese Nro de DNI: ";

     std::cin.getline(dni,9);
     setDni(dni);

     std::cout<<"Ingrese Nombre: ";
     std::cin.getline(nombre,30);
     setNombre(nombre);

     std::cout<<"Ingrese Apellido: ";
     std::cin.getline(apellido,30);
     setApellido(apellido);

     std::cout<<"Ingrese Domicilio: ";
     std::cin.getline(domicilio,30);
     setDomicilio(domicilio);

     std::cout<<"Ingrese Nro de telefono: ";
     std::cin.getline(telefono,15);
     setTelefono(telefono);

     std::cout<<"Ingrese Email ";
     std::cin.getline(mail,30);
     setEmail(mail);


     std::cout<<"Fecha de nacimiento: "<<std::endl;
    _fechaNac.cargar();

     }
void Persona::MostrarPersona(){

    std::cout<<"**************************"<<std::endl;
    std::cout<<"DNI : "<<getDni()<<std::endl;

    std::cout<<"Nombre: "<<getNombre()<<std::endl;

    std::cout<<"Apellido: "<<getApellido()<<std::endl;

    std::cout<<"Domicilio: "<<getDomicilio()<<std::endl;

    std::cout<<"Telefono: "<<getTelefono()<<std::endl;

    std::cout<<"Email: "<<getEmail()<<std::endl;

    std::cout<<"Estado : "<<getEstado()<<std::endl;





}
