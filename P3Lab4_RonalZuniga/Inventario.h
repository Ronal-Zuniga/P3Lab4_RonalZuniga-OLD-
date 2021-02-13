#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "Producto.h"
#include <string>
#include <vector>

class Inventario{
	private:
		vector<Producto*> productos;
		vector<string> categorias;
	public:
		Inventario();
		~Inventario();
		Inventario(vector<Producto*>);
		void agregarProducto(Producto*);
		void modificarProducto(int);
		void eliminarProducto(int);
		Inventario* busqueda(string);
		void estadisticasGenerales();
		bool validarCateg(string);
		float precioInventario();
		float precioCategoria(string);
		int productosCategoria(string);
		int totalUnidades();
		vector<string> productosUnicos();
};
#endif
