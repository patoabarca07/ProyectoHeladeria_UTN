#include "Helado.h"
#include "string.h"
#include <libxl.h>

using namespace libxl;

Helado::Helado() {
    strcpy(_codHelado,"0");
    strcpy(_gusto,"Sin gusto");
    _tipo=0;
    _precio=0;
    _stock=0;
    _estado=1;
}

char* Helado::getCodHelado() {

    return _codHelado;
}
char* Helado::getGusto() {

    return _gusto;
}
int Helado::getTipo() {
    return _tipo;
}
float Helado::getPrecio() {
    return _precio;
}
int Helado::getStock() {
    return _stock;

}
bool Helado::getEstado() {
    return _estado;
}


void Helado::setCodHelado(char*c) {
    strcpy(_codHelado,c);
}
void Helado::setGusto(char*g) {
    strcpy(_gusto,g);
}
void Helado::setTipo(int t) {
    _tipo=t;
}
void Helado::setPrecio(float p) {

    _precio=p;
}
void Helado::setStock(int s) {
    _stock=s;
}
void Helado::setEstado(bool e) {
    _estado=e;

}

void Helado::Cargar() {
    char codigo[6], gusto[30];
    int tipo, stock;
    float precio;


    std::cout<<"Ingrese Codigo de helado: ";
    std::cin.ignore();
    std::cin.getline(codigo,6);
    setCodHelado(codigo);

    std::cout<<"Ingrese gusto de helado: ";
    std::cin.getline(gusto,30);
    setGusto(gusto);

    std::cout<<"Ingrese tipo de helado (1-agua,2-crema,3-vegano): ";
    std::cin>>tipo;
    setTipo(tipo);

    std::cout<<"Ingrese precio del helado: ";
    std::cin>>precio;
    setPrecio(precio);

    std::cout<<"Ingrese Stock del helado: ";
    std::cin>>stock;
    setStock(stock);

    }



bool Helado::GrabarAlta(Helado obj) {

    FILE *p;
    bool g=0;
    p=fopen("Helados.dat","ab");
    if(p==NULL) {
        return g;
    }
    g=fwrite(&obj,sizeof(Helado),1,p);

    fclose(p);
    return g;
}

int Helado::Modificar(char *codigo) {
    Helado obj;
    int opcion;

    std::cout<<"Ingrese 1-Modificar precio o 2-Ingresar stock"<<std::endl;
    std::cin>>opcion;

   FILE *p;
    p=fopen("Helados.dat","rb+");
    if(p==NULL) {
        return -1;
    }

    switch(opcion){

    case 1:
        {
            float precio;
            int g;
            std::cout<<"Ingrese nuevo precio: ";
            std::cin>>precio;


            while(fread(&obj,sizeof(Helado),1,p)==1) {
                if(strcmp(obj.getCodHelado(),codigo)==0) {
                    obj.setPrecio(precio);
                    fseek(p,ftell(p)-sizeof(Helado),SEEK_SET);
                    g=fwrite(&obj,sizeof(Helado), 1,p);
                    fclose(p);
                    return g;
                }
            }
                break;}
            case 2:{
            int stock;
            int g;
            std::cout<<"Ingrese stock a agregar: ";
            std::cin>>stock;


            while(fread(&obj,sizeof(Helado),1,p)==1) {
                if(strcmp(obj.getCodHelado(),codigo)==0) {
                    obj.setStock(obj.getStock()+stock);
                    fseek(p,ftell(p)-sizeof(Helado),SEEK_SET);
                    g=fwrite(&obj,sizeof(Helado), 1,p);
                    fclose(p);
                    return g;
                }
            }
                break; }
    }

    fclose(p);
    return -2;

}

int Helado::DardeBaja(char *codigo) {
    Helado obj;
    int g;
    FILE *p;

    p=fopen("Helados.dat","rb+");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getCodHelado(),codigo)==0) {
            obj.setEstado(false);
            fseek(p,ftell(p)-sizeof(Helado),SEEK_SET);
            g=fwrite(&obj,sizeof(Helado), 1,p);
            fclose(p);
            return g;
        }
    }
    fclose(p);
    return -2;

}


