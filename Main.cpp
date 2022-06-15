#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include "RegistroVendedor.h"
#include "RegistroAdmin.h"
using namespace std;

//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
AdminVector vectorAdmin;
//Prototipos
void menuDeOpcionesGeneral();
void loginAdmin();
void ingresoAdmin();
void registroAdmin();
//void menuAdmin();
void loginVendedor();
void ingresarSistema();
void registroSistema();
//void menuDeVentas();


void menuVendedor();

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
        cout << "\t\tMENU DE OPCIONES GENERALES\n";
        cout << "Ingresar como Administrador	[1]\n";
        cout << "Ingresar como vendedor	      [2]\n";
        cout << "Salir					              [3]\n";
        cout << "Ingrese una opcion           [1-3]:";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); ingresoAdmin(); break;
        case 2: system("cls"); loginVendedor(); break;
        case 3:	cout << "\t\t###########Gracias por tu visita##########\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta [1-3]" << endl;
        }
    } while (opt != 3);
}


void ingresoAdmin()
{
    bool validacion;

    validacion = vectorAdmin.validacionArchivoVacio();
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

    cout << "|| REGISTRO DE ADMIN ||" << "\n";
    cod = vectorAdmin.getCorrelativoCodigo();

    cout << "Codigo(" << cod << ")" << endl;
    cin.ignore();
    cout << "Ingresar Usuario: ";
    cin >> usuario;
    srand(time(NULL));
    contrasena = generarContrasena(8);
    cout << "Contrasena Generada: " << contrasena;

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
        cout << "|| LOGIN DE USUARIO ||" << "\n";
        cin.ignore();
        cout << "Ingresar Usuario: ";
        cin >> usuario;
        cout << "Ingresar Contraseña: ";
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
            cout << "\t\tBienvenido al sistema\n";
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
        cout << "\t\tMENU DE OPCIONES\n";
        cout << "Registrarse en el sistema   [1]\n";
        cout << "Ingresar al sistema         [2]\n";
        cout << "Salir					             [3]\n";
        cout << "Ingrese una opcion [1-3]:";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); registroSistema(); break;
        case 2: system("cls"); ingresarSistema(); break;
        case 3:	cout << "\t\t###########Gracias por tu visita##########\n";
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


    cout << "|| REGISTRO DE USUARIO ||" << "\n";
    cod = vendedorVector.getCorrelativoCodigo();

    cout << "Codigo(" << cod << ")" << endl;
    cin.ignore();
    cout << "Ingresar Usuario: ";
    cin >> usuario;
    cout << "Ingresar Contrasena: ";
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
        cout << "|| LOGIN DE USUARIO ||" << "\n";
        cin.ignore();
        cout << "Ingresar Usuario: ";
        cin >> usuario;
        cout << "Ingresar Contraseña: ";
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
            cout << "\t\tBienvenido al sistema\n";
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

