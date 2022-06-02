#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib>
#include "RegistroVendedor.h"
#include "RegistroAdmin.h"
using namespace std;
//Globale

//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
//Prototipos
void menuDeOpcionesGeneral();
void loginAdmin();
void IngresoAdmin();
void registroAdmin();
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


void IngresoAdmin()
{
  bool validacion = false;
  validacion = ValidacionArchivo();
  if (valdacion == true)
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
    contrasena = (rand()%89999999) + 10000000;
    cout << "Contrasena Generada: " << contrasena;

      Admin objA;
        objA.setIdCodigo(cod);
        objA.setUsuario(usuario);
        objA.setContrasena(contrasena);

    vendedorAdmin.add(objA);
    vectorAdmin.grabarEnArchivoAdmin(objA);
    system("cls");

    LoginAdmin();
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
    cin>> usuario;
    cout << "Ingresar Contraseña: ";
    caracter = _getch();

    contrasena = "";
    while(caracter != 13)
    {
      if(caracter != 8)
      {
        contrasena.push_back(caracter);
        cout<<"*";
      }
      else
      {
        if(contrasena.length() > 0)
        {
          cout<<"\b \b";
          contrasena = contrasena.substr(0, contrasena.length() -1);
        }
      }
      caracter = _getch(); 
    }
    //cin>> contrasena;
    Admin objAdmin;
      objAdmin.setUsuario(usuario);
      objAdmin.setContrasena(contrasena);

      validacion = vendedorAdmin.getValidacionAdmin(objAdmin);


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
    cin>> usuario;
    cout << "Ingresar Contraseña: ";
    caracter = _getch();

    contrasena = "";
    while(caracter != 13)
    {//Para que siga apereciendo los asteristos hasta que pulsemos enter
      if(caracter != 8)
      {//Para que siga apereciendo los asteristos apesar de borrar
        contrasena.push_back(caracter);
        cout<<"*";
        }
          else{
            if(contrasena.length() > 0){
              cout<<"\b \b";
              contrasena = contrasena.substr(0, contrasena.length() -1);
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

