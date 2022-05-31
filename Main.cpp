#include <iostream>
#include <string>
#include<vector>
#include "RegistroVendedor.h"
using namespace std;
//Crear Objeto CLASE VendedorVector
VendedorVector vendedorVector;
//Prototipos
void menuDeOpcionesGeneral();
void loginAdmin();
void menuAdmin();
void loginVendedor();
void ingresarSistema();
void registroSistema();


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
		cout<<"\t\tMENU DE OPCIONES GENERALES\n";
		cout<<"Ingresar como Administrador	[1]\n";
		cout<<"Ingresar como vendedor	      [2]\n";
		cout<<"Salir					              [3]\n";
		cout<<"Ingrese una opcion [1-3]:";
		cin>>opt;
		switch(opt)
		{
			case 1:	system("cls");loginAdmin();break;
			case 2: system("cls");loginVendedor();break;
			case 3:	cout<<"\t\t###########Gracias por tu visita##########\n";
					exit(0);
					break;
			default:cout<<"Ingrese una opcion correcta[1-3]"<<endl;
		}
	}
	while(opt!=3);
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
        system("cls");
        cout << "\t\tLogin de Usuario" << endl;
        cout << "\t\t----------------" << endl;
        cout << "\n\tUsuario:"; getline(cin, usuario);
        cout << "\n\tPassword:"; getline(cin, password);
        // comparacion para saber si el usuario es correcto
        if (usuario == USER && password == PASS)
        {
            ingresa = true;
        }
        else 
        {
            cout << "\n\tEl usuario y/o password son incorrectos";
            contador++;
        }
    } while (ingresa == false && contador < 3);
    
    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. Intentelo mas tarde" << endl;
    }
    else 
    {
      cout << "Bienvenido al Sistema" << endl;
      menuAdmin();   
    }
}

void loginVendedor()
{
  //Declarar Variables
	int opt;
	do
	{
		cout<<"\t\tMENU DE OPCIONES\n";
		cout<<"Registrarse en el sistema   [1]\n";
		cout<<"Ingresar al sistema         [2]\n";
		cout<<"Salir					             [3]\n";
		cout<<"Ingrese una opcion [1-3]:";
		cin>>opt;
		switch(opt)
		{
			case 1:	system("cls");registroSistema();break;
			case 2: system("cls");ingresarSistema();break;
			case 3:	cout<<"\t\t###########Gracias por tu visita##########\n";
					exit(0);
					break;
			default:cout<<"Ingrese una opcion correcta [1-3]"<<endl;
		}
	}
	while(opt!=3);
}

void registrarSistema()
{
  int cod;
  string usuario;
  string contrasena;

  cout<<"|| REGISTRO DE USUARIO ||"<<"\n";
  cod = vendedorVector.getCorrelativoCodigo();
	cout << "Codigo(" << cod << ")" << endl;
  cout<<"Ingresar Usuario: ";
  getline(cin, usuario);

  cout<<"Ingresar Contraseña: ";
  getline(cin, contrasena);
  cin.ignore();

  Vendedor objVendedor;
  objVendedor.setCodigo(cod);
  objVendedor.setUsuario(usuario);
  objVendedor.setContrasena(contrasena);

  vendedorVector.add(objVendedor);
  vendedorVector.grabarEnArchivoVendedor(objVendedor);
  system("cls");
}

void ingresarSistema()
{
  int cod;
  string usuario;
  string contrasena;
  int pos;
  
  cout<<"|| LOGIN DE USUARIO ||"<<"\n";
  
  cout<<"Ingresar Codigo: ";
  cin>>cod;
  
  cout<<"Ingresar Usuario: ";
  getline(cin, usuario);

  cout<<"Ingresar Contraseña: ";
  getline(cin, contrasena);
  cin.ignore();

  Vendedor objValidacion;
  objValidacion.setCodigo(cod);
  objValidacion.setUsuario(usuario);
  objValidacion.setContrasena(contrasena);

  pos = vendedorVector.getPosArray(objValidacion);
  
  for(int i=0)
  
}
