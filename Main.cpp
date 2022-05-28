#include <iostream>
#include <string>
#include <cstdlib>

#define USER "Renzo"
#define PASS "123456789"
using namespace std;

int main()
{
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
    }


}
