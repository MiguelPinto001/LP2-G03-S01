#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include <iostream>
#include <vector>
using namespace std;

GestionarInventario::GestionarInventario(vector<Producto> _Inventario, vector<Producto> _listaPedidos, vector<int> _cantXprod, string _estadoPedido, vector<Producto> _Inventariotemp)
    : Inventario(_Inventario), detallesPed(_listaPedidos, _cantXprod, _estadoPedido), Inventariotemp(_Inventariotemp) { }

vector<Producto> GestionarInventario::getInventario() {
    return Inventario;
}
Pedido GestionarInventario::getDetallesPed() {
    return detallesPed;
}
vector<Producto> GestionarInventario::getInventariotemp() {
    return Inventariotemp;
}

void GestionarInventario::setInventario(vector<Producto> _Inventario) {
    Inventario=_Inventario;
}
void GestionarInventario::setDetallesPed(Pedido _detallesPed) {
    detallesPed=_detallesPed;
}
void GestionarInventario::setInventariotemp(vector<Producto> _Inventariotemp) {
    Inventariotemp=_Inventariotemp;
}

void GestionarInventario::agregarProducto(Producto Prod_Nuevo) {
    Inventario.push_back(Prod_Nuevo);
}
void GestionarInventario::actualizarInventario(Pedido Ped_Realizado) {
    Inventariotemp=Ped_Realizado.getListaPedidos();
    vector<int> cantidades = Ped_Realizado.getCantXprod();

    for (int i=0; i<Inventariotemp.size(); i++) {
        for (int j=0; j<Inventario.size(); j++) {
            if (Inventario[j].getCodigo() == Inventariotemp[i].getCodigo()) {
                Inventario[j].setStock(Inventario[j].getStock()-cantidades[i]);
            }
        }
    }
}
    
void GestionarInventario::mostrarInventario(){
    cout<<"INVENTARIO"<<endl;
    cout<<"STOCK    Descripción\n"<<endl;
    for (int i=0;i<Inventario.size();i++){
        cout<<Inventario[i].getStock()<<"       "<<Inventario[i].getNombre()<<endl;
    }
}


GestionarInventario::~GestionarInventario(){};