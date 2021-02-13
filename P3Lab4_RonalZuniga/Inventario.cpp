#include "Inventario.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

Inventario::Inventario() {
}

Inventario::~Inventario() {
	for(int i = 0; i < productos.size(); i++) {
		delete productos[i];
	}
}

Inventario::Inventario(vector<Producto*> _productos) {
	this->productos = _productos;
}

void Inventario::agregarProducto(Producto* producto) {
	if(productos.empty()) {
		productos.push_back(producto);
	} else {
		bool contiene;
		for (int i = 0; i < productos.size(); i++) {
			Producto* p = (productos[i]);
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
			if(categorias.empty()) {
				categorias.push_back(producto->getCategoria());
			} else {
				bool b = validarCateg(producto->getCategoria());
				if(b) {

				} else {
					categorias.push_back(producto->getCategoria());
				}
			}
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
				Producto* p = (productos[i]);
				if((p->getId() == _id)) {
					posicion = i;
					i = productos.size();
				}
			}//fin primer for
			for (int i = 0; i < productos.size(); i++) {
				Producto* p = (productos[i]);
				if((p->getId() == idNuevo)) {
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
				Producto* p = (productos[i]);
				if((p->getId() == _id)) {
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
				Producto* p = (productos[i]);
				if((p->getId() == _id)) {
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
				Producto* p = (productos[i]);
				if((p->getId() == _id)) {
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
				Producto* p = (productos[i]);
				if((p->getId() == _id)) {
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

void Inventario::eliminarProducto(int _id) {
	bool flag;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		if((p->getId() == _id)) {
			productos.erase(productos.begin() + i);
			delete p;
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
}//fin metodo eliminar

bool Inventario::validarCateg(string _categoria) {
	bool categ;
	for (int i = 0; i < categorias.size(); i++) {
		string c = categorias[i];
		if (c.compare(_categoria) == 0) {
			categ = true;
			i = categorias.size();
		} else {
			categ = false;
		}
	}
	return categ;
}

float Inventario::precioInventario() {
	float total = 0;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		total += p->getPrecio();
	}
	return total;
}

float Inventario::precioCategoria(string _categoria) {
	float tCateg = 0;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		if(p->getCategoria().compare(_categoria) == 0) {
			tCateg += p->getPrecio();
		}
	}
	return tCateg;
}

int Inventario::productosCategoria(string _categoria) {
	int prodCateg = 0;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		if(p->getCategoria().compare(_categoria) == 0) {
			prodCateg++;
		}
	}
	return prodCateg;
}

int Inventario::totalUnidades() {
	int unidades = 0;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		unidades += p->getCantidad();
	}
	return unidades;
}

vector<string> Inventario::productosUnicos() {
	vector<string> pUnicos;
	for(int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		if(pUnicos.empty()) {
			pUnicos.push_back(p->getNombre());
		} else {
			bool flag;
			for (int x = 0; x < pUnicos.size(); x++) {
				string s = pUnicos[i];
				if(s.compare(p->getNombre()) == 0) {
					flag = true;
					x = pUnicos.size();
				} else {
					flag = false;
				}
			}
			if(flag) {

			} else {
				pUnicos.push_back(p->getNombre());
			}
		}
	}
	return pUnicos;
}

void Inventario::estadisticasGenerales() {
	cout << "----Productos----" << endl;
	for (int i = 0; i < productos.size(); i++) {
		Producto* p = (productos[i]);
		cout << "Id: " << p->getId() << endl;
		cout << "Nombre: " << p->getNombre() << endl;
		cout << "Cantidad: " << p->getCantidad() << endl;
		cout << "Categoria: " << p->getCategoria() << endl;
		cout << "Precio: " << p->getPrecio() << endl;
		cout << endl;
		cout << endl;
	}
	cout << "Total de Unidades: " << totalUnidades() << endl;
	cout << "Total de Productos Unicos: " << productosUnicos().size() << endl;
	cout << "Precio Total del Inventario: " << precioInventario() << endl;
	cout << "Total de Productos por Categoria" << endl;
	for (int j = 0; j < categorias.size(); j++) {
		cout << categorias[j] << ": " << productosCategoria(categorias[j]) << endl;
	}
	cout << endl;
	cout << "Precio Total de Productos por Categoria" << endl;
	for (int k = 0; k < categorias.size(); k++) {
		cout << categorias[k] << ": " << precioCategoria(categorias[k]) << endl;
	}
	cout << endl;
	cout << endl;
}

Inventario* Inventario::busqueda(string nBuscar) {
	Inventario* inv = new Inventario();
	cout << "----------------------------------------" << endl;
	cout << "BUSQUEDA" << endl;
	char buscar[80];
	for (int y = 0; y < 80; y++) {
		buscar[y] = nBuscar[y];
	}
	for (int i = 0; i < productos.size(); i++) {
		char cadena[80];
		string cad = productos[i]->getNombre();
		for (int x = 0; x < 80; x++) {
			cadena[x] = cad[x];
		}
		if(strstr(cadena, buscar)) {
			inv->agregarProducto(productos[i]);
		} else {
			cout << "NO se ha encontrado " << buscar << endl;
		}
	}
	return inv;
}




