#include "Orden.h"
#include <iostream>
using namespace std;

Orden::Orden(vector<Abarrote> _listaOrden, vector<int> _cantXprod, string _estadoOrden, string _cliente) {
    listaOrden = _listaOrden;
    cantXprod = _cantXprod;
    estadoOrden = _estadoOrden;
    cliente = _cliente;
}

vector<Abarrote>& Orden::getListaOrden() {
    return listaOrden;
}

vector<int> Orden::getCantXprod() {
    return cantXprod;
}

string Orden::getEstadoOrden() {
    return estadoOrden;
}

string Orden::getCliente() {
    return cliente;
}

void Orden::setListaOrden(vector<Abarrote> _listaOrden) {
    listaOrden = _listaOrden;
}

void Orden::setCantXprod(vector<int> _cantXprod) {
    cantXprod = _cantXprod;
}

void Orden::setEstadoOrden(string _estadoOrden) {
    estadoOrden = _estadoOrden;
}

void Orden::setCliente(string _cliente) {
    cliente = _cliente;
}

void Orden::mostrarInfoOrden() {
    cout << "\n_________________________" << endl;
    cout << "DETALLES DE LA ORDEN" << endl;
    cout << "Cliente: " << cliente << endl;
    cout << "CANT.    PRODUCTO" << endl;
    for (int i = 0; i < listaOrden.size(); i++) {
        cout << "  " << cantXprod[i] << "      " << listaOrden[i].getNombre() << endl;
    }
}

void Orden::notificarCliente() {
    cout << "\nNotificación: Estimado " << cliente << ", su orden está lista para recoger." << endl;
}

Orden::~Orden() { }
