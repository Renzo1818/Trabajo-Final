#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include "Producto.h"

using namespace std;

class ProductoVector
{
private:
    vector<Producto> vectorProducto;

public:
    ProductoVector()
    {
        vector<Producto>VectorProducto;
        cargarDatosDelArchivoAlVector();

    }
    void add(Producto obj)
    {
        vectorProducto.push_back(obj);
    }
    int rows() {
        return vectorProducto.size();
    }

    bool getValidacionCodigo(Producto obj)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (obj.getCodigo() == vectorProducto[i].getCodigo())
            {
                return true;
            }
        }
        return false;
    }

    Producto get(int pos)
    {
        return vectorProducto[pos];
    }

    int getCorrelativoCodigo()
    {
        if (rows() == 0)
        {
            return 1;
        }
        else
        {
            return vectorProducto[vectorProducto.size() - 1].getCodigo() + 1;
        }
    }

    void remove(Producto obj) {
        vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));

    }

    Producto buscaPorCodigo(int codigo)
    {
        Producto objError;
        objError.setNombre("Error");
        for (int i = 0; i < rows(); i++)
        {
            if (codigo == get(i).getCodigo())
            {
                return get(i);
            }
        }
        return objError;
    }

    int getPostArray(Producto obj)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (obj.getCodigo() == get(i).getCodigo())
            {
                return i;
            }
        }
        return -1;
    }


    bool modificar(Producto obj, string nom, float precio, int stock)
    {
        for (int i = 0; i < rows(); i++)
        {
            if (obj.getCodigo() == get(i).getCodigo())
            {
                vectorProducto[i].setNombre(nom);
                vectorProducto[i].setPrecio(precio);
                vectorProducto[i].setStock(stock);
                return true;
            }
        }
        return false;
    }


    void grabarModificarEliminarArchivo()
    {
        try
        {
            fstream archivoProducto;
            archivoProducto.open("archivoProducto.txt", ios::out);
            if (archivoProducto.is_open())
            {
                for (Producto x : vectorProducto)
                {
                    archivoProducto << x.getCodigo() << ";" << x.getNombre() << ";" << x.getPrecio() << ";" << x.getStock() << ";" << endl;
                }
                archivoProducto.close();
            }
        }
        catch (exception e)
        {
            cout << "Ocurrio un error al grabar en el archivo";
        }
    }



    void grabarEnArchivoProducto(Producto v)
    {
        try
        {
            fstream archivoProducto;
            archivoProducto.open("archivoProducto.txt", ios::app);

            if (archivoProducto.is_open())
            {
                archivoProducto << v.getCodigo() << ";" << v.getNombre() << ";" << v.getPrecio() << ";" << v.getStock() << ";" << endl;
                archivoProducto.close();
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
            fstream archivoProducto;

            archivoProducto.open("archivoProducto.txt", ios::in);
            if (archivoProducto.is_open())
            {
                while (!archivoProducto.eof())
                {
                    while (getline(archivoProducto, linea))
                    {
                        i = 0;
                        while ((posi = linea.find(";")) != string::npos)
                        {
                            temporal[i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }

                        Producto objProducto;
                        objProducto.setCodigo(std::stoi(temporal[0]));
                        objProducto.setNombre(temporal[1]);
                        objProducto.setPrecio(std::stoi(temporal[2]));
                        objProducto.setStock(std::stoi(temporal[3]));

                        add(objProducto);
                    }
                }
            }
            archivoProducto.close();
        }
        catch (exception e)
        {
            cout << "Ocurrio un problema al momento de leer el archivo!!!";
        }
    }

};
