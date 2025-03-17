#include "Pedido.h"
#include "Producto.h"
#include <iostream>
#include <vector>
using namespace std;
//No se vuelve a definir la clase porque ya está definida en el archivo de cabecera "Pedido.h"
//Se usan operadores de alcance para los métodos de la clase (::Pedido)


Pedido::Pedido(vector<Producto> _listaPedidos, vector<int> _cantXprod, string _estadoPedido) {
	listaPedidos = _listaPedidos;
	cantXprod = _cantXprod;
	estadoPedido = _estadoPedido;
}

vector<Producto>& Pedido::getListaPedidos() {
	return listaPedidos;
}
vector<int> Pedido::getCantXprod() {
	return cantXprod;
}
string Pedido::getEstadoPedido() {
	return estadoPedido;
}


void Pedido::setListaPedidos(vector<Producto> _listaPedidos) {
	listaPedidos = _listaPedidos;
}
void Pedido::setCantXprod(vector<int> _cantXprod) {
	cantXprod=_cantXprod;
}
void Pedido::setEstadoPedido(string _estadoPedido) {
	estadoPedido=_estadoPedido;
}

void Pedido::mostrarInfoPedido() {
    cout<<"\n"<<endl;
    cout<<"_________________________"<<endl;
    cout<<"DETALLES DEL NUEVO PEDIDO"<<endl;
	cout<<"CANT.    PRODUCTO"<<endl;
	for (int i=0; i<listaPedidos.size(); i++) {
		cout<<"  "<<cantXprod[i]<<"      "<<listaPedidos[i].getNombre()<<endl;
	}
}
Pedido::~Pedido() {
}