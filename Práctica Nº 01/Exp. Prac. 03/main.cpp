#include <iostream>
#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include <vector>
using namespace std;

int main()
{   //Instanciamos objetos de la clase Producto
    Producto prod1("Jean",99.90,20,001);
    prod1.mostrarInfo();
    Producto prod2("Casaca", 149.90,13,002);
    prod2.mostrarInfo();
    Producto prod3("Polo",39.90,16,003);
    prod3.mostrarInfo();
    Producto prod4("Calcetines",14.90,30,004);
    prod4.mostrarInfo();
    Producto prod5("Polera",89.90,23,005);
    prod5.mostrarInfo();
    
    //Datos del pedido
    vector<Producto> inventario= {prod1,prod2,prod3,prod4,prod5};
    vector<Producto> carrito= {prod1,prod2,prod3,prod4,prod5};
    vector<int> nroPrendas= {1,2,3,4,1};

    //Instanciamos objetos de la clase Pedido
    Pedido ped1(carrito,nroPrendas,"solicitado");
    ped1.mostrarInfoPedido();

    //INstanciamos objetos de la clase GestionarInventario
    GestionarInventario actu(inventario,carrito,nroPrendas,"solicitado");
    actu.actualizarInventario(ped1);
    actu.mostrarInventario();

    return 0;
}