#pragma once
#include <iostream>
#include <string>
#include "DetalleVenta.h"

using namespace std;

class Venta {
private:
    int codVenta;
    int codVendedor;
    string fecha;
    string dni;
    string ruc;
    float subTotal;
    float IGV;
    string estado;
    string tipoVenta;
    float total;

public:
    Venta()
    {

    }
    //SET
    void setCodVenta(int valor) {
        codVenta = valor;
    }
    void setCodVendedor(int valor) {
        codVendedor = valor;
    }
    void setFecha(string valor) {
        fecha = valor;
    }
    void setDni(string valor) {
        dni = valor;
    }
    void setRuc(string valor) {
        ruc = valor;
    }
    void setSubTotal(float valor) {
        subTotal = valor;
    }
    void setIgv(float valor) {
        IGV = valor;
    }

    void setTotal(float valor) {
        total = valor;
    }

    void setEstado(string valor) {
        estado = valor;
    }
    void setTipoVenta(string valor) {
        tipoVenta = valor;
    }

    //GET
    int getCodVenta()
    {
        return codVenta;
    }

    int getCodVendedor()
    {
        return codVendedor;
    }
    string getFecha()
    {
        return fecha;
    }
    string getDni()
    {
        return dni;
    }

    string getRuc() {
        return ruc;
    }

    float getSubTotal()
    {
        return subTotal;
    }

    float getIgv()
    {
        return IGV;
    }

    string getEstado()
    {
        return estado;
    }
    string getTipoVenta() {
        return tipoVenta;
    }

    float getTotal()
    {
        return total;
    }

    //OPERACIONES
    float getsubTotalIGV()
    {
        return getSubTotal() * getIgv();
    }

};
