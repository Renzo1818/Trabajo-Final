#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include "Venta.h"

using namespace std;

class VentaVector
{
private:
    vector<Venta> vectorVenta;

public:
    VentaVector()
    {
        vector<Venta> vectorVenta;
        cargarDatosDelArchivoAlVector();

    }
    void add(Venta obj)
    {
        vectorVenta.push_back(obj);
    }

    int rows()
    {
        return vectorVenta.size();
    }


    Venta get(int pos)
    {
        return vectorVenta[pos];
    }


    int getCorrelativoCodigo()
    {
        if (rows() == 0)
        {
            return 100;
        }
        else
        {
            return vectorVenta[vectorVenta.size() - 1].getCodVenta() + 200;
        }
    }



    Venta buscaPorCodigo(int codigo)
    {
        Venta objError;
        objError.setCodVenta(-1);
        for (int i = 0; i < rows(); i++)
        {
            if (codigo == get(i).getCodVenta())
            {
                return get(i);
            }
        }
        return objError;
    }

    int getPostArray(Venta obj)
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


    bool modificarEstado(int codV, string est)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (codV == get(i).getCodVenta())
            {
                vectorVenta[i].setEstado(est);

                return true;
            }
        }
        return false;
    }

    float GetCierreCaja(string fecha)
    {
        float acumulador = 0;
        for (int i = 0; i < rows(); i++)
        {
            if (fecha == get(i).getFecha())
            {
                acumulador += get(i).getTotal();
            }
        }
        return acumulador;
    }


    void grabarModificarArchivo()
    {
        try
        {
            fstream archivoVenta;
            archivoVenta.open("archivoVenta.txt", ios::out);
            if (archivoVenta.is_open())
            {
                for (Venta x : vectorVenta)
                {
                    archivoVenta << x.getCodVenta() << ";" << x.getCodVendedor() << ";" << x.getFecha() << ";" << x.getDni() << ";" << x.getRuc() << ";" << x.getSubTotal() << ";" << x.getTotal() << ";" <<
                        x.getEstado() << ";" << x.getTipoVenta() << ";" << endl;
                }
                archivoVenta.close();
            }
        }
        catch (exception e)
        {
            cout << "Ocurrio un error al grabar en el archivo";
        }
    }

    void grabarEnArchivoVenta(Venta x)
    {
        try
        {
            fstream archivoVenta;
            archivoVenta.open("archivoVenta.txt", ios::app);

            if (archivoVenta.is_open())
            {
                archivoVenta << x.getCodVenta() << ";" << x.getCodVendedor() << ";" << x.getFecha() << ";" << x.getDni() << ";" << x.getRuc() << ";" << x.getSubTotal() << ";" <<
                    x.getTotal() << ";" << x.getEstado() << ";" << x.getTipoVenta() << ";" << endl;
                archivoVenta.close();
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
            string temporal[9];
            fstream archivoVenta;

            archivoVenta.open("archivoVenta.txt", ios::in);
            if (archivoVenta.is_open())
            {
                while (!archivoVenta.eof())
                {
                    while (getline(archivoVenta, linea))
                    {
                        i = 0;
                        while ((posi = linea.find(";")) != string::npos)
                        {
                            temporal[i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }

                        Venta objVenta;
                        objVenta.setCodVenta(std::stoi(temporal[0]));
                        objVenta.setCodVendedor(std::stoi(temporal[1]));
                        objVenta.setFecha(temporal[2]);
                        objVenta.setDni(temporal[3]);
                        objVenta.setRuc(temporal[4]);
                        objVenta.setSubTotal(std::stoi(temporal[5]));
                        objVenta.setTotal(std::stoi(temporal[6]));
                        objVenta.setEstado(temporal[7]);
                        objVenta.setTipoVenta(temporal[8]);

                        add(objVenta);
                    }
                }
            }
            archivoVenta.close();
        }
        catch (exception e)
        {
            cout << "Ocurrio un problema al momento de leer el archivo!!" << endl;
        }
    }
};
