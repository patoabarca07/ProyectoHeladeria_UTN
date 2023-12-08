#include "Empleado.h"
#include <string.h>
#include <iostream>
#include "Persona.h"

using namespace libxl;

Empleado::Empleado() {
    strcpy(_codEmpleado,"00000");
}
char* Empleado::getCodEmpleado() {
    return _codEmpleado;
}
void Empleado::setCodEmpleado(char *c) {

    strcpy(_codEmpleado,c);
}

void Empleado::Cargar() {

    Persona::CargarPersona();
    char ce[6];
    std::cout<<"Ingrese Codigo de Empleado: ";
    std::cin.ignore();
    std::cin.getline(ce,6);
    setCodEmpleado(ce);


}

int Empleado::Modificar(char *codigo) {
    Empleado obj;
    char telefono[15];
    int g;
    std::cout<<"Ingrese nuevo telefono: ";
    //std::cin.ignore();
    std::cin.getline(telefono,15);

    FILE *p;

    p=fopen("Empleados.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Empleado),1,p)==1) {
        if(strcmp(obj.getCodEmpleado(),codigo)==0) {
            obj.setTelefono(telefono);
            fseek(p,ftell(p)-sizeof(Empleado),SEEK_SET);
            g=fwrite(&obj,sizeof(Empleado), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}

bool Empleado::GrabarAlta(Empleado obj) {

    FILE *p;
    bool g;
    p=fopen("Empleados.dat","ab");
    if(p==NULL) {
        return g;
    }
    g=fwrite(&obj,sizeof(Empleado),1,p);

    fclose(p);
    return g;

}

int Empleado::DardeBaja(char *codigo) {
    Empleado obj;
    int g;

    FILE *p;

    p=fopen("Empleados.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Empleado),1,p)==1) {
        if(strcmp(obj.getCodEmpleado(),codigo)==0) {
            obj.setEstado(false);
            fseek(p,ftell(p)-sizeof(Empleado),SEEK_SET);
            g=fwrite(&obj,sizeof(Empleado), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}
void Empleado::Mostrar() {

    Persona::MostrarPersona();

    std::cout<<"Codigo de empleado: "<<getCodEmpleado()<<std::endl;

    std::cout<<"*************************"<<std::endl;

}

void Empleado:: Listar() {
    Empleado obj;

    FILE *p;

    p=fopen("Empleados.dat","rb");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Empleado),1,p)==1) {

        obj.Mostrar();
    }

    fclose(p);

}



int Empleado::obtenerCantidadRegistros() {

    Empleado obj;
    int cont=0;

    FILE *p;

    p=fopen("Empleados.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Empleado),1,p)==1) {
        cont++;
    }
    fclose(p);
    return cont;
}

void Empleado::leerRegistrosEmpleados(Empleado *vectorEmpleados) {

    Empleado obj;
    int i = 0;


    FILE *p;
    p = fopen("Empleados.dat","rb");

    if(p == NULL) {
        exit(1);
    }
    while(fread(&obj, sizeof(Empleado), 1, p)==1) {
        vectorEmpleados[i] = obj;
        i++;
    }
    fclose(p);
}

void Empleado::ordenarPorApellido(Empleado *vectorEmpleados,int tam) {
    int i, j;
    Empleado aux;

    for(i = 0; i < tam; i++) {
        for(j = 1; j < tam; j++) {

            if(strcmp(vectorEmpleados[j].getApellido(), vectorEmpleados[j-1].getApellido()) < 0) {
                aux = vectorEmpleados[j-1];
                vectorEmpleados[j-1] = vectorEmpleados[j];
                vectorEmpleados[j] = aux;
            }
        }
    }

}
void Empleado::listarOrdenado(Empleado *vectorEmpleados,int tam) {

    for(int i = 0; i < tam; i++) {
        vectorEmpleados[i].Mostrar();
        std::cout << std::endl;
    }


}



void Empleado::ListarPorApellido() {

    int cantidadRegistros=obtenerCantidadRegistros();


    Empleado *vectorEmpleados = new Empleado[cantidadRegistros];


    if(vectorEmpleados == NULL) {
        exit(1);
    }
    leerRegistrosEmpleados(vectorEmpleados);


    ordenarPorApellido(vectorEmpleados,cantidadRegistros);


    listarOrdenado(vectorEmpleados,cantidadRegistros);


    delete vectorEmpleados;

}


void Empleado::realizarBackUp() {
    Empleado empleado;
    FILE *pOrigen, *pDestino;

    pOrigen=fopen("Empleados.dat","rb");
    if(pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Empleados.bak","ab+");
    if(pDestino==NULL) {
        return;
    }

    while(fread(&empleado,sizeof(Empleado),1,pOrigen)==1) {
        fwrite(&empleado,sizeof(Empleado),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);

}
void Empleado::RestaurarArchivoEmpleado() {
    Empleado empleado;

    FILE *pOrigen, *pDestino;
    pOrigen=fopen("Empleados.bak","rb");
    if (pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Empleados.dat","wb");
    if(pDestino==NULL) {
        return;
    }

    while (fread(&empleado,sizeof(Empleado),1,pOrigen)==1) {
        fwrite(&empleado,sizeof(Empleado),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);

}


void Empleado::CargarExcelEmpleados() {

    Book* libro = xlCreateBook(); //CREA UN OBJ LIBRO

    if (libro) { //VERIFICA SI SE CREO EL LIBRO
        // CREA UNA HOJA
        Sheet* hojaEmpleados = libro->addSheet("Empleados");

        Empleado obj;
        int cont=obj.obtenerCantidadRegistros();


        FILE *pArchivo;
        pArchivo=fopen("Empleados.dat","rb");

        if(pArchivo==NULL) {
            std:: cout << "Error al abrir el archivo" << std::endl;
            system("pause");
            exit(1);
        }

        hojaEmpleados->setCol(0, 0, 2);
        hojaEmpleados->setCol(1, 1, 12);
        hojaEmpleados->setCol(2, 2, 25);
        hojaEmpleados->setCol(3, 3, 25);
        hojaEmpleados->setCol(4, 4, 20);
        hojaEmpleados->setCol(5, 5, 20);
        hojaEmpleados->setCol(6, 6, 20);
        hojaEmpleados->setCol(7, 7, 20);
        hojaEmpleados->setCol(8, 8, 15);
        hojaEmpleados->setCol(9, 9, 25);


        Font* fuente;
        fuente=libro->addFont();
        fuente->setName("Times New Roman");
        fuente->setSize(14);
        fuente->setBold(true);

        Format* formato;
        formato=libro->addFormat();
        formato->setFont(fuente);
        formato->setFillPattern(FILLPATTERN_SOLID);
        formato->setPatternForegroundColor(COLOR_GRAY25);
        formato->setAlignH(ALIGNH_CENTER);
        formato->setAlignV(ALIGNV_CENTER);
        formato->setBorder(BORDERSTYLE_THIN);

        hojaEmpleados->writeStr(1, 1, "DNI",formato);
        hojaEmpleados->writeStr(1, 2, "NOMBRE",formato);
        hojaEmpleados->writeStr(1, 3, "APELIIDO",formato);
        hojaEmpleados->writeStr(1, 4, "DOMICILIO",formato);
        hojaEmpleados->writeStr(1, 5, "TELEFONO",formato);
        hojaEmpleados->writeStr(1, 6, "MAIL",formato);
        hojaEmpleados->writeStr(1, 7, "FECHA DE NAC",formato);
        hojaEmpleados->writeStr(1, 8, "COD EMPLEADO",formato);
        hojaEmpleados->writeStr(1, 9, "ESTADO",formato);

        //FORMATO DE LOS DATOS
        Font* fuente2 = libro->addFont();
        fuente2->setName("Arial");
        fuente2->setSize(12);

        Format* formato2 = libro->addFormat();
        formato2->setFont(fuente2);
        formato2->setBorder(BORDERSTYLE_THIN);
        formato2->setFillPattern(FILLPATTERN_SOLID);
        formato2->setPatternForegroundColor(COLOR_AQUA);
        formato2->setNumFormat(NUMFORMAT_NUMBER_SEP_NEGBRA);

        int y=2;

        for (int i=0; i<cont; i++) {

            while(fread(&obj,sizeof(Empleado),1,pArchivo)==1) {

                hojaEmpleados->writeStr(y, 1, obj.getDni(),formato2);
                hojaEmpleados->writeStr(y, 2, obj.getApellido(),formato2);
                hojaEmpleados->writeStr(y, 3,obj.getNombre(),formato2);
                hojaEmpleados->writeStr(y, 4,obj.getDomicilio(),formato2);
                hojaEmpleados->writeStr(y, 5,obj.getTelefono(),formato2);
                hojaEmpleados->writeStr(y, 6,obj.getEmail(),formato2);
                hojaEmpleados->writeStr(y, 7, obj.getFechadeNac().toString().c_str(), formato2);
                hojaEmpleados->writeStr(y, 8,obj.getCodEmpleado(),formato2);

                if(obj.getEstado()==1) {

                    hojaEmpleados->writeStr(y, 9,"Activo",formato2);
                } else {
                    hojaEmpleados->writeStr(y, 9,"Inactivo",formato2);
                }



                y++;

            }
        }

        fclose(pArchivo);
    }
    libro->save("Empleados.xls");


    // Libera los recursos asociados al objeto 'libro'
    libro->release();


}
