#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "RegistroVendedor.h"
#include "RegistroAdmin.h"
#include "RegistroProducto.h"
using namespace std;

//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
AdminVector vectorAdmin;
ProductoVector vectorProductos;

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
//void listarEmpleados();
//void eliminarEmpleados();


//Prototipos - VENDEDOR
void loginVendedor();
void ingresarSistema();
void registroSistema();
//void menuDeVentas();


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

    cout << "\n\tCodigo(" << cod << ")" << endl;
    cin.ignore();
    cout << "\n\tIngresar Usuario: ";
    cin >> usuario;
    cout << "\n\tIngresar Contrasena: ";
    cin >> contrasena;


    Vendedor objVendedor;
    objVendedor.setCodigo(cod);
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
            //menuDeVentas();

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
        cout << "\n\tListar Productos               [2]\n";
        cout << "\n\tModificar Productos	          [3]\n";
        cout << "\n\tEliminar Productos			        [4]\n";
        cout << "\n\tSalir                          [5]\n";
        cout << "\n\tIngresar una opcion            [1-5]: ";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); agregarProductos(); break;
        case 2: system("cls"); listarProductos(); break;
        case 3: system("cls"); modificarProductos(); break;
        case 4: system("cls"); eliminarProductos(); break;
        case 5:	cout << "\n\n\n\t\t--------Gracias por tu visita--------\n";
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
        objProducto.setCodigo(codigo);
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
        cout << "\tCodigo: " << vectorProductos.get(i).getCodigo() << endl;
        cout << "\tNombre: " << vectorProductos.get(i).getNombre() << endl;
        cout << "\tPrecio: " << vectorProductos.get(i).getPrecio() << endl;
        cout << "\tStock: " << vectorProductos.get(i).getStock() << endl;
        cout << "\t*************************************" << endl;
    }

    system("pause");
    system("cls");

}

void modificarProductos()
{
    int codigo;
    cout << "Ingrese el codigo a buscar: ";
    cin >> codigo;
    Producto objModificar = vectorProductos.buscaPorCodigo(codigo);

    cout << "\t\t*************************************\n";

    cout << "\t\t|||||| Registro encontrado... ||||||\n";
    cout << "\n\tCodigo (" << objModificar.getCodigo() << ")\n";
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
    cout << "\n\tCodigo (" << objBuscar.getCodigo() << ")\n";
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
