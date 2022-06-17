#pragma once
#include<iostream>
#include "Venta.h"

using namespace std;

class DetalleVenta : public Venta {
private:
    int codVenta;//Hacer sobrecarga
    int codProducto; //Hacer sobrecarga
    int cantidad;
    float precioVenta;
public:
    /*DetalleVenta() : Venta() {

    }*/
    float getImporte() {
        return cantidad * precioVenta;
    }
};
