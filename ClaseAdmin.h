#pragma once
#include <iostream>
using namespace std;
class Admin
{
private:
    int idCodigo;
    string usuario;
    int contrasena;
public:

    Admin()
    {

    }

    //sets
    void setIdCodigo(int valor)
    {
        idCodigo = valor;
    }
    void setUsuario(string valor)
    {
        usuario = valor;
    }
    void setContrasena(int valor)
    {
        contrasena = valor;
    }
    //Get
    int getIdCodigo()
    {
        return idCodigo;
    }
    string getUsuario()
    {
        return usuario;
    }
    int getContrasena()
    {
        return contrasena;
    }

};
