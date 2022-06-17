#pragma once
#include <iostream>
using namespace std;
class Admin
{
private:
    int idCodigo;
    string usuario;
    string contrasena;
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
    void setContrasena(string valor)
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
    string getContrasena()
    {
        return contrasena;
    }

};
