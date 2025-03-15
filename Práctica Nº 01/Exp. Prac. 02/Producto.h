#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include  <string>
using namespace std;


class Producto {
private:
    string nombre;
    float precio;
    int stock;

public:
    Producto(string _nombre, float _precio, int _stock);

    string getNombre();

    float getPrecio();

    int getStock();

    void setNombre(string _nombre);

    void setPrecio(float _precio);

    void setStock(int _stock);

    void mostrarInfo();

    ~Producto();
};
#endif