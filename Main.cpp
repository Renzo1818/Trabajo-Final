#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "RegistroVendedor.h"
#include "RegistroAdmin.h"
#include "RegistroProducto.h"
#include "RegistroDetalleVenta.h"
#include "RegistroVenta.h"
using namespace std;

//Globales
int codigoVendedor;

//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
AdminVector vectorAdmin;
ProductoVector vectorProductos;
DetalleVentaVector vectorDetalle;
VentaVector vectorVentas;

//Prototipos Generales
void menuDeOpcionesGeneral();

//Protitos - ADMIN
void loginAdmin();
void ingresoAdmin();
void registroAdmin();
void menuAdmin();

void agregarProductos();
void listarProductos();
void modificarProductos();
void eliminarProductos();
//void modificarEstadoVenta();
//void listarVentas();
//void cierreDeCaja();
void listarEmpleados();
void eliminarEmpleados();


//Prototipos - VENDEDOR
void loginVendedor();
void ingresarSistema();
void registroSistema();
void menuVendedor();

void registrarVenta();
//void listarCompra();



string generarContrasena(int n)
{
    char a;
    string b;
    for (int i = 0; i < n; i++)
    {
        a = 97 + rand() % (122 - 97);
        b += a;
    }
    return b;
}

int main()
{
    menuDeOpcionesGeneral();
}


void menuDeOpcionesGeneral()
{
    //Declarar Variables
    int opt;
    do
    {
        cout << "\t\t|||||| MENU DE OPCIONES GENERALES ||||||\n";
        cout << "\n\tIngresar como Administrador	[1]\n";
        cout << "\n\tIngresar como vendedor	        [2]\n";
        cout << "\n\tSalir			        [3]\n";
        cout << "\n\tIngrese una opcion              [1-3]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); ingresoAdmin(); break;
        case 2: system("cls"); loginVendedor(); break;
        case 3:	cout << "\n\n\n\t\t--------Gracias por tu visita--------\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta [1-3]" << endl;
        }
    } while (opt != 3);
}


void ingresoAdmin()
{
    bool validacion;

    validacion = vectorAdmin.validacionVectorVacio();
    if (validacion == true)
    {
        registroAdmin();
    }
    else
    {
        loginAdmin();
    }
}



void registroAdmin()
{
    int cod;
    string usuario;
    string contrasena;

    cout << "\t\t|||||| REGISTRO DE ADMIN ||||||" << "\n";
    cod = vectorAdmin.getCorrelativoCodigo();

    cout << "\n\tCodigo(" << cod << ")" << endl;
    cin.ignore();
    cout << "\n\tIngresar Usuario: ";
    cin >> usuario;
    srand(time(NULL));
    contrasena = generarContrasena(8);
    cout << "\n\tContrasena Generada: " << contrasena;

    Admin objAdmin;
    objAdmin.setIdCodigo(cod);
    objAdmin.setUsuario(usuario);
    objAdmin.setContrasena(contrasena);

    vectorAdmin.add(objAdmin);
    vectorAdmin.grabarEnArchivoAdmin(objAdmin);
    cout << "\n";
    system("pause");
    system("cls");

    loginAdmin();
}


void loginAdmin()
{
    string usuario;
    string contrasena;
    char caracter;
    bool validacion = false;
    int cont = 0;

    do
    {
        cout << "\t\t|||||| LOGIN DE USUARIO ||||||" << "\n";
        cin.ignore();
        cout << "\n\tIngresar Usuario: ";
        cin >> usuario;
        cout << "\n\tIngresar Contrasena: ";
        caracter = _getch();

        contrasena = "";
        while (caracter != 13)
        {
            if (caracter != 8)
            {
                contrasena.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (contrasena.length() > 0)
                {
                    cout << "\b \b";
                    contrasena = contrasena.substr(0, contrasena.length() - 1);
                }
            }
            caracter = _getch();
        }
        //cin >> contrasena;
        Admin objAdmin;
        objAdmin.setUsuario(usuario);
        objAdmin.setContrasena(contrasena);

        validacion = vectorAdmin.getValidacionAdmin(objAdmin);


        if (validacion == true)
        {
            system("cls");
            cout << "\t\t|||||| Bienvenido al sistema ||||||\n";
            system("pause");
            system("cls");
            menuAdmin();
            
        }
        else
        {
            system("cls");
            cont++;
            cout << "No pudo ingresar, intentelo mas tarde" << endl;
            system("pause");
        }


    } while (validacion = false && cont < 3);
}


