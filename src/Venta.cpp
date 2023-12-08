#include "Venta.h"
#include "string.h"
#include <iomanip>

using namespace libxl;

Venta::Venta() {
    _cantBochas=0,
    _envio=0;
    _total=0;
}

Fecha Venta::getFecha() {
    return _fecha;
}
Helado Venta::getHelado1() {
    return _helado1;
}
Helado Venta::getHelado2() {
    return _helado2;
}
Helado Venta::getHelado3() {
    return _helado3;
}
Cliente Venta::getcliente() {
    return _cliente;
}
Empleado Venta::getEmpleado() {
    return _empleado;
}
Envase Venta::getEnvase() {
    return _envase;
}
int Venta::getCantBochas() {
    return _cantBochas;
}
float Venta::getEnvio() {
    return _envio;
}
float Venta::getTotal() {
    return _total;
}


void Venta::setFecha(Fecha f) {
    _fecha=f;
}

void Venta::setHelado1(Helado h) {
    _helado1=h;
}
void Venta::setHelado2(Helado h) {
    _helado2=h;
}
void Venta::setHelado3(Helado h) {
    _helado3=h;
}

void Venta::setCliente(Cliente c) {
    _cliente=c;
}
void Venta::setEmpleado(Empleado e) {

    _empleado=e;
}
void Venta::setEnvase(Envase e) {
    _envase=e;
}
void Venta::setCantBochas(int c) {
    _cantBochas=c;
}
void Venta::setEnvio(float e) {
    _envio=e;
}
void Venta::setTotal(float t) {
    _total=t;
}


//MENU FACTURACION

void Venta::CalcularVentaLocal() {
    int c;
    char codigo[6];
    char codigoEn[6];
    char codigoEmp[6];
    char dni[9];
    float p,t=0;
    bool e;


    //_fecha.cargar();

    Cliente clie;



    std::cout<<"Ingrese codigo de vendedor:  ";
    std::cin.ignore();
    std::cin.getline(codigoEmp,6);
    _empleado.setCodEmpleado(codigoEmp);


    std::cout<<"Ingrese DNI del cliente:  ";
    std::cin.getline(dni,9);
    _cliente.setDni(dni);
    clie=_cliente.BuscarCliente(dni);
    if(strcmp(clie.getDni(),"0")==0) {
        std::cout<<"--------------------------------------------------------"<<std::endl;
        std::cout<<"El DNI no existe en el registro de Clientes. Dar de alta"<<std::endl;
        std::cout<<"--------------------------------------------------------"<<std::endl;
        clie.Cargar();
        bool g=clie.GrabarAlta(clie);
        if(g) {
            std::cout<<"Grabado con con exito.Continue la venta "<<std::endl;
            std::cout<<"----------------------------------------"<<std::endl;
        }

    }
    setCliente(clie);


    std::cout<<"Ingrese Codigo de envase:  ";
    //std::cin.ignore();
    std::cin.getline(codigoEn,6);
    _envase.setCodEnvase(codigoEn);
    setEnvase(_envase);


    std::cout<<"Ingrese cantidad de bochas del cucurucho(1,2 o 3):  ";
    std::cin>>c;
    setCantBochas(c);

    switch(c) {
    case 1:
        std::cin.ignore();
        do {
            std::cout<<"Ingrese Cod helado Gusto 1: ";
            std::cin.getline(codigo,6);
            e=_helado1.BuscarCodigo(codigo);
        } while(e==false);

        _helado1.setCodHelado(codigo);
        p=_helado1.BuscarPrecio(codigo);
        _helado1.ActualizarStockLocal(codigo,1);
        _helado2.setCodHelado("0");
        _helado3.setCodHelado("0");

        setTotal(p);


        break;
    case 2: {
        std::cin.ignore();
        do {
            std::cout<<"Ingrese Cod helado Gusto 1: ";
            std::cin.getline(codigo,6);
            e=_helado1.BuscarCodigo(codigo);
        } while(e==false);

        _helado1.setCodHelado(codigo);
        p=_helado1.BuscarPrecio(codigo);
        _helado1.ActualizarStockLocal(codigo,1);
        t+=p;

        do {
            std::cout<<"Ingrese Cod helado Gusto 2: ";
            std::cin.getline(codigo,6);
            e=_helado2.BuscarCodigo(codigo);
        } while(e==false);


        _helado2.setCodHelado(codigo);
        p=_helado2.BuscarPrecio(codigo);
        _helado2.ActualizarStockLocal(codigo,1);
        _helado3.setCodHelado("0");
        t+=p;
        setTotal(t);
        break;
    }
    case 3: {
        std::cin.ignore();
        do {
            std::cout<<"Ingrese Cod helado Gusto 1: ";

            std::cin.getline(codigo,6);
            e=_helado1.BuscarCodigo(codigo);
        } while(e==false);

        _helado1.setCodHelado(codigo);
        p=_helado1.BuscarPrecio(codigo);
        _helado1.ActualizarStockLocal(codigo,1);
        t+=p;

        do {
            std::cout<<"Ingrese Cod helado Gusto 2: ";
            std::cin.getline(codigo,6);
            e=_helado2.BuscarCodigo(codigo);
        } while(e==false);


        _helado2.setCodHelado(codigo);
        p=_helado2.BuscarPrecio(codigo);
        _helado2.ActualizarStockLocal(codigo,1);

        t+=p;

        do {
            std::cout<<"Ingrese Cod helado Gusto 3: ";
            std::cin.getline(codigo,6);
            e=_helado3.BuscarCodigo(codigo);
        } while(e==false);


        _helado3.setCodHelado(codigo);
        p=_helado3.BuscarPrecio(codigo);
        _helado3.ActualizarStockLocal(codigo,1);
        t+=p;
        setTotal(t);

        break;
    }
    default:

        break;


    }

    _envase.ActualizarStockLocal(codigoEn);
}

