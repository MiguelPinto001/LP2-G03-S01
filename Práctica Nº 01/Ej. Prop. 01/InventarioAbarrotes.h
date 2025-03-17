#ifndef INVENTARIOABARROTES_H
#define INVENTARIOABARROTES_H

#include "Abarrote.h"
#include "Orden.h"
#include <iostream>
#include <vector>
using namespace std;

class InventarioAbarrotes {
private:
    vector<Abarrote>& inventario;
    Orden detallesOrden;
    vector<Abarrote> inventarioTemp;

public:
    InventarioAbarrotes(vector<Abarrote>& _inventario, vector<Abarrote> _listaOrden, vector<int> _cantXprod, string _estadoOrden, vector<Abarrote> inventarioTemp = {});

    vector<Abarrote> getInventario();
    Orden getDetallesOrden();
    vector<Abarrote> getInventarioTemp();

    void setInventario(vector<Abarrote> _inventario);
    void setDetallesOrden(Orden _detallesOrden);
    void setInventarioTemp(vector<Abarrote> _inventarioTemp);

    void agregarProducto(Abarrote nuevoAbarrote);
    void actualizarInventario(Orden ordenRealizada);
    void mostrarInventario();

    ~InventarioAbarrotes();
};

#endif
