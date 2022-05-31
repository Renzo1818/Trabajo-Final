#include <iostream>
#include <vector>
#include <fstream>
#include"vendedor.h"
using namespace std;

class VendedorVector
{
private:
	vector<Vendedor> vectorVendedor;

public:
	VendedorVector()
	{
		vector<Vendedor> vectorVendedor;
	}

	void add(Vendedor obj)
	{
		vectorVendedor.push_back(obj);
	}
  Vendedor get(int pos) 
  { 
		return vectorVendedor[pos];
	}

	int rows() 
  { 
		return vectorVendedor.size();
	}

	int getPosArray(Vendedor obj) 
  {
		for (int i = 0; i < rows(); i++) 
    {
			if (obj.getContrasena() == vectorVendedor[i].getContrasena() && obj.getUsuario() == vectorVendedor[i].getUsuario()) {
				return i;
			}
		}
		return -1;
	}
  

	int getCorrelativoCodigo()
	{
		if (vectorVendedor.size() == 0) {
			return 1;
		}
		else
		{
			return vectorVendedor[vectorVendedor.size() - 1].getCodigo() + 1;
		}
	}

	void grabarEnArchivoVendedor(Vendedor v)
	{
		try
		{
			fstream archivoVendedor;
			archivoVendedor.open("archivoVendedores.csv", ios::app);

			if (archivoVendedor.is_open())
			{
				archivoVendedor << v.getCodigo() << ";" << v.getUsuario() << ";" << v.getContrasena() << endl;
				archivoVendedor.close();
			}
		}
		catch (exception e)
		{
			cout << "Error";
		}
	}

};
