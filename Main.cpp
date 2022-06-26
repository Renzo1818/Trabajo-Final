#pragma once
#include <iostream>     
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
int codVendedor;
string fecha;

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
void listarVentas();
void modificarEstadoVenta();
void listarVentasCanceladas();
void cierreDeCaja();
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
    cout << "\t";
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

        codVendedor = vendedorVector.BuscarPorUsuario(usuario, contrasena);

        validacion = vendedorVector.getValidacionVendedor(objValidacion);


        if (validacion == true)
        {
            system("cls");
            cout << "\t\t|||||| Bienvenido al sistema ||||||\n";
            cout << "\n\tIngresar Fecha: ";
            cin >> fecha;
            system("pause");
            system("cls");
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
        cout << "\n\tListar Ventas                       [7]\n";
        cout << "\n\tCambiar estado de la venta          [8]\n";
        cout << "\n\tListar ventas canceladas            [9]\n";
        cout << "\n\tCierre caja                         [10]\n";
        cout << "\n\tSalir                               [11]\n";
        cout << "\n\tIngresar una opcion                 [1-11]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); agregarProductos(); break;
        case 2: system("cls"); listarProductos(); system("cls"); break;
        case 3: system("cls"); modificarProductos(); break;
        case 4: system("cls"); eliminarProductos(); break;
        case 5: system("cls"); listarEmpleados(); system("cls"); break;
        case 6: system("cls"); eliminarEmpleados(); break;
        case 7: system("cls"); listarVentas(); system("pause"); system("cls"); break;
        case 8: system("cls"); modificarEstadoVenta(); break;
        case 9: system("cls"); listarVentasCanceladas(); system("pause"); system("cls"); break;
        case 10:system("cls"); cierreDeCaja(); system("pause"); system("cls"); break;
        case 11:	cout << "\n\n\n\t\t--------Gracias por tu visita--------\n";
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

    listarProductos();

    cout << "Ingrese el codigo a buscar: ";
    cin >> codigo;
    Producto objModificar = vectorProductos.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    system("cls");

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

    listarProductos();


    cout << "\t\t|||||| MENU ELIMINAR ||||||\n";
    cout << "\n\tIngresar codigo a eliminar: "; cin >> codigo;

    Producto objBuscar = vectorProductos.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    system("pause");

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
    //system("cls");
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
void listarVentas() {
    cout << "\t\t|||||| VENTAS ||||||\n";
    cout << "\t\t**************" << endl;

    for (int i = 0; i < vectorVentas.rows(); i++)
    {
        cout << "\n\tCodigo Venta (" << vectorVentas.get(i).getCodVenta() << ")" << endl;
        cout << "\n\tCodigo Vendedor (" << vectorVentas.get(i).getCodVendedor() << ")" << endl;
        cout << "\n\tFecha: " << vectorVentas.get(i).getFecha() << endl;
        cout << "\n\tEstado: " << vectorVentas.get(i).getEstado() << endl;
        cout << "\n\tTipo de Venta: " << vectorVentas.get(i).getTipoVenta() << endl;
        cout << "\n\tDNI del Cliente: " << vectorVentas.get(i).getDni() << endl;

        if (vectorVentas.get(i).getTipoVenta() == "Boleta" || vectorVentas.get(i).getTipoVenta() == "boleta")
        {
            cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
        }
        else if (vectorVentas.get(i).getTipoVenta() == "Factura" || vectorVentas.get(i).getTipoVenta() == "factura")
        {
            cout << "\n\tRUC del Cliente: " << vectorVentas.get(i).getRuc() << endl;
            cout << "\n\tSub-Total: " << vectorVentas.get(i).getSubTotal() << endl;
            cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
        }
        else {
            cout << "VENTAS NO ENCONTRADA!!!!!" << endl;
        }
        cout << "\t\t--------------------------------\n";

    }

}
void modificarEstadoVenta()
{
    int codigo;
    string estadoMod;

    listarVentas();

    cout << "\t\t*************************************\n";
    cout << "\t\t|||||| Modificar Estado ||||||\n";
    cout << "\t\t*************************************\n";
    cout << "\n\tIngrese el codigo Venta a modificar: ";
    cin >> codigo;

    Venta objModificarEstado = vectorVentas.buscaPorCodigo(codigo);

    if ( objModificarEstado.getEstado() == "ACTIVO")
    {
        bool estado = vectorVentas.modificarEstado(codigo, "CANCELADO");

        if (estado == true)
        {
            cout << "\n\tEstado Modificado Satisfactoriamente!!\n";
            vectorVentas.grabarModificarArchivo();
        }
        else
        {
            cout << "\n\tNo se edito el Estado!!\n";
            system("pause");
        }
    }
    else if (objModificarEstado.getEstado() == "CANCELADO") {

        bool estado = vectorVentas.modificarEstado(codigo, "ACTIVO");

        if (estado == true)
        {
            cout << "\n\tEstado Modificado Satisfactoriamente!!\n";
            vectorVentas.grabarModificarArchivo();
        }
        else
        {
            cout << "\n\tNo se edito el Estado!!\n";
            system("pause");
        }
    }
    else {
        cout << "No existe la venta!!!" << endl;
    }

    
    system("pause");
    system("cls");
}
void listarVentasCanceladas() {

    cout << "\t\t|||||| LISTA DE VENTAS CANCELADAS ||||||\n";

    for (int i = 0; i < vectorVentas.rows(); i++)
    {

        if (vectorVentas.get(i).getEstado() == "CANCELADO")
        {
            
            cout << "\n\tCodigo Venta (" << vectorVentas.get(i).getCodVenta() << ")" << endl;
            cout << "\n\tCodigo Vendedor (" << vectorVentas.get(i).getCodVendedor() << ")" << endl;
            cout << "\n\tFecha: " << vectorVentas.get(i).getFecha() << endl;
            cout << "\n\tEstado: " << vectorVentas.get(i).getEstado() << endl;
            cout << "\n\tTipo de Venta: " << vectorVentas.get(i).getTipoVenta() << endl;
            cout << "\n\tDNI del Cliente: " << vectorVentas.get(i).getDni() << endl;

            if (vectorVentas.get(i).getTipoVenta() == "Boleta" || vectorVentas.get(i).getTipoVenta() == "boleta")
            {
                cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
            }
            else if (vectorVentas.get(i).getTipoVenta() == "Factura" || vectorVentas.get(i).getTipoVenta() == "factura")
            {
                cout << "\n\tRUC del Cliente: " << vectorVentas.get(i).getRuc() << endl;
                cout << "\n\tSub-Total: " << vectorVentas.get(i).getSubTotal() << endl;
                cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
            }
            else
            {
                cout << "VENTAS NO ENCONTRADA!!!!!" << endl;
            }
            cout << "\n\t--------------------------------\n";
        }
    }
}
void cierreDeCaja(){
    string fe;
    float acu;

    cout << "\t\t|||||| CIERRE DE CAJA ||||||\n";
    cout << "\n\tIngresar fecha: "; cin >> fe;

    acu = vectorVentas.GetCierreCaja(fe);

    cout << "\n\tEl cierre de caja de la fecha (" << fe << ") es: " << acu;

    cout << "\n";

}

/*void modificarEstadoVenta()
{
    int codigo;
    string estadoMod;

    listarVentas();
    cout << "\n";
    cout << "\t\t******************************\n";
    cout << "\t\t|||||| Modificar Estado ||||||\n";
    cout << "\t\t*******************************\n";
    cout << "\n\tIngrese el codigo Venta a modificar: ";
    cin >> codigo;
    cout << "\n\tNuevo Estado: "; 
    cin >> estadoMod;

    bool estado = vectorVentas.modificarEstado(codigo, estadoMod);
    if (estado = true)
    {
        cout << "\n\tEstado Modificado Satisfactoriamente!!\n";
        vectorVentas.grabarModificarArchivo();
    }
    else
    {
        cout << "\n\tNo se edito el Estado!!\n";
        system("pause");
    }
    system("pause");
    system("cls");
}*/
void menuVendedor()
{
    //Declarar Variables
    int opt;
    do
    {
        cout << "\t\t|||||| MENU DE OPCIONES VENTAS ||||||\n";
        cout << "\n\tRegistrar Venta               [1]\n";
        cout << "\n\tListar Compra                 [2]\n";
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
        default:cout << "Ingrese una opcion correcta [1-3]" << endl; system("pause"); system("cls");
        }
    } while (opt != 3);
}
void registrarVenta()
{
    //vectorDetalle, vectorVentas

    int codigoVenta;
    int cantidad;
    string dni, ruc;
    int codProducto;
    string rpta, confirmacion, eleccion;
    float acumulador = 0;

    cout << "\t\t|||||| REGISTAR VENTA ||||||\n";
    cout << "\t\t*******************************\n";
    codigoVenta = vectorVentas.getCorrelativoCodigo();
    cout << "\n\tCodigo(" << codigoVenta << ")" << endl;
    cin.ignore();
    system("cls");


    do {
        cout << "\t\t|||||| CATALOGO ||||||\n";
        listarProductos();
        cout << "\t\t||||||||||||||||||||||\n";

        cout << "\n\tIngresar codigo del Producto: ";
        cin >> codProducto;
        system("cls");

        Producto objProductoBusca = vectorProductos.buscaPorCodigo(codProducto);

        if (objProductoBusca.getNombre() != "Error")
        {
            cout << "\t\t|| Producto Seleccionado ||" << endl;
            cout << "\t\t--------------------------------\n";
            cout << "\n\tProducto: " << objProductoBusca.getNombre() << "\n";
            cout << "\n\tPrecio : s/" << objProductoBusca.getPrecio() << "\n";
            cout << "\n\tStock: " << objProductoBusca.getStock() << "\n";
            cout << "--------------------------------\n";

        }
        else
        {
            cout << "--No se encontro el producto--" << endl;
            system("pause");
            registrarVenta();
        }

        cout << "\n\tIngresar cantidad del Producto: ";
        cin >> cantidad;

        if (objProductoBusca.getStock() >= cantidad)
        {
            DetalleVenta objDetalleVenta;
            objDetalleVenta.setCodVenta(codigoVenta);
            objDetalleVenta.setCantidad(cantidad);
            objDetalleVenta.setCodProducto(codProducto);
            objDetalleVenta.setNombre(objProductoBusca.getNombre());
            objDetalleVenta.setStock(objProductoBusca.getStock());
            objDetalleVenta.setPrecio(objProductoBusca.getPrecio());

            acumulador += objDetalleVenta.getImporte();

            cout << "\n\tEstas seguro de anadir los anteriores productos al carrito? [SI / Si / si]: ";
            cin >> confirmacion;

            if (confirmacion == "SI" || confirmacion == "Si" || confirmacion == "si")
            {
                //Actualizacion Stock
                Producto objProductoStock = vectorProductos.buscaPorCodigo(codProducto);

                vectorProductos.modificarStock(vectorProductos.buscaPorCodigo(codProducto), cantidad);
                vectorProductos.grabarModificarEliminarArchivo();

                //Agregar productos al carrito
                vectorDetalle.add(objDetalleVenta);
                vectorDetalle.grabarEnArchivoDetalleVenta(objDetalleVenta);
            }
            else
            {

                system("pause");
            }
        }
        else
        {
            cout << "\n\tProducto Elegido con stock Limitado..." << endl;
            cout << "\n\tStock del Prodcuto: " << objProductoBusca.getStock() << endl;
            cout << "\n\tPor favor ingresar una cantidad válida!!!" << endl;
            system("pause");
            system("cls");
            registrarVenta();
        }

        cout << "\n\n\t\t*******************************\n";

        cout << "\n\tDesea ingresar mas productos? [SI/ Si/ si]: ";
        cin >> rpta;

        system("cls");


    } while (rpta == "SI" || rpta == "Si" || rpta == "si");

    system("cls");

    bool bandera;
    do
    {
        bandera = false;
        //Ingrese sus datos
        cout << "\t\t||||||GENERAR COMPRA||||||\n";
        cout << "\n\tIngresar el DNI del cliente: ";
        cin >> dni;

        cout << "\n";
        cout << "\n\tDesea Boleta o Factura: "; cin >> eleccion;
        system("cls");

        if (eleccion == "Boleta" || eleccion == "boleta")
        {
            //Listar todos los productos
            Venta objBoleta;
            objBoleta.setCodVenta(codigoVenta);
            objBoleta.setCodVendedor(codVendedor);
            objBoleta.setFecha(fecha);
            objBoleta.setDni(dni);
            objBoleta.setRuc("-");
            objBoleta.setIgv(0);
            objBoleta.setSubTotal(0);
            objBoleta.setTotal(acumulador);
            objBoleta.setEstado("ACTIVO");
            objBoleta.setTipoVenta("Boleta");

            vectorVentas.add(objBoleta);
            vectorVentas.grabarEnArchivoVenta(objBoleta);

            cout << "\t\t|||||| " << objBoleta.getTipoVenta() << " ||||||\n";
            cout << "\t\t|||||| CARRITO ||||||\n";

            cout << "\t\t--------------------------------\n";

            vectorDetalle.listarDetallesVentas(objBoleta.getCodVenta());


            cout << "\n\tTotal: " << objBoleta.getTotal() << endl;
            cout << "\n\t||||||COMPRA REALIZADA||||||\n";

            system("pause");
            system("cls");
        }



        else if (eleccion == "Factura" || eleccion == "factura")
        {
            //Ruc
            cout << "\n\tIngrese su numero de ruc: ";
            cin >> ruc;
            system("pause");
            system("cls");
            //Listar todos los productos
            Venta objFactura;
            objFactura.setCodVenta(codigoVenta);
            objFactura.setCodVendedor(codVendedor);
            objFactura.setFecha(fecha);
            objFactura.setDni(dni);
            objFactura.setRuc(ruc);
            objFactura.setIgv(0.18);
            objFactura.setSubTotal(acumulador);
            objFactura.setTotal(objFactura.getSubTotal() - objFactura.getsubTotalIGV());
            objFactura.setEstado("ACTIVO");
            objFactura.setTipoVenta("Factura");

            vectorVentas.add(objFactura);
            vectorVentas.grabarEnArchivoVenta(objFactura);


            cout << "\t\t|||||| " << objFactura.getTipoVenta() << " ||||||\n";
            cout << "\t\t|||||| CARRITO ||||||\n";

            cout << "\t\t--------------------------------\n";

            vectorDetalle.listarDetallesVentas(objFactura.getCodVenta());

            cout << "\n\tSub Total: " << objFactura.getSubTotal() << endl;
            cout << "\n\tPrecio aplicando IGV: " << objFactura.getsubTotalIGV() << endl;
            cout << "\n\tTotal: " << objFactura.getTotal() << endl;
            cout << "\n\t||||||COMPRA REALIZADA||||||\n";


            system("pause");
            system("cls");

        }
        else
        {
            cout << "*************Ingresar un dato valido*************";
            bandera = true;
        }
    } while (bandera == true);
}