void loginVendedor()
{
    //Declarar Variables
    int opt;
    do
    {
        cout << "\t\t|||||| MENU DE OPCIONES ||||||\n";
        cout << "\n\tRegistrarse en el sistema     [1]\n";
        cout << "\n\tIngresar al sistema           [2]\n";
        cout << "\n\tSalir			      [3]\n";
        cout << "\n\tIngrese una opcion            [1-3]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); registroSistema(); break;
        case 2: system("cls"); ingresarSistema(); break;
        case 3:	cout << "\n\n\n\t\t-----Gracias por tu visita------\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta [1-3]" << endl;
        }
    } while (opt != 3);
}


void registroSistema()
{
    int cod;
    string usuario;
    string contrasena;


    cout << "\t\t|||||| REGISTRO DE USUARIO ||||||" << "\n";
    cod = vendedorVector.getCorrelativoCodigo();
    codigoVendedor = cod;

    cout << "\n\tCodigo(" << cod << ")" << endl;
    cin.ignore();
    cout << "\n\tIngresar Usuario: ";
    cin >> usuario;
    cout << "\n\tIngresar Contrasena: ";
    cin >> contrasena;


    Vendedor objVendedor;
    objVendedor.setCodVendedor(cod);
    objVendedor.setUsuario(usuario);
    objVendedor.setContrasena(contrasena);

    vendedorVector.add(objVendedor);
    vendedorVector.grabarEnArchivoVendedor(objVendedor);
    system("cls");

    ingresarSistema();
}


void ingresarSistema()
{
    string usuario;
    string contrasena;
    char caracter;
    bool validacion = false;
    int cont = 0;

    do
    {
        cout << "\t\t|||||| LOGIN DE USUARIO ||||||" << "\n";
        cin.ignore();
        cout << "\n\tIngresar Usuario: ";
        cin >> usuario;
        cout << "\n\tIngresar Contraseña: ";
        caracter = _getch();

        contrasena = "";
        while (caracter != 13){
            if (caracter != 8){
                contrasena.push_back(caracter);
                cout << "*";
            }
            else {
                if (contrasena.length() > 0) {
                    cout << "\b \b";
                    contrasena = contrasena.substr(0, contrasena.length() - 1);
                }
            }
            caracter = _getch();

        }
        //cin>> contrasena;

        Vendedor objValidacion;
        objValidacion.setUsuario(usuario);
        objValidacion.setContrasena(contrasena);

        validacion = vendedorVector.getValidacionVendedor(objValidacion);


        if (validacion == true)
        {
            system("cls");
            cout << "\t\t|||||| Bienvenido al sistema ||||||\n";
            menuVendedor();

        }
        else
        {
            system("cls");
            cont++;
            cout << "No pudo ingresar, intentelo mas tarde" << endl;
            system("pause");
        }


    } while (validacion = false && cont < 3);
}

