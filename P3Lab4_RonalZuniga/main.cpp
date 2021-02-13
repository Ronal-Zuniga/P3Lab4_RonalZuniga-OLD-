#include <iostream>
#include "Producto.h"
#include "Inventario.h"
#include <string>
using namespace std;

int menuGeneral();
int menuProductos();

int main(int argc, char** argv) {
	int opcion;
	Inventario* inventario = new Inventario();
	while((opcion = menuGeneral()) != 4) {
		switch(opcion) {
			case 1: {
				int opcion2;
				while((opcion2 = menuProductos()) != 4) {
					switch(opcion2) {
						case 1: {
							cout << "----Agregar Producto----" << endl;
							int id, cantidad;
							string nombre, categoria;
							float precio;
							cout << "NUEVO PRODUCTO" << endl;
							cout << "Ingrese el Id: ";
							cin >> id;
							cout << endl;
							cout << "Ingrese el Nombre: ";
							cin >> nombre;
							cout << endl;
							cout << "Ingrese la Cantidad: ";
							cin >> cantidad;
							cout << endl;
							cout << "Ingrese la Categoria: ";
							cin >> categoria;
							cout << endl;
							cout << "Ingrese el Precio: ";
							cin >> precio;
							cout << endl;
							Producto* product = new Producto(id,nombre,cantidad,categoria,precio);
							inventario->agregarProducto(product);
							cout << endl;
							cout << endl;
							delete product;
						}//fin case 1
						break;

						case 2: {
							cout << "----Modificar Producto----" << endl;
							int idInicial;
							cout << "Ingrese el Id original del producto: ";
							cin >> idInicial;
							inventario->modificarProducto(idInicial);
						}//fin case 2
						break;

						case 3: {
							cout << "----Eliminar Producto----" << endl;
							int idInicial;
							cout << "Ingrese el Id original del producto: ";
							cin >> idInicial;
							inventario->eliminarProducto(idInicial);
						}//fin case 3
						break;

						case 4:
							cout << endl << endl;
							break;
					}//fin switch
				}//fin while
			}//fin case 1
			break;

			case 2: {
				cout << "----Estadisticas Generales----" << endl;
				inventario->estadisticasGenerales();
				cout << endl;
				cout << endl;
			}
			break;

			case 3: {
				string busqueda;
				cout << "Ingrese palabra para buscar en los productos: ";
				cin >> busqueda;
				Inventario* inv = new Inventario(); 
				inv = inventario->busqueda(busqueda);
				cout << "----Estadisticas Generales----" << endl;
				inv->estadisticasGenerales();
				cout << endl;
				cout << endl;
				inv->~Inventario();
				delete inv;
			}
			break;

			case 4:
				cout << "Programa Finalizado" << endl;
				inventario->~Inventario();
				delete inventario;
				break;
		}//fin switch menu general
	}//fin while menu
	return 0;
}

int menuGeneral() {
	int opcion;
	cout << "----MENU----" << endl;
	cout << "1. Mantenimiento de Productos" << endl;
	cout << "2. Estadisticas Generales" << endl;
	cout << "3. Busqueda por nombre" << endl;
	cout << "4. Salir";
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}//fin metodo Menu

int menuProductos() {
	int opcion;
	cout << "1. Agregar Producto" << endl;
	cout << "2. Modificar Producto" << endl;
	cout << "3. Eliminar Producto" << endl;
	cout << "4. Salir";
	cout << endl;
	cout << "Ingrese la opcion: ";
	cin >> opcion;
	return opcion;
}//fin metodo Menu