/*void listarVentas()
{
    int codVd;
    int codVt;
    listarEmpleados();
    cout << "\n\tIngresar el codigo del vendedor: ";
    cin >> codVd;
    system("cls");

    for (int i = 0; i < vectorVentas.rows(); i++) {
        if (codVd == vectorVentas.get(i).getCodVendedor())
        {
            cout << "\n\tCodigo Venta (" << vectorVentas.get(i).getCodVenta() << ")" << endl;
            cout << "\n\tEstado: " << vectorVentas.get(i).getEstado() << endl;
            cout << "\n\tTipo de Venta: " << vectorVentas.get(i).getTipoVenta() << endl;
            cout << "\n\tDNI del Cliente: " << vectorVentas.get(i).getDni() << endl;

            cout << "\n\t----------------------------------\n";

            if (vectorVentas.get(i).getTipoVenta() == "Boleta" || vectorVentas.get(i).getTipoVenta() == "boleta")
            {
                codVt = vectorVentas.get(i).getCodVenta();
                vectorDetalle.listarDetallesVentas(codVt);
                cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
            }
            else if (vectorVentas.get(i).getTipoVenta() == "Factura" || vectorVentas.get(i).getTipoVenta() == "factura")
            {
                cout << "\n\tRUC del Cliente: " << vectorVentas.get(i).getRuc() << endl;
                codVt = vectorVentas.get(i).getCodVenta();
                vectorDetalle.listarDetallesVentas(codVt);
                cout << "\n\tSub-Total: " << vectorVentas.get(i).getSubTotal() << endl;
                cout << "\n\tIGV: " << vectorVentas.get(i).getsubTotalIGV() << endl;
                cout << "\n\tTotal: " << vectorVentas.get(i).getTotal() << endl;
            }

            cout << "\n\t--------------------------------\n";
        }
    }
}*/
