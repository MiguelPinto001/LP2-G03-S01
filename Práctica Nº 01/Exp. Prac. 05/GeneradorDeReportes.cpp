#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include "GeneradorDeReportes.h"
#include <iostream>
#include <vector>
using namespace std;

GeneradorDeReportes::GeneradorDeReportes(vector<Pedido> _historial, int _umbralStock){
    historial = _historial;
    umbralStock = _umbralStock;
}

vector<Pedido> GeneradorDeReportes::getHistorial(){
    return historial;
}

int GeneradorDeReportes::getUmbralStock(){
    return umbralStock;
}

void GeneradorDeReportes::setHistorial(vector<Pedido> _historial){
    historial = _historial;
}

void GeneradorDeReportes::setUmbralStock(int _umbralStock){
    umbralStock = _umbralStock;
}

void GeneradorDeReportes::reporteVentas(vector<Producto> _Inventario){
    cout<<"\nREPORTE DE VENTAS"<<endl;
    cout<<"________________________________________"<<endl;
    cout << " Unid." << endl;
    cout << "Vendidas Código  Descripción" << endl;
    for (int i=0;i<_Inventario.size();i++){
        int unidadesVendidas=0;
        for (int j=0;j<historial.size();j++){ 
            vector<Producto> productosDelPedido=historial[j].getListaPedidos();
            vector<int> cantidades=historial[j].getCantXprod();
            for (int k=0; k<productosDelPedido.size(); k++) {
                if (productosDelPedido[k].getCodigo()==_Inventario[i].getCodigo()){
                    unidadesVendidas=unidadesVendidas+cantidades[k];
                }
            }
        }
        cout << "   " << unidadesVendidas << "       " << _Inventario[i].getCodigo() << "      " << _Inventario[i].getNombre() << endl;
    }
    
}

void GeneradorDeReportes::reporteInventarioBajo(vector<Producto>& _Inventario, int _umbralStock) {
    cout<<"\nPRODUCTOS POR DEBAJO DEL UMBRAL: "<<_umbralStock<<endl;
    cout<<"________________________________________"<<endl;
    cout<<"STOCK    Descripción"<<endl;
    for (int i=0; i<_Inventario.size(); i++) {
        if(_Inventario[i].getStock()<_umbralStock){
            cout<<_Inventario[i].getStock()<<"       "<<_Inventario[i].getNombre()<<endl;
        }
    }
    cout<<"________________________________________"<<endl;
}

void GeneradorDeReportes::reporteGeneral(vector<Producto>& _Inventario, int _umbralStock) {
    cout << "\n________________________________________" << endl;
    cout << "REPORTE GENERAL DEL INVENTARIO Y PEDIDOS" << endl;
    cout << "________________________________________" << endl;

    // Mostrar inventario actual reutilizando mostrarInventario()
    cout << "\nINVENTARIO ACTUAL" << endl;
    cout << "________________________________________" << endl;
    GestionarInventario gestor(_Inventario, {}, {}, ""); 
    gestor.mostrarInventario();

    // Mostrar historial de pedidos reutilizando mostrarInfoPedido()
    cout << "\nHISTORIAL DE PEDIDOS" << endl;
    cout << "________________________________________" << endl;
    cout << "Total de pedidos: " << historial.size() << endl;
    for (int i = 0; i < historial.size(); i++) {
        cout << "\nPedido #" << i + 1 << endl;
        historial[i].mostrarInfoPedido();
    }

    // Mostrar ventas por producto reutilizando reporteVentas()
    cout << "\nREPORTE DE VENTAS" << endl;
    cout << "________________________________________" << endl;
    reporteVentas(_Inventario);

    // Mostrar productos con stock bajo reutilizando reporteInventarioBajo()
    reporteInventarioBajo(_Inventario, _umbralStock);

}

GeneradorDeReportes::~GeneradorDeReportes(){};
