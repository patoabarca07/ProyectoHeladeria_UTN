#include "Cliente.h"
#include <string.h>
#include <iomanip>

using namespace libxl;

Cliente::Cliente() {
    strcpy(_gustoPreferido,"Sin gusto preferido");
}

char* Cliente::getGustoPreferido() {
    return _gustoPreferido;
}

void  Cliente::setGustoPreferido(char *g) {
    strcpy(_gustoPreferido,g);
}

void Cliente::Cargar() {


    Persona::CargarPersona();
    char gp[20];
    std::cout<<"Ingrese gusto preferido: ";
    std::cin.ignore();
    std::cin.getline(gp,20);
    setGustoPreferido(gp);



}


bool Cliente::GrabarAlta(Cliente obj) {

    FILE *p;
    bool g=0;
    p=fopen("Clientes.dat","ab");
    if(p==NULL) {
        return g;
    }
    g=fwrite(&obj,sizeof(Cliente),1,p);

    fclose(p);
    return g;

}
int Cliente::Modificar(char *dni) {
    Cliente obj;
    char domicilio[30];
    int g;
    std::cout<<"Ingrese nuevo domicilio: ";
    //std::cin.ignore();
    std::cin.getline(domicilio,30);

    FILE *p;

    p=fopen("Clientes.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {

        if(strcmp(obj.getDni(),dni)==0) {
            obj.setDomicilio(domicilio);
            fseek(p,ftell(p)-sizeof(Cliente),SEEK_SET);
            g=fwrite(&obj,sizeof(Cliente), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}

int Cliente::DardeBaja(char *dni) {
    Cliente obj;
    int g;
    FILE *p;

    p=fopen("Clientes.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {
        if(strcmp(obj.getDni(),dni)==0) {
            obj.setEstado(false);
            fseek(p,ftell(p)-sizeof(Cliente),SEEK_SET);
            g=fwrite(&obj,sizeof(Cliente), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}

Cliente Cliente::BuscarCliente(char*dni) {
    Cliente obj;
    Cliente cliente;
    cliente.setDni("0");
    FILE *p;

    p=fopen("Clientes.dat","rb");
    if(p==NULL) {
        return cliente;
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {
        if(strcmp(obj.getDni(),dni)==0) {
            cliente.setDni(dni);
            cliente.setNombre(obj.getNombre());
            cliente.setApellido(obj.getApellido());
            cliente.setDomicilio(obj.getDomicilio());
            cliente.setTelefono(obj.getTelefono());
            cliente.setEmail(obj.getEmail());
            cliente.setEstado(obj.getEstado());
            cliente.setFechadeNac(obj.getFechadeNac());
            cliente.setGustoPreferido(obj.getGustoPreferido());
            fclose(p);
            return cliente;
        }
    }
    fclose(p);
    return cliente;

}
void Cliente::Mostrar() {

    Persona::MostrarPersona();

    std::cout<<"Gusto Preferido: "<<getGustoPreferido()<<std::endl;

    std::cout<<"***************************"<<std::endl;

}

void Cliente:: Listar() {
    Cliente obj;

    FILE *p;

    p=fopen("Clientes.dat","rb");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {

        obj.Mostrar();
    }

    fclose(p);

}
void Cliente::BuscarClienteporGusto(char *gusto) {
    Cliente obj;
    int cont=0;

    FILE *p;

    p=fopen("Clientes.dat","rb");
    if(p==NULL) {
        return;
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {
        if(strcmp(obj.getGustoPreferido(),gusto)==0) {
            obj.Mostrar();
            cont++;
        }
    }
    fclose(p);
    if(cont==0) {

        std::cout<<"No hay clientes con ese gusto preferido"<<std::endl;
    }

}
int Cliente::obtenerCantidadRegistros() {

    Cliente obj;
    int cont=0;

    FILE *p;

    p=fopen("Clientes.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Cliente),1,p)==1) {
        cont++;
    }
    fclose(p);
    return cont;
}
void Cliente::leerRegistrosClientes(Cliente *vectorClientes) {

    Cliente obj;
    int i = 0;


    FILE *p;
    p = fopen("Clientes.dat","rb");

    if(p == NULL) {
        exit(1);
    }
    while(fread(&obj, sizeof(Cliente), 1, p)==1) {
        vectorClientes[i] = obj;
        i++;
    }
    fclose(p);
}

void Cliente::ordenarPorApellido(Cliente *vectorClientes,int tam) {
    int i, j;
    Cliente aux;

    for(i = 0; i < tam; i++) {
        for(j = 1; j < tam; j++) {

            if(strcmp(vectorClientes[j].getApellido(), vectorClientes[j-1].getApellido()) < 0) {
                aux = vectorClientes[j-1];
                vectorClientes[j-1] = vectorClientes[j];
                vectorClientes[j] = aux;
            }
        }
    }

}
void Cliente::listarOrdenado(Cliente *vectorClientes,int tam) {

    for(int i = 0; i < tam; i++) {
        vectorClientes[i].Mostrar();
        std::cout << std::endl;
    }


}



void Cliente::ListarPorApellido() {

    int cantidadRegistros=obtenerCantidadRegistros();


    Cliente *vectorClientes = new Cliente[cantidadRegistros];


    if(vectorClientes == NULL) {
        exit(1);
    }
    leerRegistrosClientes(vectorClientes);


    ordenarPorApellido(vectorClientes,cantidadRegistros);


    listarOrdenado(vectorClientes,cantidadRegistros);


    delete vectorClientes;

}





//MENU CONFIGURACIONES

void Cliente::realizarBackUp() {
    Cliente cliente;
    FILE *pOrigen, *pDestino;

    pOrigen=fopen("Clientes.dat","rb");
    if(pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Clientes.bak","ab+");
    if(pDestino==NULL) {
        return;
    }

    while(fread(&cliente,sizeof(Cliente),1,pOrigen)==1) {
        fwrite(&cliente,sizeof(Cliente),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);


}
void Cliente::RestaurarArchivoCliente() {

    Cliente cliente;
    FILE *pOrigen, *pDestino;
    pOrigen=fopen("Clientes.bak", "rb");
    if(pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Clientes.dat", "wb");
    if(pDestino==NULL) {
        return;
    }

    while(fread(&cliente,sizeof(Cliente),1,pOrigen)==1) {
        fwrite(&cliente,sizeof(Cliente),1,pDestino);
    }
    fclose(pOrigen);
    fclose(pDestino);

}


void Cliente::CargarExcelClientes() {

    Book* libro = xlCreateBook(); //CREA UN OBJ LIBRO

    if (libro) { //VERIFICA SI SE CREO EL LIBRO
        // CREA UNA HOJA
        Sheet* hojaClientes = libro->addSheet("Clientes");

        Cliente obj;
        int cont=obj.obtenerCantidadRegistros();


        FILE *pArchivo;
        pArchivo=fopen("Clientes.dat","rb");

        if(pArchivo==NULL) {
            std:: cout << "Error al abrir el archivo" << std::endl;
            system("pause");
            exit(1);
        }


        hojaClientes->setCol(0, 0, 2);
        hojaClientes->setCol(1, 1, 12);
        hojaClientes->setCol(2, 2, 25);
        hojaClientes->setCol(3, 3, 25);
        hojaClientes->setCol(4, 4, 20);
        hojaClientes->setCol(5, 5, 20);
        hojaClientes->setCol(6, 6, 20);
        hojaClientes->setCol(7, 7, 20);
        hojaClientes->setCol(8, 8, 15);
        hojaClientes->setCol(9, 9, 25);


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

        hojaClientes->writeStr(1, 1, "DNI",formato);
        hojaClientes->writeStr(1, 2, "NOMBRE",formato);
        hojaClientes->writeStr(1, 3, "APELIIDO",formato);
        hojaClientes->writeStr(1, 4, "DOMICILIO",formato);
        hojaClientes->writeStr(1, 5, "TELEFONO",formato);
        hojaClientes->writeStr(1, 6, "MAIL",formato);
        hojaClientes->writeStr(1, 7, "FECHA DE NAC",formato);
        hojaClientes->writeStr(1, 8, "GUSTO PREFERIDO",formato);
        hojaClientes->writeStr(1, 9, "ESTADO",formato);

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

            while(fread(&obj,sizeof(Cliente),1,pArchivo)==1) {

                hojaClientes->writeStr(y, 1, obj.getDni(),formato2);
                hojaClientes->writeStr(y, 2, obj.getApellido(),formato2);
                hojaClientes->writeStr(y, 3,obj.getNombre(),formato2);
                hojaClientes->writeStr(y, 4,obj.getDomicilio(),formato2);
                hojaClientes->writeStr(y, 5,obj.getTelefono(),formato2);
                hojaClientes->writeStr(y, 6,obj.getEmail(),formato2);
                hojaClientes->writeStr(y, 7, obj.getFechadeNac().toString().c_str(), formato2);
                hojaClientes->writeStr(y, 8,obj.getGustoPreferido(),formato2);

                if(obj.getEstado()==1) {

                    hojaClientes->writeStr(y, 9,"Activo",formato2);
                } else {
                    hojaClientes->writeStr(y, 9,"Inactivo",formato2);
                }



                y++;

            }
        }

        fclose(pArchivo);
    }
    libro->save("Clientes.xls");


    // Libera los recursos asociados al objeto 'libro'
    libro->release();



}