void menuAdmin() {
    //Declarar Variables
    int opt;
    do
    {
        cout << "\t\t|||||| MENU DE OPCIONES ADMIN ||||||\n";
        cout << "\n\tAgregar Productos	            [1]\n";
        cout << "\n\tListar Productos                    [2]\n";
        cout << "\n\tModificar Productos	            [3]\n";
        cout << "\n\tEliminar Productos                  [4]\n";
        cout << "\n\tListar Empleados                    [5]\n";
        cout << "\n\tListar Eliminar                     [6]\n";
        cout << "\n\tSalir                               [7]\n";
        cout << "\n\tIngresar una opcion                 [1-7]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); agregarProductos(); break;
        case 2: system("cls"); listarProductos(); break;
        case 3: system("cls"); modificarProductos(); break;
        case 4: system("cls"); eliminarProductos(); break;
        case 5: system("cls"); listarEmpleados(); break;
        case 6: system("cls"); eliminarEmpleados(); break;
        case 7:	cout << "\n\n\n\t\t--------Gracias por tu visita--------\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta [1-9]" << endl;
        }
    } while (opt != 9);

}
void agregarProductos()
{
    int codigo;
    string nombre;
    float precio;
    int stock;
    string rpta;
    //vectorProducto
    do
    {
        system("cls");
        cout << "\t\t|||||| Agregar Productos ||||||\n";
        cout << "\t\t*******************************\n";
        codigo = vectorProductos.getCorrelativoCodigo();
        cout << "\n\tCodigo(" << codigo << ")" << endl;
        cin.ignore();
        cout << "\n\tIngresar nombre del Producto: ";
        getline(cin, nombre);
        cout << "\n\tIngresar precio: "; cin >> precio;
        cout << "\n\tIngresar stock: "; cin >> stock;

        Producto objProducto;
        objProducto.setCodProducto(codigo);
        objProducto.setNombre(nombre);
        objProducto.setPrecio(precio);
        objProducto.setStock(stock);

        vectorProductos.add(objProducto);
        vectorProductos.grabarEnArchivoProducto(objProducto);

        cout << "\n\n\t\t*******************************\n";

        cout << "\n\tDesear ingresar mas productos: "; 
        cin >> rpta;

    } while (rpta == "SI" || rpta == "Si" || rpta == "si");

    system("cls");
}


void listarProductos()
{
    cout << "\t*************************************" << endl;

    for (int i = 0; i < vectorProductos.rows(); i++)
    {
        cout << "\tCodigo: " << vectorProductos.get(i).getCodProducto() << endl;
        cout << "\tNombre: " << vectorProductos.get(i).getNombre() << endl;
        cout << "\tPrecio: " << vectorProductos.get(i).getPrecio() << endl;
        cout << "\tStock: " << vectorProductos.get(i).getStock() << endl;
        cout << "\t*************************************" << endl;
    }

    system("pause");
    //system("cls");

}

void modificarProductos()
{
    int codigo;
    cout << "Ingrese el codigo a buscar: ";
    cin >> codigo;
    Producto objModificar = vectorProductos.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    cout << "\t\t|||||| Registro encontrado... ||||||\n";
    cout << "\n\tCodigo (" << objModificar.getCodProducto() << ")\n";
    cout << "\n\tNombre: " << objModificar.getNombre() << "\n";
    cout << "\n\tPrecio: " << objModificar.getPrecio() << "\n";
    cout << "\n\tStock: " << objModificar.getStock() << "\n";
    cin.ignore();

    cout << "\t\t*************************************\n";

    string nomModificado;
    int stockModificado;
    float precioModificado;

    cout << "\t\t|||||| Modificar campos ||||||\n";
    cout << "\t\t*************************************\n";

    cout << "\n\tNuevo Nombre: "; getline(cin, nomModificado);
    cout << "\n\tNuevo Precio: "; cin >> precioModificado;
    cout << "\n\tNuevo Stock: "; cin >> stockModificado;

    bool estado = vectorProductos.modificar(objModificar, nomModificado, precioModificado, stockModificado);
    if (estado = true)
    {
        cout << "\n\tRegistro Modificado Satisfactoriamente!!\n";

        vectorProductos.grabarModificarEliminarArchivo();
    }
    else
    {
        cout << "No se edito el registro!!\n";
        system("pause");

    }
    system("pause");
    system("cls");

}

