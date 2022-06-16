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
