#include "InventarioAbarrotes.h"
#include <iostream>
using namespace std;

InventarioAbarrotes::InventarioAbarrotes(vector<Abarrote>& _inventario, vector<Abarrote> _listaOrden, vector<int> _cantXprod, string _estadoOrden, vector<Abarrote> _inventarioTemp)
    : inventario(_inventario), detallesOrden(_listaOrden, _cantXprod, _estadoOrden, ""), inventarioTemp(_inventarioTemp) {}

vector<Abarrote> InventarioAbarrotes::getInventario() {
    return inventario;
}

Orden InventarioAbarrotes::getDetallesOrden() {
    return detallesOrden;
}

vector<Abarrote> InventarioAbarrotes::getInventarioTemp() {
    return inventarioTemp;
}

void InventarioAbarrotes::setInventario(vector<Abarrote> _inventario) {
    inventario = _inventario;
}

void InventarioAbarrotes::setDetallesOrden(Orden _detallesOrden) {
    detallesOrden = _detallesOrden;
}

void InventarioAbarrotes::setInventarioTemp(vector<Abarrote> _inventarioTemp) {
    inventarioTemp = _inventarioTemp;
}

void InventarioAbarrotes::agregarProducto(Abarrote nuevoAbarrote) {
    inventario.push_back(nuevoAbarrote);
}

void InventarioAbarrotes::actualizarInventario(Orden ordenRealizada) {
    vector<Abarrote>& productosOrden = ordenRealizada.getListaOrden();
    vector<int> cantidades = ordenRealizada.getCantXprod();

    for (int i = 0; i < productosOrden.size(); i++) {
        for (int j = 0; j < inventario.size(); j++) {
            if (inventario[j].getCodigo() == productosOrden[i].getCodigo()) {
                int nuevoStock = inventario[j].getStock() - cantidades[i];
                inventario[j].setStock(nuevoStock);
            }
        }
    }
}

void InventarioAbarrotes::mostrarInventario() {
    cout << "\n________________________________________" << endl;
    cout << "INVENTARIO DE ABARROTES" << endl;
    cout << "________________________________________" << endl;
    cout << "STOCK    CODIGO   PRODUCTO" << endl;
    for (int i = 0; i < inventario.size(); i++) {
        cout << inventario[i].getStock() << "       " << inventario[i].getCodigo() << "      " << inventario[i].getNombre() << endl;
    }
    cout << "________________________________________" << endl;
}

InventarioAbarrotes::~InventarioAbarrotes() {}
