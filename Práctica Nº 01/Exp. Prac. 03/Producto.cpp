#include "Producto.h"
#include <iostream>
#include <vector>
using namespace std;

Producto::Producto(string _nombre, float _precio, int _stock, int _codigo) { //Constructor
	nombre=_nombre;
	precio=_precio;
	stock=_stock;
	codigo=_codigo;
}

string Producto::getNombre() { //getter nombre
	return nombre;
}

float Producto::getPrecio() { //getter precio
	return precio;
}

int Producto::getStock() { //getter stock
	return stock;
}

int Producto::getCodigo() { //getter codigo
	return codigo;
}

void Producto::setNombre(string _nombre) { //setter nombre
	nombre = _nombre;
}

void Producto::setPrecio(float _precio) { //setter precio
	precio = _precio;
}

void Producto::setStock(int _stock) { //setter stock
	stock = _stock;
}

void Producto::setCodigo(int _codigo) { //setter codigo
	codigo = _codigo;
}

void Producto::mostrarInfo() { //método que muestra info del objeto
	cout<<"\n"<<endl;
	cout<<"Nombre: "<< nombre <<endl;
	cout<<"Precio: "<< precio <<endl;
	cout<<"Stock: "<< stock <<endl;
	cout<<"Codigo: "<< codigo <<endl;
}

Producto::~Producto() { //edstructor
}