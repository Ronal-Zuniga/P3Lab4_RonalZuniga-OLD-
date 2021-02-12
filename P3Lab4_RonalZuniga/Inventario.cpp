#include "Inventario.h"
#include <iostream>
#include <string>
using namespace std;

Inventario::Inventario(vector<Producto*> _productos) {
	this->productos = _productos;
}

void Inventario::agregarProducto(Producto* producto) {
	if(productos.empty()) {
		productos.push_back(producto);
	} else {
		bool contiene;
		for (int i = 0; i < productos.size(); i++) {
			Producto* p = new Producto (productos[i]);
			if((p->getId() == producto->getId())) {
				cout << "No se pueden agregar productos con mismo id" << endl;
				contiene = true;
				i = productos.size();
			} else {
				contiene = false;
			}
		}
		if(contiene) {
			cout << "No se ha agregado el producto" << endl;
		} else {
			productos.push_back(producto);
			cout << "Producto agregado correctamente" << endl;
		}
	}
	cout << endl;
	cout << endl;
}//fin metodo agregar

void Inventario::modificarProducto(int _id) {
	cout << "¿Que desea modificar" << endl;
	cout << "1. Id" << endl;
	cout << "2. Nombre" << endl;
	cout << "3. Cantidad" << endl;
	cout << "4. Categoria" << endl;
	cout << "5. Precio" << endl;
	cout << endl;
	cout << "Ingrese su opcion";
	int opcion;
	cin >> opcion;
	cout << endl;
	int idNuevo;
	string nombreNuevo;
	int cantNueva;
	string categNueva;
	float precioNuevo;
	switch(opcion) {
		case 1:
			cout << endl;
			cout << "Ingrese el nuevo Id del producto: ";
			bool contiene;
			int posicion;
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == _id)){
					posicion = i;
					i = productos.size();
				}
			}//fin primer for
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == idNuevo)){
					cout << "No se pueden existir productos con mismo id" << endl;
					contiene = true;
					i = productos.size();
				} else {
					contiene = false;
				}
			}//fin segundo for
			if(contiene) {
				cout << "No se ha modificado el producto" << endl;
			} else {
				productos[posicion]->setId(idNuevo);
				cout << "Producto modificado correctamente" << endl;
			}
			break;

		case 2:
			cout << endl;
			cout << "Ingrese el nuevo nombre del producto: ";
			cin >> nombreNuevo;
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == _id)){
					productos[posicion]->setNombre(nombreNuevo);
					i = productos.size();
					cout << "Producto modificado correctamente" << endl;
				}
			}
			break;

		case 3:
			cout << endl;
			cout << "Ingrese la nueva cantidad del producto: ";
			cin >> cantNueva;
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == _id)){
					productos[posicion]->setCantidad(cantNueva);
					i = productos.size();
					cout << "Producto modificado correctamente" << endl;
				}
			}
			break;

		case 4:
			cout << endl;
			cout << "Ingrese la nueva categoria del producto: ";
			cin >> categNueva;
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == _id)){
					productos[posicion]->setCategoria(categNueva);
					i = productos.size();
					cout << "Producto modificado correctamente" << endl;
				}
			}
			break;

		case 5:
			cout << endl;
			cout << "Ingrese el nuevo precio del producto: ";
			cin >> precioNuevo;
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = new Producto (productos[i]);
				if((p->getId() == _id)){
					productos[posicion]->setPrecio(precioNuevo);
					i = productos.size();
					cout << "Producto modificado correctamente" << endl;
				}
			}
			break;
	}//fin del switch
	cout << endl;
	cout << endl;
}//fin metodo modificar

void Inventario::eliminarProducto(int _id){
	bool flag;
		for (int i = 0; i < productos.size(); i++) {
			Producto* p = new Producto (productos[i]);
			if((p->getId() == _id)){
				productos.erase(productos[i]);
				flag = true;
				i = productos.size();
			} else {
				flag = false;
			}
		}
		if(flag) {
			cout << "Producto eliminado correctamente" << endl;
		} else {
			cout << "No se ha encontrado el producto" << endl;
		}
}


