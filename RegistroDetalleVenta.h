#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "DetalleVenta.h"

using namespace std;

class DetalleVentaVector
{
private:
    vector<DetalleVenta> vectorDetalleVenta;

public:
    DetalleVentaVector()
    {
        vector<DetalleVenta>vectorDetalleVenta;
        cargarDatosDelArchivoAlVector();

    }
    void add(DetalleVenta obj)
    {
        vectorDetalleVenta.push_back(obj);
    }

    int rows() {
        return vectorDetalleVenta.size();
    }

    DetalleVenta get(int pos)
    {
        return vectorDetalleVenta[pos];
    }


    int getPostArray(DetalleVenta obj)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (obj.getCodVenta() == get(i).getCodVenta())
            {
                return i;
            }
        }
        return -1;
    }

    DetalleVenta buscaPorCodigo(int codigo)
    {
        DetalleVenta objError;
        objError.setCodVenta(0);
        for (int i = 0; i < rows(); i++)
        {
            if (codigo == get(i).getCodVenta())
            {
                return get(i);
            }
        }
        return objError;
    }

    void listarDetallesVentas(int codigo)
    {
        for (int i = 0; i < rows(); i++) {
            if (codigo == get(i).getCodVenta())
            {
                cout << "\n\tCodigo Producto :" << get(i).getCodProducto() << endl;
                cout << "\n\tNombre Producto: " << get(i).getNombre() << endl;
                cout << "\n\tCantidad: " << get(i).getCantidad() << endl;
                cout << "\n\tPrecio: " << get(i).getPrecio() << endl;
                cout << "\n\t--------------------------------\n";
            }
        }
    }


    void grabarEnArchivoDetalleVenta(DetalleVenta a)
    {
        try
        {
            fstream archivoDetalleVenta;
            archivoDetalleVenta.open("archivoDetalleVenta.txt", ios::app);

            if (archivoDetalleVenta.is_open())
            {
                archivoDetalleVenta << a.getCodVenta() << ";" << a.getCodProducto() << ";" << a.getCantidad() << ";" << a.getImporte() << ";" << endl;
                archivoDetalleVenta.close();
            }
        }
        catch (exception e)
        {
            cout << "Error";
        }
    }

    void cargarDatosDelArchivoAlVector()
    {
        try
        {
            int i;
            string linea;
            size_t posi;
            string temporal[4];
            fstream archivoDetalleVenta;

            archivoDetalleVenta.open("archivoDetalleVenta.txt", ios::in);
            if (archivoDetalleVenta.is_open())
            {
                while (!archivoDetalleVenta.eof())
                {
                    while (getline(archivoDetalleVenta, linea))
                    {
                        i = 0;
                        while ((posi = linea.find(";")) != string::npos)
                        {
                            temporal[i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }

                        DetalleVenta objDetalle;
                        objDetalle.setCodVenta(std::stoi(temporal[0]));
                        objDetalle.setCodProducto(std::stoi(temporal[1]));
                        objDetalle.setCantidad(std::stoi(temporal[2]));
                        objDetalle.setPrecio(std::stoi(temporal[3]));

                        add(objDetalle);
                    }
                }
            }
            archivoDetalleVenta.close();
        }
        catch (exception e)
        {
            cout << "Ocurrio un problema al momento de leer el archivo!!!";
        }
    }
};
