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
	}

	void agregar(Vendedor obj)
	{
		vectorVendedor.push_back(obj);
	}

	int rows() { //Cantidad de filas
		return vectorVendedor.size();
	}

	int getPosArray(Vendedor obj) {
		for (int i = 0; i < rows(); i++) {
			if (obj.getContrasena() == vectorVendedor[i].getContrasena()) {
				return i;
			}
		}
		return -1;
	}
	Vendedor get(int pos) { //Entregar el objeto actual, segun la posicion pasada como parametro
		return vectorVendedor[pos];
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