void Venta::CalcularVentaDomicilio() {

    int c;
    char codigo[6];
    char codigoEn[6];
    char codigoEmp[6];
    char dni[9];
    float p,t=0;
    float pEnvio;
    bool e;

    //_fecha.cargar();
    Cliente clie;


    std::cout<<"Ingrese codigo de vendedor:  ";
    std::cin.ignore();
    std::cin.getline(codigoEmp,6);
    _empleado.setCodEmpleado(codigoEmp);

    std::cout<<"Ingrese DNI del cliente:  ";
    std::cin.getline(dni,9);
    _cliente.setDni(dni);
    clie=_cliente.BuscarCliente(dni);
    if(strcmp(clie.getDni(),"0")==0) {
        std::cout<<"El DNI no existe en el registro de Clientes. Dar de alta"<<std::endl;
        clie.Cargar();
        bool g=clie.GrabarAlta(clie);
        if(g) {
            std::cout<<"Grabado con con exito.Continue la venta "<<std::endl;
        }
    }
    setCliente(clie);


    std::cout<<"Ingrese Codigo de envase:  ";
    //std::cin.ignore();
    std::cin.getline(codigoEn,6);
    _envase.setCodEnvase(codigoEn);

    std::cout<<"Ingrese Precio de Envio: ";
    std::cin>>pEnvio;
    _envio=pEnvio;
    _cantBochas=12;

    std::cin.ignore();
    do {
        std::cout<<"Ingrese Cod helado Gusto 1: ";
        std::cin.getline(codigo,6);
        e=_helado1.BuscarCodigo(codigo);
    } while(e==false);

    _helado1.setCodHelado(codigo);
    p=_helado1.BuscarPrecio(codigo);
    _helado1.ActualizarStockLocal(codigo,4);
    t+=(p*4);

    do {
        std::cout<<"Ingrese Cod helado Gusto 2: ";
        std::cin.getline(codigo,6);
        e=_helado2.BuscarCodigo(codigo);
    } while(e==false);


    _helado2.setCodHelado(codigo);
    p=_helado2.BuscarPrecio(codigo);
    _helado2.ActualizarStockLocal(codigo,4);

    t+=(p*4);

    do {
        std::cout<<"Ingrese Cod helado Gusto 3: ";
        std::cin.getline(codigo,6);
        e=_helado3.BuscarCodigo(codigo);
    } while(e==false);

    _helado3.setCodHelado(codigo);
    p=_helado3.BuscarPrecio(codigo);
    _helado3.ActualizarStockLocal(codigo,4);
    t+=(p*4);
    t+=pEnvio;
    setTotal(t);
    _envase.ActualizarStockLocal(codigoEn);
}

