#pragma once
#include <iostream>
#include <string>
using namespace std;
class Vendedor
{
private:
    int codVendedor;
    string usuario;
    string contrasena;

public:
    Vendedor()
    {

    }

    void setCodVendedor(int cod)
    {
        codVendedor = cod;
    }

    void setUsuario(string usu)
    {
        usuario = usu;
    }

    void setContrasena(string contra)
    {
        contrasena = contra;
    }

    int getCodVendedor()
    {
        return codVendedor;
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