void eliminarProductos()
{
    int codigo;
    string rpta;
    cout << "\t\t|||||| MENU ELIMINAR ||||||\n";
    cout << "\n\tIngresar codigo a eliminar: "; cin >> codigo;

    Producto objBuscar = vectorProductos.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    cout << "\t\t|||||| Registro encontrado... ||||||\n";
    cout << "\n\tCodigo (" << objBuscar.getCodProducto() << ")\n";
    cout << "\n\tNombre: " << objBuscar.getNombre() << "\n";
    cout << "\n\tPrecio: " << objBuscar.getPrecio() << "\n";
    cout << "\n\tStock: " << objBuscar.getStock() << "\n";
    cin.ignore();


    cout << "\t\t*************************************\n";

    cout << "Esta seguro que desea eliminar este producto? ";
    cin >> rpta;

    if (rpta == "SI" || rpta == "Si" || rpta == "si") {
        Producto objEliminar = vectorProductos.buscaPorCodigo(codigo);
        
        if (objEliminar.getNombre() != "Error")
        {
            vectorProductos.remove(objEliminar);

            cout << "\n\t------Registro Eliminado Satisfactoriamente!!!------" << "\n";

            vectorProductos.grabarModificarEliminarArchivo();

        }
        else
        {
            cout << "No se encontró el registro!!" << endl;
        }
        system("pause");
        system("cls");

    }
    
}
void listarEmpleados()
{
    cout << "\t\t|||||| Menu listar empleados ||||||" << endl;
    cout << "\t\t*************************************" << endl;

    for (int i = 0; i < vendedorVector.rows(); i++)
    {
        cout << "\tCodigo: " << vendedorVector.get(i).getCodVendedor() << endl;
        cout << "\tNombre: " << vendedorVector.get(i).getUsuario() << endl;
        cout << "\t*************************************" << endl;
    }

    system("pause");
    system("cls");
}

