#include <iostream>
#include <vector>
#include <fstream>
#include"ClaseVendedor.h"
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

  int getCorrelativoCodigo() 
    {
      if(vectorVendedor.size()==0){
        return 1;
      }
      else
      {
        return vectorVendedor[vectorVendedor.size()-1].getCodigo()+1;
      }
    }


  void agregar(Vendedor obj)
		{
			vectorVendedor.push_back(obj);
		}


  void grabarEnArchivoVendedor(Vendedor v)
		{
			try
			{
				fstream archivoVendedor;
				archivoVendedor.open("archivoVendedores.csv",ios::app);
        
				if(archivoVendedor.is_open())
				{
					archivoVendedor<<v.getCodigo()<<";"<<v.getUsuario()<<";"<<v.getContrasena()<<endl;
					archivoVendedor.close();
				}
			}			
			catch(exception e)
			{
				cout<<"Error";
			}
		}

};
