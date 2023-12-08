#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "Helado.h"
#include "Envase.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
#include "string.h"

using namespace std;

void menuAltas();
void menuHelados();
void menuEnvases();
void menuClientes();
void menuEmpleados();
void menuFacturacion();
void menuReportes();
void menuConsultas();
void menuListados();
void menuInformes();
void menuConfiguraciones();
void menuBackup();
void menuRestaurar();
void menuExportarExcel();



int MenuPrincipal() {
    int opc;


    while(true) {
        system("cls");
        cout << "***************************************" << endl;
        cout << "-------- MENU PRINCIPAL----------------" << endl;
        cout << "***************************************" << endl;
        cout << "   1 - ALTAS Y MODIFICACIONES" << endl;
        cout << "   2 - FACTURACION" << endl;
        cout << "   3 - REPORTES" << endl;
        cout << "   4 - CONFIGURACIONES" << endl;
        cout << "****************************************" << endl;
        cout << "   0 - SALIR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            menuAltas();
            break;
        case 2:
            menuFacturacion();
            break;
        case 3:
            menuReportes();
            break;
        case 4:
            menuConfiguraciones();
            break;
        case 0:
            cout << endl << endl;
            return 0;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return 0;
            break;
        }
    }
}

void menuAltas() {
    int opc;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU ALTAS y MODIFICIONES -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - HELADOS" << endl;
        cout << "   2 - ENVASES" << endl;
        cout << "   3 - CLIENTES" << endl;
        cout << "   4 - EMPLEADOS" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            menuHelados();
            break;
        case 2:
            menuEnvases();
            break;
        case 3:
            menuClientes();
            break;
        case 4:
            menuEmpleados();
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}
void menuHelados() {
    Helado helado;
    int opc;
    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU HELADOS -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - ALTA" << endl;
        cout << "   2 - MODIFICACION" << endl;
        cout << "   3 - BAJA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1: {
            char codigo[6];
            cout<<"Ingrese Codigo de helado: ";
            cin.ignore();
            cin.getline(codigo,6);
            bool e=helado.BuscarCodigo(codigo);
            if(e==false) {
                cout<<"Cargar: "<<endl;
                helado.Cargar();
                bool g=helado.GrabarAlta(helado);
                if(g) {
                    cout <<"Alta exitosa"<<endl;

                } else {
                    cout<<"Error al abrir el archivo";
                }
            } else {
                cout<<"El codigo de Helado ya existe en el registro"<<endl;
            }

            system("pause");

            break;
        }

        case 2: {
            char codigo[6];
            cout<<"Ingrese Codigo de helado: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=helado.Modificar(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de helado"<<endl;

                } else {
                    cout<<"Modificacion realizada"<<endl;
                }
            }


            break;
        }
        case 3: {
            char codigo[6];
            cout<<"Ingrese Codigo de helado a dar de baja: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=helado.DardeBaja(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de helado"<<endl;

                } else {
                    cout<<"Baja realizada"<<endl;
                }

            }
            cout<<"---------------------------"<<endl;

            break;
            system("pause");
        }
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }

    }
}