float Helado::BuscarPrecio(char *codigo) {
    Helado obj;
    float precio;


    FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getCodHelado(),codigo)==0) {

            precio=obj.getPrecio();
            fclose(p);
            return precio;
        }
    }
    fclose(p);
    return -2;


}
void Helado::ActualizarStockLocal(char*codigo, int stock) {

Helado obj;

    FILE *p;

    p=fopen("Helados.dat","rb+");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getCodHelado(),codigo)==0) {

            obj.setStock(obj.getStock() - stock);
            fseek(p,ftell(p)-sizeof(Helado),SEEK_SET);
            fwrite(&obj,sizeof(Helado), 1,p);
            fclose(p);

        }
    }
}

void Helado:: Mostrar(){
    std::cout<<"*************************"<<std::endl;

    std::cout<<"Codigo de helado: "<<getCodHelado()<<std::endl;

    std::cout<<"Gusto de helado: "<<getGusto()<<std::endl;

    std::cout<<"Tipo de helado: "<<getTipo()<<std::endl;

    std::cout<<"Precio del helado: "<<getPrecio()<<std::endl;

    std::cout<<"Stock del helado: "<<getStock()<<std::endl;

    std::cout<<"Estado del helado : "<<getEstado()<<std::endl;
    std::cout<<"*************************"<<std::endl;

 }


void Helado::Listar(){
Helado obj;

    FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        return ;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1){

        obj.Mostrar();
    }

    fclose(p);
}

bool Helado::BuscarCodigo(char *codigo){

    Helado obj;

    FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        return false;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getCodHelado(),codigo)==0) {


            fclose(p);
            return true;
        }
    }
    fclose(p);
    std::cout<<"Codigo inexistente"<<std::endl;
    return false;


}

bool Helado::BuscarGusto(char *gusto){

Helado obj;

    FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        return false;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getGusto(),gusto)==0) {

            obj.Mostrar();
            fclose(p);
            return true;

        }
    }
    fclose(p);
    return false;

}

int Helado::MostrarStock(char *codigo){

Helado obj;
int s;

    FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        return -1;
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        if(strcmp(obj.getCodHelado(),codigo)==0) {
            obj.setStock(obj.getStock());
            s=obj.getStock();
            fclose(p);
            return s;

        }
    }
    fclose(p);
    return -2;

}

//MENU REPORTES -- LISTADOS

int Helado::obtenerCantidadRegistros(){

Helado obj;
int cont=0;

FILE *p;

    p=fopen("Helados.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Helado),1,p)==1) {
        cont++;
    }
    fclose(p);
    return cont;
}


void Helado::leerRegistrosHelados(Helado *vectorHelados) {
    Helado obj;
    int i = 0;


    FILE *p;
    p = fopen("Helados.dat","rb");

    if(p == NULL) {
        exit(1);
    }
    while(fread(&obj, sizeof(Helado), 1, p)==1) {
        vectorHelados[i] = obj;
        i++;
    }
    fclose(p);

}
    void Helado::ordenarPorTipo(Helado *vectorHelados, int tam){
    int i, j;
   Helado aux;

    for(i = 0; i < tam; i++)
    {
        for(j = 1; j < tam; j++)
        {

            if(vectorHelados[j].getTipo()<vectorHelados[j-1].getTipo())
            {
                aux = vectorHelados[j-1];
                vectorHelados[j-1] = vectorHelados[j];
                vectorHelados[j] = aux;
            }
        }
    }


    }
    void Helado::listarOrdenado(Helado *vectorHelados, int tam){


 for(int i = 0; i < tam; i++)
    {
        vectorHelados[i].Mostrar();
        std::cout << std::endl;
    }


    }


