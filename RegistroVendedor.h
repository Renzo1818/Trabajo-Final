#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include"Vendedor.h"
using namespace std;

class VendedorVector
{
private:
	vector<Vendedor> vectorVendedor;

public:
	VendedorVector()
	{
		vector<Vendedor> vectorVendedor;
		cargarDatosDelArchivoAlVector();

	}

	void add(Vendedor obj)
	{
		vectorVendedor.push_back(obj);
	}

	int rows() {
		return vectorVendedor.size();
	}

	Vendedor get(int pos) {
		return vectorVendedor[pos];
	}

	bool getValidacionVendedor(Vendedor obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getUsuario() == vectorVendedor[i].getUsuario() && obj.getContrasena() == vectorVendedor[i].getContrasena())
			{
				return true;
			}

		}
		return false;
	}


	int getCorrelativoCodigo()
	{
		if (rows() == 0) {
			return 1;
		}
		else
		{
			return vectorVendedor[vectorVendedor.size() - 1].getCodVendedor() + 1;
		}
	}

	Vendedor buscaPorCodigo(int codigo)
	{
		Vendedor objError;
		objError.setUsuario("Error");
		for (int i = 0; i < rows(); i++)
		{
			if (codigo == get(i).getCodVendedor())
			{
				return get(i);
			}
		}
		return objError;
	}



	void remove(Vendedor obj)
	{
		vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));

	}


	int getPostArray(Vendedor obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodVendedor() == get(i).getCodVendedor())
			{
				return i;
			}
		}
		return -1;
	}


	bool modificar(Vendedor obj, string usu, string contra)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodVendedor() == get(i).getCodVendedor())
			{
				vectorVendedor[i].setUsuario(usu);
				vectorVendedor[i].setContrasena(contra);
				return true;
			}
		}
		return false;
	}


	void grabarModificarEliminarArchivo()
	{
		try
		{
			fstream archivoVendedor;
			archivoVendedor.open("archivoVendedor.txt", ios::out);
			if (archivoVendedor.is_open())
			{
				for (Vendedor x : vectorVendedor)
				{
					archivoVendedor << x.getCodVendedor() << ";" << x.getUsuario() << ";" << x.getContrasena() << ";" << endl;
				}
				archivoVendedor.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo";
		}
	}

	void grabarEnArchivoVendedor(Vendedor v)
	{
		try
		{
			fstream archivoVendedor;
			archivoVendedor.open("archivoVendedor.txt", ios::app);

			if (archivoVendedor.is_open())
			{
				archivoVendedor << v.getCodVendedor() << ";" << v.getUsuario() << ";" << v.getContrasena() << ";" << endl;
				archivoVendedor.close();
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
			string temporal[3];
			fstream archivoVendedor;
			archivoVendedor.open("archivoVendedor.txt", ios::in);
			if (archivoVendedor.is_open())
			{
				while (!archivoVendedor.eof())
				{
					while (getline(archivoVendedor, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;

						}
						//Crear un Objeto de tipo Alumno
						Vendedor objVendedor;
						objVendedor.setCodVendedor(std::stoi(temporal[0]));
						objVendedor.setUsuario(temporal[1]);
						objVendedor.setContrasena(temporal[2]);

						add(objVendedor);

					}
				}

			}
			archivoVendedor.close();
		}
		catch (exception e) {
			cout << "Ocurrio un problema al momento de leer el archivo!!!";
		}
	}
};