void menuEnvases() {
    int opc;
    Envase envase;


    while(true) {

        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU ENVASES -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - ALTA" << endl;
        cout << "   2 - MODIFICACION" << endl;
        cout << "   3 - BAJA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1: {

            envase.Cargar();
            bool g=envase.GrabarAlta(envase);
            if(g) {
                cout <<"Alta exitosa";
            } else {
                cout<<"Error al abrir el archivo";
            }

            break;
        }

        case 2: {
            char codigo[6];
            cout<<"Ingrese Codigo de Envase: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=envase.Modificar(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de envase"<<endl;

                } else {
                    cout<<"Modificacion realizada"<<endl;
                }
            }

            break;
        }

        case 3: {
            char codigo[6];
            cout<<"Ingrese Codigo de Envase a dar de baja: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=envase.DardeBaja(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de envase"<<endl;

                } else {
                    cout<<"Baja realizada"<<endl;
                }
            }



            break;
        }

        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
        system("pause");
    }

}
void menuClientes() {
    Cliente cliente;


    int opc;

    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU CLIENTES -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - ALTA" << endl;
        cout << "   2 - MODIFICACION" << endl;
        cout << "   3 - BAJA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {

        case 1: {
            char dni[9];
            cout<<"Ingrese DNI : ";
            cin.ignore();
            cin.getline(dni,9);
            cliente=cliente.BuscarCliente(dni);
            if(strcmp(cliente.getDni(),"0")==0) {
                cout<<"-----------------------------------------------"<<endl;
                cout<<"El DNI no existe en el registro. Continuar alta"<<endl;
                cout<<"-----------------------------------------------"<<endl;

                cliente.Cargar();
                bool g=cliente.GrabarAlta(cliente);
                if(g) {
                    cout <<"Alta exitosa";
                } else {
                    cout<<"Error al abrir el archivo";
                }
            } else {
                cout<<"------------------------------------"<<endl;
                cout<<"El cliente ya se encuentra registrado"<<endl;
                cout<<"------------------------------------"<<endl;
            }
            system("pause");
            break;
        }

        case 2: {
            char dni[9];
            cout<<"Ingrese DNI del Cliente: ";
            cin.ignore();
            cin.getline(dni,9);
            int m=cliente.Modificar(dni);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el DNI del cliente"<<endl;

                } else {
                    cout<<"Modificacion realizada"<<endl;
                }
            }
            system("pause");
            break;
        }
        case 3: {
            char dni[9];
            cout<<"Ingrese DNI del cliente a dar de baja ";
            cin.ignore();
            cin.getline(dni,9);
            int m=cliente.DardeBaja(dni);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el DNI del cliente"<<endl;

                } else {
                    cout<<"Baja realizada"<<endl;
                }
            }
            system("pause");
            break;

            system("pause");
        }


        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}

void menuEmpleados() {
    Empleado empleado;
    int opc;

    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU EMPLEADOS -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - ALTA" << endl;
        cout << "   2 - MODIFICACION" << endl;
        cout << "   3 - BAJA" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1: {
            std::cin.ignore();
            empleado.Cargar();
            bool g=empleado.GrabarAlta(empleado);
            if(g) {
                cout <<"Alta exitosa";
            } else {
                cout<<"Error al abrir el archivo";
            }
            system("pause");
            break;
        }
        case 2: {
            char codigo[6];
            cout<<"Ingrese Codigo de Empleado: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=empleado.Modificar(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de Empleado"<<endl;

                } else {
                    cout<<"Modificacion realizada"<<endl;
                }
            }
            system("pause");
            break;

        }
        case 3: {
            char codigo[6];
            cout<<"Ingrese Codigo de Empleado a dar de baja: ";
            cin.ignore();
            cin.getline(codigo,6);
            int m=empleado.DardeBaja(codigo);
            if(m==-1) {
                cout<<"Error al abrir el archivo";
            } else {
                if(m==-2) {
                    cout<<"No se encontro el codigo de empleado"<<endl;

                } else {
                    cout<<"Baja realizada"<<endl;
                }
            }
            //empleado.Listar();
            system("pause");
            break;

        }
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}

void menuFacturacion() {
    Venta venta;
    int opc;



    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU FACTURACION -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - FACTURACION VENTA EN LOCAL" << endl;
        cout << "   2 - FACTURACION VENTA A DOMICILIO" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1: {
            venta.CalcularVentaLocal();
            bool g=venta.Grabar(venta);
            if(g) {
                cout <<"Venta registrada con exito";
            } else {
                cout<<"Error al abrir el archivo";
            }
            system("cls");
            venta.MostrarFactura();
            system("pause");
            break;
        }

        case 2: {
            venta.CalcularVentaDomicilio();
            bool g=venta.Grabar(venta);
            if(g) {
                cout <<"Venta registrada con exito";
            } else {
                cout<<"Error al abrir el archivo";
            }
            system("cls");
            venta.MostrarFactura();
            system("pause");
            break;
        }


        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }

}

void menuReportes() {
    int opc;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU REPORTES  -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - CONSULTAS" << endl;
        cout << "   2 - LISTADOS" << endl;
        cout << "   3 - INFORMES" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            menuConsultas();
            break;
        case 2:
            menuListados();
            break;
        case 3:
            menuInformes();
            break;

        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}

