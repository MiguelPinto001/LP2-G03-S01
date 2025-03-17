#include "ReportesAbarrotes.h"
#include <iostream>
using namespace std;

ReportesAbarrotes::ReportesAbarrotes(vector<Orden> _historial, int _umbralStock) {
    historial = _historial;
    umbralStock = _umbralStock;
}

vector<Orden> ReportesAbarrotes::getHistorial() {
    return historial;
}

int ReportesAbarrotes::getUmbralStock() {
    return umbralStock;
}

void ReportesAbarrotes::setHistorial(vector<Orden> _historial) {
    historial = _historial;
}

void ReportesAbarrotes::setUmbralStock(int _umbralStock) {
    umbralStock = _umbralStock;
}

void ReportesAbarrotes::reporteVentas(vector<Abarrote>& _inventario) {
    cout << "\n________________________________________" << endl;
    cout << "REPORTE DE VENTAS" << endl;
    cout << "________________________________________" << endl;
    cout << "Vendidas  CODIGO   PRODUCTO" << endl;

    for (int i = 0; i < _inventario.size(); i++) {
        int unidadesVendidas = 0;
        for (int j = 0; j < historial.size(); j++) {
            vector<Abarrote> productosOrden = historial[j].getListaOrden();
            vector<int> cantidades = historial[j].getCantXprod();
            for (int k = 0; k < productosOrden.size(); k++) {
                if (productosOrden[k].getCodigo() == _inventario[i].getCodigo()) {
                    unidadesVendidas += cantidades[k];
                }
            }
        }
        cout << "  " << unidadesVendidas << "       " << _inventario[i].getCodigo() << "      " << _inventario[i].getNombre() << endl;
    }
}

void ReportesAbarrotes::reporteInventarioBajo(vector<Abarrote>& _inventario, int _umbralStock) {
    cout << "\n________________________________________" << endl;
    cout << "PRODUCTOS POR DEBAJO DEL UMBRAL: " << _umbralStock << endl;
    cout << "________________________________________" << endl;
    cout << "STOCK    CODIGO   PRODUCTO" << endl;

    for (int i = 0; i < _inventario.size(); i++) {
        if (_inventario[i].getStock() < _umbralStock) {
            cout << _inventario[i].getStock() << "       " << _inventario[i].getCodigo() << "      " << _inventario[i].getNombre() << endl;
        }
    }
}

void ReportesAbarrotes::reporteGeneral(vector<Abarrote>& _inventario, int _umbralStock) {
    cout << "\n________________________________________" << endl;
    cout << "INVENTARIO ACTUAL" << endl;
    cout << "________________________________________" << endl;
    cout << "STOCK    CODIGO   PRODUCTO" << endl;
    for (int i = 0; i < _inventario.size(); i++) {
        cout << _inventario[i].getStock() << "       " << _inventario[i].getCodigo() << "      " << _inventario[i].getNombre() << endl;
    }

    reporteVentas(_inventario);
    reporteInventarioBajo(_inventario, _umbralStock);
}


ReportesAbarrotes::~ReportesAbarrotes() {}

