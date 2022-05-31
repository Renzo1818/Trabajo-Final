#include <iostream>
using namespace std;
class Admin
{
  private:
    int idCodigo;
    string usuario;
    int contrasena;
  public:
  Admin(int id_, string usua_, int contra_){
    idCodigo = id_;
    usuario = usua_;
    contrasena = contra_;
    
  Admin();
  ~Admin();
}
//get
int getIdCodigo(){
  return idCodigo;
}
string getUsuario(){
  return usuario;
}
int getContrasena(){
  return contrasena;
}


};