bool Venta::Grabar(Venta obj) {
    FILE *p;
    bool g=0;
    p=fopen("Ventas.dat","ab");
    if(p==NULL) {
        return g;
    }
    g=fwrite(&obj,sizeof(Venta),1,p);

    fclose(p);
    return g;
}


void Venta::MostrarFactura() {
    std::cout<<"******************************"<<std::endl;
    std::cout<<"***Heladeria El Cucurucho***"<<std::endl;
    std::cout<<"Cuit: 30-0000000-1"<<std::endl;
    std::cout<<"Domicilio: Sojo 2423-Saladillo"<<std::endl;
    std::cout<<"******************************"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Fecha: "<<_fecha.toString()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Nombre Y Apellido Cliente: "<<_cliente.getNombre()<<" "<<_cliente.getApellido()<<std::endl;
    std::cout<<"DNI Cliente: "<<_cliente.getDni()<<std::endl;
    std::cout<<"Domicilio: "<<_cliente.getDomicilio()<<std::endl;
    std::cout<<"******************************"<<std::endl;

    std::cout<<"**********Detalle***********"<<std::endl;

    if(_envio>0) {
        std::cout<<"Cant de Bochas \t Total"<<std::endl;
        std::cout<<getCantBochas()<<" \t\t $ "<<getTotal()-_envio<<std::endl;
        std::cout<<"Precio Envio \t\t $ "<<_envio<<std::endl;
        std::cout<<"........................"<<std::endl;
        std::cout<<"TOTAL \t\t $ "<<getTotal()<<std::endl;

        std::cout<<std::endl;;
    } else {
        std::cout<<"Cant de Bochas \t Total"<<std::endl;
        std::cout<<getCantBochas()<<" \t\t $ "<<getTotal()<<std::endl;
        std::cout<<std::endl;
    }

    std::cout<<"******************************"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Cv: "<<_empleado.getCodEmpleado()<<std::endl;


}


//MENU REPORTES

int Venta::ContarVentasPorCliente(char *dni) {
    Venta obj;
    int cont=0;

    FILE *p;
    bool g=0;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        return -1;
    }

    while(fread(&obj,sizeof(Venta),1,p)==1) {

        if(strcmp(obj._cliente.getDni(),dni)==0) {
            cont++;
        }
    }
     fclose(p);
    return cont;


}
int Venta::obtenerCantidadRegistros() {
    Venta obj;
    int cont=0;

    FILE *p;

    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {
        cont++;
    }
    fclose(p);
    return cont;

}


//MENU INFORMES

void Venta::ObtenerRecaudacionMensual() {

    Venta obj;
    int mes;
    float recaudacion=0;
    std::cout<<"Ingrese el mes:"<<std::endl;
    std::cin>>mes;
    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {

        if(obj.getFecha().getMes()==mes) {

            recaudacion+=obj.getTotal();
        }
    }

    fclose(p);
    if(recaudacion>0) {
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Recaudacion mes: "<<mes<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Total  $ "<<recaudacion<<std::endl;
        std::cout<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
    } else {
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"No hubo ventas ese mes"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
    }
}

void Venta::ObtenerRecaudacionAnual() {

    Venta obj;
    int anio;
    float recaudacion=0;
    std::cout<<"Ingrese el anio:"<<std::endl;
    std::cin>>anio;

    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {

        if(obj.getFecha().getAnio()==anio) {

            recaudacion+=obj.getTotal();
        }
    }

    fclose(p);

    if(recaudacion>0) {
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Recaudacion Anio "<<anio<<std::endl;
        std::cout<<"Total  $ "<<recaudacion<<std::endl;
        std::cout<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
    } else {
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"No hubo recaudacion ese anio"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
    }


}

