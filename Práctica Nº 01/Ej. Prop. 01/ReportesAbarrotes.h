#ifndef REPORTESABARROTES_H
#define REPORTESABARROTES_H

#include "Abarrote.h"
#include "Orden.h"
#include <iostream>
#include <vector>
using namespace std;

class ReportesAbarrotes {
private:
    vector<Orden> historial;
    int umbralStock;

public:
    ReportesAbarrotes(vector<Orden> _historial, int _umbralStock);

    vector<Orden> getHistorial();
    int getUmbralStock();

    void setHistorial(vector<Orden> _historial);
    void setUmbralStock(int _umbralStock);

    void reporteVentas(vector<Abarrote>& _inventario);
    void reporteInventarioBajo(vector<Abarrote>& _inventario, int _umbralStock);
    void reporteGeneral(vector<Abarrote>& _inventario, int _umbralStock);

    ~ReportesAbarrotes();
};

#endif
