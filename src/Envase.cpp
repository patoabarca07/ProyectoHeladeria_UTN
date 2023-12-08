#include "Envase.h"
#include <string.h>
#include <iostream>

Envase::Envase() {
    strcpy(_codEnvase,"00000");
    _tipo=0;
    _stock=0;
    _estado=1;
}
char* Envase::getCodEnvase() {
    return _codEnvase;
}
int Envase::getTipo() {
    return _tipo;
}
int Envase::getStock() {
    return _stock;
}
bool Envase::getEstado() {
    return _estado;
}

void Envase::setCodEnvase(char *c) {
    strcpy(_codEnvase,c);
}
void Envase::setTipo(int t) {
    _tipo=t;
}
void Envase::setStock(int s) {
    _stock=s;
}

void Envase::setEstado(bool e) {

    _estado=e;
}

void Envase::Cargar() {
    char codigo[6];
    int tipo,stock;
    bool estado;

    std::cout<<"Ingrese Codigo de envase: ";
    std::cin.ignore();
    std::cin.getline(codigo,6);
    setCodEnvase(codigo);


    std::cout<<"Ingrese tipo de envase (1-Cucurucho,2-Kilo): ";
    std::cin>>tipo;
    setTipo(tipo);



    std::cout<<"Ingrese Stock de envases: ";
    std::cin>>stock;
    setStock(stock);

}
bool Envase::GrabarAlta(Envase obj) {

    FILE *p;
    bool g=0;
    p=fopen("Envases.dat","ab");
    if(p==NULL) {
        return g;
    }
    g=fwrite(&obj,sizeof(Envase),1,p);

    fclose(p);
    return g;

}

int Envase::Modificar(char *codigo) {

    Envase obj;
    int stock;
    int g;
    std::cout<<"Ingrese stock a agregar: ";
    std::cin>>stock;

    FILE *p;
    p=fopen("Envases.dat","rb+");
    if(p==NULL) {
        return -1;
    }


    while(fread(&obj,sizeof(Envase),1,p)==1) {
        if(strcmp(obj.getCodEnvase(),codigo)==0) {
            obj.setStock(obj.getStock()+stock);
            fseek(p,ftell(p)-sizeof(Envase),SEEK_SET);
            g=fwrite(&obj,sizeof(Envase), 1,p);
            fclose(p);
            return g;
        }
    }

    fclose(p);
    return -2;

}

int Envase::DardeBaja(char *codigo) {
    Envase obj;
    int g;
    FILE *p;

    p=fopen("Envases.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Envase),1,p)==1) {
        if(strcmp(obj.getCodEnvase(),codigo)==0) {
            obj.setEstado(false);
            fseek(p,ftell(p)-sizeof(Envase),SEEK_SET);
            g=fwrite(&obj,sizeof(Envase), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}

void Envase::ActualizarStockLocal(char *codigo) {
    Envase obj;

    FILE *p;

    p=fopen("Envases.dat","rb+");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Envase),1,p)==1) {
        if(strcmp(obj.getCodEnvase(),codigo)==0) {
            obj.setStock(obj.getStock() - 1);
            fseek(p,ftell(p)-sizeof(Envase),SEEK_SET);
            fwrite(&obj,sizeof(Envase), 1,p);
            fclose(p);

        }
    }
}
void Envase:: Mostrar() {
    std::cout<<"Codigo de Envase: "<<getCodEnvase()<<std::endl;

    std::cout<<"Tipo de Envase: "<<getTipo()<<std::endl;

    std::cout<<"Stock del Envase: "<<getStock()<<std::endl;

    std::cout<<"Estado del Envase: "<<getEstado()<<std::endl;
    std::cout<<"*************************"<<std::endl;

}


void Envase::Listar() {
    Envase obj;

    FILE *p;

    p=fopen("Envases.dat","rb");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Envase),1,p)==1) {

        obj.Mostrar();
    }

    fclose(p);
}
