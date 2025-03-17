#include "Abarrote.h"
#include <iostream>
using namespace std;

Abarrote::Abarrote(string _nombre, float _precio, int _stock, int _codigo) {
    nombre = _nombre;
    precio = _precio;
    stock = _stock;
    codigo = _codigo;
}

string Abarrote::getNombre() const {
    return nombre;
}

float Abarrote::getPrecio() {
    return precio;
}

int Abarrote::getStock() const {
    return stock;
}

int Abarrote::getCodigo() {
    return codigo;
}

void Abarrote::setNombre(string _nombre) {
    nombre = _nombre;
}

void Abarrote::setPrecio(float _precio) {
    precio = _precio;
}

void Abarrote::setStock(int _stock) {
    stock = _stock;
}

void Abarrote::setCodigo(int _codigo) {
    codigo = _codigo;
}

void Abarrote::mostrarInfo() {
    cout << "\nNombre       Precio  Stock   Codigo" << endl;
    cout << nombre << "         " << precio << "    " << stock << "     " << codigo << endl;
}

Abarrote::~Abarrote() { }
