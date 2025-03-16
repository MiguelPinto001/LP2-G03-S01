#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <iostream>
#include <vector>
using namespace std;

class Pedido {
private:
    vector<Producto> listaPedidos;
    vector<int> cantXprod;
    string estadoPedido;
public:
    Pedido(vector<Producto> _listaPedidos, vector<int> _cantXprod, string _estadoPedido);

    vector<Producto> getListaPedidos();
    vector<int> getCantXprod();
    string getEstadoPedido();


    void setListaPedidos(vector<Producto> _listaPedidos);
    void setCantXprod(vector<int> _cantXprod);
    void setEstadoPedido(string _estadoPedido);

    void mostrarInfoPedido();
    ~Pedido();
};
#endif