#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Admin.h"
using namespace std;

class AdminVector
{
private:
	vector<Admin> vectorAdmin;

public:
	AdminVector()
	{
		vector<Admin> vectorAdmin;
		cargarDatosDelArchivoAlVector();
		

	};

	void add(Admin obj)
	{
		vectorAdmin.push_back(obj);
	}
	bool getValidacionAdmin(Admin obj)
	{
		for (int i = 0; i < vectorAdmin.size(); i++)
		{
			if (obj.getUsuario() == vectorAdmin[i].getUsuario() && obj.getContrasena() == vectorAdmin[i].getContrasena())
			{
				return true;
			}

		}
		return false;
	}

	int getCorrelativoCodigo()
	{
		if (vectorAdmin.size() == 0) {
			return 1;
		}
		else
		{
			return vectorAdmin[vectorAdmin.size() - 1].getIdCodigo() + 1;
		}
	}

	void grabarEnArchivoAdmin(Admin a)
	{
		try
		{
			fstream archivoAdmin;
			archivoAdmin.open("archivoAdmin.txt", ios::app);

			if (archivoAdmin.is_open())
			{
				archivoAdmin << a.getIdCodigo() << ";" << a.getUsuario() << ";" << a.getContrasena() << ";" << endl;
				archivoAdmin.close();
			}
		}
		catch (exception e)
		{
			cout << "Error";
		}
	}

	//Validar si el vector esta vacio
	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			string linea;
			size_t posi;
			string temporal[3];
			fstream archivoAdmin;

			archivoAdmin.open("archivoAdmin.txt", ios::in);
			if (archivoAdmin.is_open())
			{
				while (!archivoAdmin.eof())
				{
					while (getline(archivoAdmin, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}

						Admin objAdmin;
						objAdmin.setIdCodigo(std::stoi(temporal[0]));
						objAdmin.setUsuario(temporal[1]);
						objAdmin.setContrasena(temporal[2]);

						add(objAdmin);
					}
				}
			}
			archivoAdmin.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un problema al momento de leer el archivo!!!";
		}
	}

	bool validacionVectorVacio()
	{
		if (vectorAdmin.size() == 0)
		{
			return true;
		}
		else {
			return false;
		}
		
		
	}

};
