#pragma once
#include<iostream>
#include "Producto.h"
using namespace std;

class DetalleVenta: public Producto{
private:
    int codVenta;
    int cantidad;

public:
    DetalleVenta(int cod, string nom, float precio_, int stock_, int codVenta_, int cantidad_): 
        Producto(cod, nom, precio_, stock_) {
       codVenta = codVenta_;
       cantidad = cantidad_;

    }
    DetalleVenta() {

    }
    //Set
    void setCodVenta(int valor) {
        codVenta = valor;
    }
    void setCantidad(int valor) {
        cantidad = valor;
    }
    //Get
    int getCodVenta() {
        return codVenta;
    }
    int getCantidad() {
        return cantidad;
    }
    //Metodos

    float getImporte() {
        return getCantidad() * getPrecio();
    }
};