void eliminarEmpleados()
{
    int codigo;
    string rpta;

    cout << "\t\t|||||| Menu Eliminar Empleado ||||||" << endl;
    cout << "\t\t************************************" << endl;

    cout << "\n\tIngresar codigo a eliminar: "; cin >> codigo;

    Vendedor objBuscar = vendedorVector.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    cout << "\t\t|||||| Registro encontrado... ||||||\n";
    cout << "\n\tCodigo (" << objBuscar.getCodVendedor() << ")\n";
    cout << "\n\tUsuario: " << objBuscar.getUsuario() << "\n";

    cin.ignore();

    cout << "\t\t*************************************\n";

    cout << "\n\tEsta seguro que desea eliminar? ";
    cin >> rpta;

    if (rpta == "SI" || rpta == "Si" || rpta == "si")
    {
        Vendedor objEliminar = vendedorVector.buscaPorCodigo(codigo);

        if (objEliminar.getUsuario() != "Error")
        {
            vendedorVector.remove(objEliminar);

            cout << "\n\t------Registro Eliminado Satisfactoriamente!!!------" << "\n";

            vendedorVector.grabarModificarEliminarArchivo();
        }
        else
        {
            cout << "No se encontró el registro!!" << endl;
        }
        cout << "\n";
        system("pause");
        system("cls");
    }
    else {
        system("cls");
    }
}
void menuVendedor()
{
    //Declarar Variables
    int opt;
    do
    {
        cout << "\t\t|||||| MENU DE OPCIONES VENTAS ||||||\n";
        cout << "\n\tRegistrar Venta               [1]\n";
        cout << "\n\tListar Compra           [2]\n";
        cout << "\n\tSalir			      [3]\n";
        cout << "\n\tIngrese una opcion            [1-3]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); registrarVenta(); break;
        case 2: system("cls"); cout<<"Hola"; break;
        case 3:	cout << "\n\n\n\t\t-----Gracias por tu visita------\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta [1-3]" << endl;
        }
    } while (opt != 3);
}
void registrarVenta()
{
    //vectorDetalle, vectorVentas

    int codigoVenta;
    int codigoVendedor = 0;
    int cantidad;
    string dni;
    int codProducto;
    string rpta, confirmacion, eleccion;
    float acumulador = 0;

    cout << "\t\t|||||| REGISTAR VENTA ||||||\n";
    cout << "\t\t*******************************\n";
    codigoVenta = vectorVentas.getCorrelativoCodigo();
    cout << "\n\tCodigo(" << codigoVenta << ")" << endl;
    cout << "\n\tIngresar el DNI del cliente: ";
    cin >> dni;
    cin.ignore();
    system("cls");


    do {
        cout << "\t\t|||||| CATALOGO ||||||\n";
        listarProductos();
        cout << "\t\t||||||||||||||||||||||\n";

        cout << "\n\tIngresar codigo del Producto: ";
        cin >> codProducto;
        cin.ignore();

        Producto objProductoBusca = vectorProductos.buscaPorCodigo(codProducto);

        if (objProductoBusca.getNombre() != "Error")
        {
            cout << "\t\t|| Producto Seleccionado ||" << endl;
            cout << "\t\t--------------------------------\n";
            cout << "\n\tProducto: " << objProductoBusca.getNombre() << "\n";
            cout << "\n\tPrecio : s/" << objProductoBusca.getPrecio() << "\n";
            cout << "\n\tStock: " << objProductoBusca.getStock() << "\n";
            cout << "--------------------------------\n";

            system("pause");
        }
        else
        {
            cout << "--No se encontro el producto--" << endl;
            system("pause");
            registrarVenta();
        }

        cout << "\n\tIngresar cantidad del Producto: ";
        cin >> cantidad;

        cout << "\n\tEstas seguro de anadir los anteriores productos al carrito? [SI / Si / si]: ";
        cin >> confirmacion;

        if (confirmacion == "SI" || confirmacion == "Si" || confirmacion == "si")
        {
            DetalleVenta objDetalleVenta;
            objDetalleVenta.setCodVenta(codigoVenta);
            objDetalleVenta.setCantidad(cantidad);
            
            objDetalleVenta.setCodProducto(codProducto);
            objDetalleVenta.setNombre(objProductoBusca.getNombre());
            objDetalleVenta.setStock(objProductoBusca.getStock());
            objDetalleVenta.setPrecio(objProductoBusca.getPrecio());
            objDetalleVenta.getImporte();


            acumulador += objDetalleVenta.getImporte();

            vectorDetalle.add(objDetalleVenta);
            vectorDetalle.grabarEnArchivoDetalleVenta(objDetalleVenta);
        }
        else
        {
            system("pause");
            registrarVenta();
        }

        cout << "\n\n\t\t*******************************\n";

        cout << "\n\tDesear ingresar mas productos: ";
        cin >> rpta;

        system("cls");


    } while (rpta == "SI" || rpta == "Si" || rpta == "si");

    system("cls");

    /*/Venta objVenta;
    objVenta.setCodVenta(codigoVenta);
    objVenta.setCodVendedor(codigoVendedor);
    objVenta.setDni(dni);
    objVenta.setSubTotal(acumulador);
    objVenta.setIgv(0.18);
    objVenta.setEstado("activo");*/


    //cout << "Desea Boleta o Factura: "; cin >> eleccion;
    bool bandera;
    do
    {
        bandera = false;
        cout << "Desea Boleta o Factura: "; cin >> eleccion;

        if (eleccion == "Boleta" || eleccion == "boleta")
        {
            //Listar todos los productos
            Venta objBoleta;
            objBoleta.setCodVenta(codigoVenta);
            objBoleta.setCodVendedor(codigoVendedor);
            objBoleta.setDni("-");
            objBoleta.setIgv(0);
            objBoleta.setSubTotal(0);
            objBoleta.setTotal(acumulador);
            objBoleta.setEstado("activo");
            objBoleta.setTipoVenta("Boleta");

            vectorVentas.add(objBoleta);
            vectorVentas.grabarEnArchivoVenta(objBoleta);

        }
        else if (eleccion == "Factura" || eleccion == "factura")
        {
            //Listar todos los productos
            Venta objFactura;
            objFactura.setCodVenta(codigoVenta);
            objFactura.setCodVendedor(codigoVendedor);
            objFactura.setDni(dni);
            objFactura.setSubTotal(acumulador);
            objFactura.setIgv(0.18);
            objFactura.setTipoVenta("Factura");

            
            objFactura.setTotal(objFactura.getSubTotal() - objFactura.getsubTotalIGV());
            objFactura.setEstado("activo");
            vectorVentas.add(objFactura);
            vectorVentas.grabarEnArchivoVenta(objFactura);

            
        }
        else
        {
            cout << "*************Ingresar un dato valido*************";
            bandera = true;
        }
    } while (bandera == true);
}
