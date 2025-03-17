#ifndef GENERADORDEREPORTES_H
#define GENERADORDEREPORTES_H

#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include <iostream>
#include <vector>
using namespace std;

class GeneradorDeReportes {
private:
    vector<Pedido> historial;
    int umbralStock;
public:
    GeneradorDeReportes(vector<Pedido> _historial, int _umbralStock=0);

    vector<Pedido> getHistorial();
    int getUmbralStock();

    void setHistorial(vector<Pedido> _historial);
    void setUmbralStock(int _umbralStock);

    void reporteVentas(vector<Producto> _Inventario);

    void reporteInventarioBajo(vector<Producto>& _Inventario, int _umbralStock);
    
    void reporteGeneral(vector<Producto>& _Inventario, int _umbralStock);
    
    ~GeneradorDeReportes();
};
#endif