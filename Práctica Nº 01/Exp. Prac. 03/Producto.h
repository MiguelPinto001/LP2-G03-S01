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
    int codigo;

public:
    Producto(string _nombre, float _precio, int _stock, int codigo);

    string getNombre();

    float getPrecio();

    int getStock();

    int getCodigo();

    void setNombre(string _nombre);

    void setPrecio(float _precio);

    void setStock(int _stock);

    void setCodigo(int _codigo);

    void mostrarInfo();

    ~Producto();
};
#endif