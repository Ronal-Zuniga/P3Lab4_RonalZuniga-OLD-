#include <iostream>
using namespace std;

int menuGeneral();
int menuProductos();

int main(int argc, char** argv) {
	int opcion;
	while((opcion = menuGeneral()) != 4) {
		switch(opcion) {
			case 1:
				int opcion2;
				while((opcion2 = menuProductos()) != 4) {
					switch(opcion2) {
						case 1:
							
							break;

						case 2:
							
							break;

						case 3:
							
							break;

						case 4:
							cout << endl << endl;
							break;
					}//fin switch
				}//fin while
				break;

			case 2:

				break;

			case 3:

				break;

			case 4:
				cout << "Programa Finalizado" << endl;
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