void Venta::ObtenerRecaudacionCliente() {

    Venta obj;
    float recaudacion=0;
    char dni[9];
    std::cout<<"Ingrese DNI del cliente: ";
    std::cin.ignore();
    std::cin.getline(dni,9);

    FILE *p;
    p = fopen("Ventas.dat","rb");

    if(p == NULL) {
        exit(1);
    }
    while(fread(&obj, sizeof(Venta), 1, p)==1) {
        if(strcmp(obj.getcliente().getDni(),dni)==0) {

            recaudacion+=obj.getTotal();
        }
    }
    fclose(p);
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"La recaudacion del clientes es de $ "<<recaudacion<<std::endl;
    std::cout<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;
}


void Venta::ObtenerCantidadBochas() {

    Venta obj;
    int cantidadBochas=0;

    FILE *p;
    p = fopen("Ventas.dat","rb");

    if(p == NULL) {
        exit(1);
    }
    while(fread(&obj, sizeof(Venta), 1, p)==1) {

        cantidadBochas+=obj.getCantBochas();
    }
    fclose(p);
    std::cout<<"-----------------------------------------------------"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"La cantidad de Bochas de Helado vendidas es de : "<<cantidadBochas<<std::endl;
    std::cout<<std::endl;
    std::cout<<"-----------------------------------------------------"<<std::endl;
}

void Venta::ObtenerRecaudacionLocal() {

    Venta obj;
    float recaudacion;

    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {

        if(obj.getCantBochas()<4) {

            recaudacion+=obj.getTotal();
        }
    }

    system("cls");
    if(recaudacion>0) {
        std::cout<<"-------------------------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Recaudacion por ventas en local: $"<<recaudacion<<std::endl;
        std::cout<<std::endl;
        std::cout<<"-------------------------------------------------"<<std::endl;
        fclose(p);
    } else {
        std::cout<<"--------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"No hubo ventas en local"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"--------------------------"<<std::endl;
    }
}

void Venta::ObtenerRecaudacionDomicilio() {

    Venta obj;
    float recaudacion;

    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {

        if(obj.getCantBochas()==12) {

            recaudacion+=obj.getTotal();
        }
    }

    system("cls");
    if(recaudacion>0) {
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Recaudacion por ventas a domicilio: $"<<recaudacion<<std::endl;
        std::cout<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
        fclose(p);
    } else {
        std::cout<<"-----------------------------------------------------"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"No hubo ventas a domicilio"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"-----------------------------------------------------"<<std::endl;
    }

}
void Venta::ObtenerRecaudacionMesPorMes() {
    Venta obj;
    float vMeses[12]= {};

    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) {
        exit(1);
    }
    while(fread(&obj,sizeof(Venta),1,p)==1) {

        vMeses[obj.getFecha().getMes()-1]+=obj.getTotal();
    }

    MostrarRecaudacionMesPorMes(vMeses);
}

void Venta::MostrarRecaudacionMesPorMes(float *vMeses) {

    std::string nombreMes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    system("cls");

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<std::left<<std::setw(15)<<"Mes"<<std::right<<std::setw(15)<<"Total"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    for(int i=0; i<12; i++) {
    std::cout<<std::left<<std::setw(15)<<nombreMes[i]<<std::right<<std::setw(15)<<vMeses[i]<<std::endl;
    }
}

//MENU CONFIGURACIONES

