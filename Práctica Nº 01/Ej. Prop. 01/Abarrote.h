#ifndef ABARROTE_H
#define ABARROTE_H

#include <iostream>
#include <string>
using namespace std;

class Abarrote {
private:
    string nombre;
    float precio;
    int stock;
    int codigo;

public:
    Abarrote(string _nombre, float _precio, int _stock, int _codigo);

    string getNombre() const;
    float getPrecio();
    int getStock() const;
    int getCodigo();

    void setNombre(string _nombre);
    void setPrecio(float _precio);
    void setStock(int _stock);
    void setCodigo(int _codigo);

    void mostrarInfo();
    ~Abarrote();
};

#endif
