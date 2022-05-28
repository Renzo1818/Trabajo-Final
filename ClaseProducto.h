#include <iostream>
#include <string>
using namespace std;

class ClaseProducto
{
private:
    int codigo;
    string nombre;
    float precio;
    int stock;
public:
    ClaseProducto(int cod, string nom, float pre, int stck)
    {
        codigo = cod;
        nombre = nom;
        precio = pre;
        stock = stck;
    }
    ClaseProducto();
    ~ClaseProducto();

    //set
    void setCodigo(int valor)
    {
        codigo = valor;
    }
    void setNombre(string valor)
    {
        nombre = valor;
    }
    void setPrecio(float valor)
    {
        precio = valor;
    }
    void setStock(int valor)
    {
        stock = valor;
    }
    //get
    int getCodigo()
    {
        return codigo;
    }
    string getNombre()
    {
        return nombre;
    }
    float getPrecio()
    {
        return precio;
    }
    int getStock()
    {
        return stock;
    }

};


