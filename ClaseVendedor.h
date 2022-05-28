#include <iostream>
#include <string>
using namespace std;
class Vendedor
{
private:
  int codigo;
  string usuario;
  string contrasena;

public:
  Vendedor(int cod, string usu, string contra)
  {
    codigo = cod;
    usuario = usu;
    contrasena = contra;
  }

  ~Vendedor()
  {
    
  }

  
  void setCodigo(int cod)
  {
    codigo = cod;
  }

  void setUsuario(string usu)
  {
    usuario = usu;
  }

  void setContrasena(string contra)
  {
    contrasena = contra;
  }

  int getCodigo()
  {
    return codigo;
  }

  string getUsuario()
  {
    return usuario;
  }

  string getContrasena()
  {
    return contrasena;
  }

};