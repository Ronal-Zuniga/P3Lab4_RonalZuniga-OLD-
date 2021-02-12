#include "Producto.h"

Producto::Producto(int _id, string _nombre, int _cantidad, string _categoria, float _precio){
	this->id = _id;
	this->nombre = _nombre;
	this->cantidad = _cantidad;
	this->categoria = _categoria;
	this->precio = _precio;
}

Producto::Producto(Producto* _producto){
	this->id = _producto->getId();
	this->nombre = _producto->getNombre();
	this->cantidad = _producto->getCantidad();
	this->categoria = _producto->getCategoria();
	this->precio = _producto->getPrecio();
}

int Producto::getId(){
	return this->id;
}

void Producto::setId(int _id){
	this->id = _id;
}

string Producto::getNombre(){
	return this->nombre;
}

void Producto::setNombre(string _nombre){
	this->nombre = _nombre;
}

int Producto::getCantidad(){
	return this->cantidad;
}

void Producto::setCantidad(int _cantidad){
	this->cantidad = _cantidad;
}

string Producto::getCategoria(){
	return this->categoria;
}

void Producto::setCategoria(string _categoria){
	this->categoria = _categoria;
}

float Producto::getPrecio(){
	return this->precio;
}

void Producto::setPrecio(float _precio){
	this->precio = _precio;
}



