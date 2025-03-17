#ifndef GESTIONARINVENTARIO_H
#define GESTIONARINVENTARIO_H

#include "Producto.h"
#include "Pedido.h"
#include <iostream>
#include <vector>
using namespace std;

class GestionarInventario {
private:
    vector<Producto>& Inventario;
    Pedido detallesPed;
    vector<Producto> Inventariotemp;
public:
    GestionarInventario(vector<Producto>& _Inventario, vector<Producto> _listaPedidos, vector<int> _cantXprod, string _estadoPedido, vector<Producto> Inventariotemp = {});

    vector<Producto> getInventario();
    Pedido getDetallesPed();
    vector<Producto> getInventariotemp();

    void setInventario(vector<Producto> _Inventario);
    void setDetallesPed(Pedido _detallesPed);
    void setInventariotemp(vector<Producto> _Inventariotemp);

    void agregarProducto(Producto Prod_Nuevo);
    void actualizarInventario(Pedido Ped_Realizado);
    void mostrarInventario();

    ~GestionarInventario();
};
#endif