void menuConsultas() {
    int opc;
    Cliente cliente;
    Helado helado;
    Venta venta;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU CONSULTAS  -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - CLIENTES POR DNI" << endl;
        cout << "   2 - CLIENTES POR GUSTO DE PREFERENCIA" << endl;
        cout << "   3 - HELADOS POR GUSTO" << endl;
        cout << "   4 - STOCK POR GUSTO" << endl;
        cout << "   5 - VENTAS POR CLIENTE" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - SALIR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1: {
            char dni[9];
            cout<<"Ingrese DNI del cliente a buscar ";
            cin.ignore();
            cin.getline(dni,9);
            cliente=cliente.BuscarCliente(dni);
            if(strcmp(cliente.getDni(),"0")!=0) {
                system("cls");
                cliente.Mostrar();

            } else {
                cout<<"El cliente no existe en los registros"<<endl;

            }
            system("pause");
            break;
        }

        case 2: {
            char gusto[20];
            cout<<"Ingrese gusto a buscar ";
            cin.ignore();
            cin.getline(gusto,20);
            cliente.BuscarClienteporGusto(gusto);
            system("pause");
            break;
        }
        case 3: {
            char gusto[20];
            cout<<"Ingrese gusto a buscar ";
            cin.ignore();
            cin.getline(gusto,20);
            bool b=helado.BuscarGusto(gusto);

            if(b==false) {
                cout<<"El gusto de helado no existe"<<endl;
            }
            system("pause");
            break;
        }
        case 4: {
            char codigo[10];
            cout<<"Ingrese codigo a buscar ";
            cin.ignore();
            cin.getline(codigo,10);
            int s=helado.MostrarStock(codigo);

            if(s>=0) {
                cout<<"-----------------------"<<endl;
                cout<<"Codigo de Helado: "<<codigo<<endl;
                cout<<"Stock:   "<<s<<" bochas"<<endl;
                cout<<"-----------------------"<<endl;
            } else {

                cout<<"El codigo ingresado no existe"<<endl;
            }
            system("pause");
            break;
        }
        case 5: {
            char dni[9];
            cout<<"Ingrese DNI del cliente: ";
            cin.ignore();
            cin.getline(dni,9);

            int c=venta.ContarVentasPorCliente(dni);

            if(c>0) {
                system("cls");
                cout<<"----------------------------------"<<endl;
                cout<<endl;
                cout<<"El cliente realizo "<<c<<" compras"<<endl;
                cout<<endl;
                cout<<"----------------------------------"<<endl;
            }

            else {
                if(c==0) {
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<endl;
                    cout<<"El cliente no realizo compras. "<<endl;
                    cout<<endl;
                    cout<<"----------------------------------"<<endl;
                } else {
                    cout<<"Error al abrir el archivo"<<endl;
                }
            }
            system("pause");
            break;
        }

        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}

void menuListados() {
    int opc;
    Cliente cliente;
    Helado helado;
    Empleado empleado;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU LISTADOS -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - CLIENTES ORDENADOS POR APELLIDO" << endl;
        cout << "   2 - HELADOS ORDENADOS POR TIPOS" << endl;
        cout << "   3 - HELADOS ORDENADOS POR STOCK" << endl;
        cout << "   4 - VENDEDORES ORDENADOS POR APELLIDO" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - SALIR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            cliente.ListarPorApellido();
            system("pause");
            break;
        case 2:
            helado.ListarPorTipo();
            system("pause");
            break;
        case 3:
            helado.ListarPorStock();
            system("pause");
            break;
        case 4:
            empleado.ListarPorApellido();
            system("pause");
            break;


        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}


void menuInformes() {
    int opc;
    Venta venta;



    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU INFORMES -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - RECAUDACION MENSUAL" << endl;
        cout << "   2 - RECAUDACION ANUAL" << endl;
        cout << "   3 - RECAUDACION POR CLIENTE" << endl;
        cout << "   4 - CANTIDAD DE BOCHAS HELADOS VENDIDAS" << endl;
        cout << "   5 - RECAUDACION POR VENTAS EN LOCAL" << endl;
        cout << "   6 - RECAUDACION POR VENTAS A DOMICILIO" << endl;
        cout << "   7 - OBTENER RECAUDACION MES POR MES "<<endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            venta.ObtenerRecaudacionMensual();
            system("pause");
            break;
        case 2:
            venta.ObtenerRecaudacionAnual();
            system("pause");
            break;
        case 3:
            venta.ObtenerRecaudacionCliente();
            system("pause");
            break;
        case 4:
            venta.ObtenerCantidadBochas();
            system("pause");
            break;
        case 5:
            venta.ObtenerRecaudacionLocal();
            system("pause");
            break;
        case 6:
            venta.ObtenerRecaudacionDomicilio();
            system("pause");
            break;
        case 7:
            venta.ObtenerRecaudacionMesPorMes();
            system("pause");
            break;


        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}


