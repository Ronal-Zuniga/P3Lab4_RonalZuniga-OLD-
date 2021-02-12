#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto{
    private:
    	int id;
        string nombre;
        int cantidad;
        string categoria;
        float precio;
    public:
        Producto(int, string, int, string, float);
        Producto();
        Producto(Producto*);
        //~Producto();

        int getId();
        void setId(int _id);
        string getNombre();
        void setNombre(string _nombre);
        int getCantidad();
        void setCantidad(int _cantidad);
        string getCategoria();
        void setCategoria(string _categoria);
        float getPrecio();
        void setPrecio(float _precio);
};
#endif
