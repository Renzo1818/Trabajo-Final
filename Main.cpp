#include <iostream>
#include <string>
#include<vector>
#include "RegistroVendedor.h"
using namespace std;
//Globale


//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
//Prototipos
void menuDeOpcionesGeneral();
void loginAdmin();
//void menuAdmin();
void loginVendedor();
void ingresarSistema();
void registroSistema();
//void menuDeVentas();


void menuVendedor();

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
        cout << "Ingrese una opcion [1-3]:";
        cin >> opt;
        switch (opt)
        {
        case 1:	system("cls"); loginAdmin(); break;
        case 2: system("cls"); loginVendedor(); break;
        case 3:	cout << "\t\t###########Gracias por tu visita##########\n";
            exit(0);
            break;
        default:cout << "Ingrese una opcion correcta[1-3]" << endl;
        }
    } while (opt != 3);
}


void loginAdmin()
{
#define USER "Pepe"
#define PASS "12345"

    string usuario;
    string password;
    int contador = 0;
    bool ingresa = false;

    do
    {
        cout << "\t\tLogin de Usuario" << endl;
        cout << "\t\t----------------" << endl;
        cin.ignore();
        cout << "\n\tUsuario:";
        cin >> usuario;
        cout << "\n\tPassword:";
        cin>>password;

        // comparacion para saber si el usuario es correcto
        if (usuario == USER && password == PASS)
        {
            ingresa = true;
            break;
        }
        else
        {
            contador++;
            cout << "\n\tEl usuario y/o password son incorrectos" << endl;
            system("pause");
            system("cls");
        }
    } while (ingresa == false && contador < 3);

    if (ingresa == true)
    {
        system("cls");
        cout << "Bienvenido al Sistema" << endl;
        //menuAdmin();
        exit(0);

        
    }
    else
    {
        system("cls");
        cout << "\n\tUsted no pudo ingresar al sistema. Intentelo mas tarde" << endl;
        system("pause");
        exit(0);
    }
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
    bool validacion = false;
    int cont = 0;

    do
    {
        cout << "|| LOGIN DE USUARIO ||" << "\n";
        cin.ignore();
        cout << "Ingresar Usuario: ";
        cin>> usuario;
        cout << "Ingresar Contraseña: ";
        cin>> contrasena;

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
            cout << "No pudo ingresar, intentelo mas tarde";
            system("pause");
        }


    } while (validacion = false && cont < 3);

    



}

