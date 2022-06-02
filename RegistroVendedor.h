#include <iostream>
#include <vector>
#include <fstream>
#include"Vendedor.h"+
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

	int rows() { //Cantidad de filas
		return vectorVendedor.size();
	}

	Vendedor get(int pos) { //Entregar el objeto actual, segun la posicion pasada como parametro
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
			archivoVendedor.open("archivoVendedores.txt", ios::app);

			if (archivoVendedor.is_open())
			{
				archivoVendedor << v.getCodigo() << ";" << v.getUsuario() << ";" << v.getContrasena() << ";" << endl;
				archivoVendedor.close();
			}
		}
		catch (exception e)
		{
			cout << "Error";
		}
	}
	void cargarDatosDelArchivoAlVector() {
		try {
			int i;
			string linea;
			size_t posi;
			string temporal[3];
			fstream archivoVendedor;
			archivoVendedor.open("archivoVendedores.txt", ios::in);
			if (archivoVendedor.is_open())
			{
				while (!archivoVendedor.eof()) {
					while (getline(archivoVendedor,linea)) {
						i = 0;
						while ((posi = linea.find(";")) != string::npos) { //string::npos es -1,termina cuando llega a ese punto
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);	//Borra la palabra de la primera 
							i++;

						}
						//Crear un Objeto de tipo Alumno
						Vendedor objVendedor;
						objVendedor.setCodigo(std::stoi(temporal[0]));
						objVendedor.setUsuario(temporal[1]);
						objVendedor.setContrasena(temporal[2]);

						add(objVendedor);

					}
				}

			}
			archivoVendedor.close();
		}
		catch(exception e) {
			cout << "Ocurrio un problema al momento de leer el archivo!!!";
		}
		

	}
};