void Helado::ListarPorTipo()
{

    int cantidadRegistros = obtenerCantidadRegistros();


   Helado* vectorHelados = new Helado[cantidadRegistros];


    if(vectorHelados == NULL)
    {
        exit(1);
    }


    leerRegistrosHelados(vectorHelados);


    ordenarPorTipo(vectorHelados,cantidadRegistros);


    listarOrdenado(vectorHelados,cantidadRegistros);


    delete vectorHelados;
}

    void Helado::ordenarPorStock(Helado *vectorHelados, int tam){

   int i, j;
   Helado aux;

    for(i = 0; i < tam; i++)
    {
        for(j = 1; j < tam; j++)
        {

            if(vectorHelados[j].getStock()>vectorHelados[j-1].getStock())
            {
                aux = vectorHelados[j-1];
                vectorHelados[j-1] = vectorHelados[j];
                vectorHelados[j] = aux;
            }
        }
    }




    }
    void Helado::ListarPorStock(){

     int cantidadRegistros = obtenerCantidadRegistros();


   Helado* vectorHelados = new Helado[cantidadRegistros];


    if(vectorHelados == NULL)
    {
        exit(1);
    }


    leerRegistrosHelados(vectorHelados);


    ordenarPorStock(vectorHelados,cantidadRegistros);


    listarOrdenado(vectorHelados,cantidadRegistros);


    delete vectorHelados;


    }


//MENU CONFIGURACIONES

void Helado::realizarBackUp()
{
    Helado helado;
    FILE *pOrigen, *pDestino;

    pOrigen=fopen("Helados.dat","rb");
    if(pOrigen==NULL)
    {
        return;
    }

    pDestino=fopen("Helados.bak","ab+");
    if(pDestino==NULL)
    {
        return;
    }

    while(fread(&helado,sizeof(Helado),1,pOrigen)==1)
    {
        fwrite(&helado,sizeof(Helado),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);

}
void Helado::RestaurarArchivoHelados()
{

    Helado helado;

    FILE *pOrigen, *pDestino;
    pOrigen = fopen("Helados.bak","rb");
    if(pOrigen == NULL)
    {
        return;
    }

    pDestino = fopen("Helados.dat","wb");
    if(pDestino == NULL)
    {
        return;
    }

    while(fread(&helado, sizeof(Helado), 1, pOrigen)==1)
    {
        fwrite(&helado, sizeof(Helado), 1, pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);

}

void Helado::CargarExcelHelados() {


    Book* libro = xlCreateBook(); //CREA UN OBJ LIBRO

    if (libro) { //VERIFICA SI SE CREO EL LIBRO
        // CREA UNA HOJA
        Sheet* hojaHelados = libro->addSheet("Helados");

        Helado obj;
        int cont=obj.obtenerCantidadRegistros();


        FILE *pArchivo;
        pArchivo=fopen("Helados.dat","rb");

        if(pArchivo==NULL) {
           std:: cout << "Error al abrir el archivo" << std::endl;
            system("pause");
            exit(1);
        }


        hojaHelados->setCol(0, 0, 2);
        hojaHelados->setCol(1, 1, 10);
        hojaHelados->setCol(2, 2, 20);
        hojaHelados->setCol(3, 3, 10);
        hojaHelados->setCol(4, 4, 15);
        hojaHelados->setCol(5, 5, 10);
        hojaHelados->setCol(6, 6, 10);


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

        hojaHelados->writeStr(1, 1, "CODIGO",formato);
        hojaHelados->writeStr(1, 2, "GUSTO",formato);
        hojaHelados->writeStr(1, 3, "TIPO",formato);
        hojaHelados->writeStr(1, 4, "PRECIO",formato);
        hojaHelados->writeStr(1, 5, "STOCK",formato);
        hojaHelados->writeStr(1, 6, "ESTADO",formato);

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

    for (int i=0; i<cont; i++)
    {

        while(fread(&obj,sizeof(Helado),1,pArchivo)==1)
        {

            hojaHelados->writeStr(y, 1, obj.getCodHelado(),formato2);
            hojaHelados->writeStr(y, 2, obj.getGusto(),formato2);
            hojaHelados->writeNum(y, 3,obj.getTipo(),formato2);
            hojaHelados->writeNum(y, 4,obj.getPrecio(),formato2);
            hojaHelados->writeNum(y, 5,obj.getStock(),formato2);

            if(obj.getEstado()==1){

             hojaHelados->writeStr(y, 6,"Activo" ,formato2);
            }
            else{
                hojaHelados->writeStr(y, 6,"Inactivo" ,formato2);
            }



            y++;

        }
    }

    fclose(pArchivo);
    }
     libro->save("Helados.xls");


        // Libera los recursos asociados al objeto 'libro'
    libro->release();

}