void Venta::realizarBackUp() {
    Venta venta;
    FILE *pOrigen, *pDestino;

    pOrigen=fopen("Ventas.dat","rb");
    if(pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Ventas.bak","ab+");
    if(pDestino==NULL) {
        return;
    }

    while(fread(&venta,sizeof(Venta),1,pOrigen)==1) {
        fwrite(&venta,sizeof(Venta),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);
    std::cout<<"Reastauracion de archivo realizada!"<<std::endl;

}

void Venta::RestaurarArchivoVenta() {

    Venta venta;


    FILE *pOrigen, *pDestino;
    pOrigen=fopen("Ventas.bak","rb");
    if (pOrigen==NULL) {
        return;
    }

    pDestino=fopen("Ventas.dat", "wb");
    if(pDestino==NULL) {
        return;
    }

    while (fread(&venta,sizeof(Venta),1,pOrigen)==1) {
        fwrite(&venta,sizeof(Venta),1,pDestino);
    }

    fclose(pOrigen);
    fclose(pDestino);
}
void Venta::CargarExcelVentas() {

    Book* libro = xlCreateBook(); //CREA UN OBJ LIBRO

    if (libro) { //VERIFICA SI SE CREO EL LIBRO
        // CREA UNA HOJA
        Sheet* hojaVentas = libro->addSheet("Ventas");

        Venta obj;
        int cont=obj.obtenerCantidadRegistros();


        FILE *pArchivo;
        pArchivo=fopen("Ventas.dat","rb");

        if(pArchivo==NULL) {
            std:: cout << "Error al abrir el archivo" << std::endl;
            system("pause");
            exit(1);
        }


        hojaVentas->setCol(0, 0, 2);
        hojaVentas->setCol(1, 1, 15);
        hojaVentas->setCol(2, 2, 25);
        hojaVentas->setCol(3, 3, 25);
        hojaVentas->setCol(4, 4, 25);
        hojaVentas->setCol(5, 5, 15);
        hojaVentas->setCol(6, 6, 15);
        hojaVentas->setCol(7, 7, 15);
        hojaVentas->setCol(8, 8, 20);
        hojaVentas->setCol(9, 9, 20);


        Font* fuente;
        fuente=libro->addFont();
        fuente->setName("Times New Roman");
        fuente->setSize(13);
        fuente->setBold(true);

        Format* formato;
        formato=libro->addFormat();
        formato->setFont(fuente);
        formato->setFillPattern(FILLPATTERN_SOLID);
        formato->setPatternForegroundColor(COLOR_GRAY25);
        formato->setAlignH(ALIGNH_CENTER);
        formato->setAlignV(ALIGNV_CENTER);
        formato->setBorder(BORDERSTYLE_THIN);

        hojaVentas->writeStr(1, 1, "FECHA",formato);
        hojaVentas->writeStr(1, 2, "GUSTO 1",formato);
        hojaVentas->writeStr(1, 3, "GUSTO 2",formato);
        hojaVentas->writeStr(1, 4, "GUSTO 3",formato);
        hojaVentas->writeStr(1, 5, "DNI CLIENTE",formato);
        hojaVentas->writeStr(1, 6, "COD VENDEDOR",formato);
        hojaVentas->writeStr(1, 7, "CAN BOCHAS",formato);
        hojaVentas->writeStr(1, 8, "PRECIO ENVIO",formato);
        hojaVentas->writeStr(1, 9, "TOTAL",formato);

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

            while(fread(&obj,sizeof(Venta),1,pArchivo)==1) {

                hojaVentas->writeStr(y, 1, obj.getFecha().toString().c_str(),formato2);
                hojaVentas->writeStr(y, 2, obj.getHelado1().getCodHelado(),formato2);
                hojaVentas->writeStr(y, 3, obj.getHelado2().getCodHelado(),formato2);
                hojaVentas->writeStr(y, 4, obj.getHelado3().getCodHelado(),formato2);
                hojaVentas->writeStr(y, 5, obj.getcliente().getDni(),formato2);
                hojaVentas->writeStr(y, 6, obj.getEmpleado().getCodEmpleado(),formato2);
                hojaVentas->writeNum(y, 7, obj.getCantBochas(),formato2);
                hojaVentas->writeNum(y, 8, obj.getEnvio(),formato2);
                hojaVentas->writeNum(y, 9, obj.getTotal(),formato2);

                y++;

            }
        }

        fclose(pArchivo);
    }
    libro->save("Ventas.xls");

    // Libera los recursos asociados al objeto 'libro'
    libro->release();
}
