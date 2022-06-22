#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto
{
private:
    int codProducto;
    string nombre;
    float precio;
    int stock;

public:
    Producto(int cod, string nom, float precio_, int stock_) {
        codProducto = cod;
        nombre = nom;
        precio = precio_;
        stock = stock_;
    }
    Producto() {

    }
    //set
    void setCodProducto(int valor)
    {
        codProducto = valor;
    }
    void setNombre(string valor)
    {
        nombre = valor;
    }
    void setPrecio(float valor)
    {
        precio = valor;
    }
    void setStock(int valor)
    {
        stock = valor;
    }
    //get
    int getCodProducto()
    {
        return codProducto;
    }
    string getNombre()
    {
        return nombre;
    }
    float getPrecio()
    {
        return precio;
    }
    int getStock()
    {
        return stock;
    }

};
