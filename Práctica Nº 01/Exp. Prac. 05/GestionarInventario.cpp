#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include <iostream>
#include <vector>
using namespace std;

GestionarInventario::GestionarInventario(vector<Producto>& _Inventario, vector<Producto> _listaPedidos, vector<int> _cantXprod, string _estadoPedido, vector<Producto> _Inventariotemp)
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
    vector<int> cantidades = Ped_Realizado.getCantXprod();
    vector<Producto>& productosPedido = Ped_Realizado.getListaPedidos();
    

    for (int i=0; i<productosPedido.size(); i++) {
        for (int j=0; j<Inventario.size(); j++) {
            if (Inventario[j].getCodigo() == productosPedido[i].getCodigo()) {
                int nuevoStock = Inventario[j].getStock()-cantidades[i];
                Inventario[j].setStock(nuevoStock);
            }
        }
    }
}
    
void GestionarInventario::mostrarInventario(){
    cout<<"________________________________________"<<endl;
    cout<<"INVENTARIO ACTUALIZADO"<<endl;
    cout<<"STOCK    Descripción\n"<<endl;
    for (int i=0;i<Inventario.size();i++){
        cout<<Inventario[i].getStock()<<"       "<<Inventario[i].getNombre()<<endl;
    }
    cout<<"________________________________________"<<endl;
}


GestionarInventario::~GestionarInventario(){};