void menuConfiguraciones() {

    int opc;

    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;

        cout << "-  MENU CONFIGURACIONES  -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - Realizar backup" << endl;
        cout << "   2 - Restaurar archivos" << endl;
        cout << "   3 - Exportar a Excel" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            menuBackup();

            break;
        case 2:
            menuRestaurar();

            break;
        case 3:
            menuExportarExcel();

            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}

void menuBackup() {
    int opc;
    Helado helado;
    Cliente cliente;
    Empleado empleado;
    Venta venta;

    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU BACKUP  -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - HELADOS" << endl;
        cout << "   2 - CLIENTES" << endl;
        cout << "   3 - EMPLEADOS" << endl;
        cout << "   4 - VENTAS" << endl;
        cout << "   5 - TODOS LOS ARCHIVOS" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            helado.realizarBackUp();
            cout<<"BackUp realizado con exito"<<endl;
            system("pause");
            break;
        case 2:
            cliente.realizarBackUp();
            cout<<"BackUp realizado con exito"<<endl;
            system("pause");
            break;
        case 3:
            empleado.realizarBackUp();
            cout<<"BackUp realizado con exito"<<endl;
            system("pause");
            break;
        case 4:
            venta.realizarBackUp();
            cout<<"BackUp realizado con exito"<<endl;
            system("pause");
            break;
        case 5:
            helado.realizarBackUp();
            cliente.realizarBackUp();
            empleado.realizarBackUp();
            venta.realizarBackUp();
            cout<<"BackUp realizado con exito"<<endl;
            system("pause");
            break;

        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}



void menuRestaurar() {
    int opc;
    Helado helado;
    Cliente cliente;
    Empleado empleado;
    Venta venta;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU RESTAURAR ARCHIVOS -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - HELADOS" << endl;
        cout << "   2 - CLIENTES" << endl;
        cout << "   3 - EMPLEADOS" << endl;
        cout << "   4 - VENTAS" << endl;
        cout << "   5 - TODOS LOS ARCHIVOS" << endl;

        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            helado.RestaurarArchivoHelados();
            cout<<"Reastauracion de archivo realizada!"<<endl;
            system("pause");

            break;
        case 2:
            cliente.RestaurarArchivoCliente();
            cout<<"Reastauracion de archivo realizada!"<<endl;
            system("pause");
            break;
        case 3:
            empleado.RestaurarArchivoEmpleado();
            cout<<"Reastauracion de archivo realizada!"<<endl;
            system("pause");
            break;
        case 4:
            venta.RestaurarArchivoVenta();
            cout<<"Reastauracion de archivo realizada!"<<endl;
            system("pause");
            break;
        case 5:
            helado.RestaurarArchivoHelados();
            cliente.RestaurarArchivoCliente();
            empleado.RestaurarArchivoEmpleado();
            venta.RestaurarArchivoVenta();
            cout<<"Reastauraciones de archivo realizadas!"<<endl;
            system("pause");
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}


void menuExportarExcel() {
    Helado helado;
    Cliente cliente;
    Empleado empleado;
    Venta venta;
    int opc;


    while(true) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "-  MENU EXPORTAR A EXCEL -" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   1 - HELADOS" << endl;
        cout << "   2 - CLIENTES" << endl;
        cout << "   3 - EMPLEADOS" << endl;
        cout << "   4 - VENTAS" << endl;
        cout << "---------------------------------------" << endl;
        cout << "   0 - RETORNAR" << endl;
        cout << endl;
        cout << "OPCION: ";
        cin >> opc;

        switch(opc) {
        case 1:
            helado.CargarExcelHelados();
            cout << "Creacion Exitosa!" << endl;

            system("pause");

            break;
        case 2:
            cliente.CargarExcelClientes();
            cout << "Creacion Exitosa!" << endl;

            system("pause");

            break;
        case 3:
            empleado.CargarExcelEmpleados();
            cout << "Creacion Exitosa!" << endl;

            system("pause");
            break;
        case 4:
            venta.CargarExcelVentas();
            cout << "Creacion Exitosa!" << endl;

            system("pause");
            break;
        case 0:
            cout << endl << endl;
            return;
            break;
        default:
            cout<<"Opcion invalida."<<endl;
            return;
            break;
        }
    }
}
#endif // MENU_H_INCLUDED
