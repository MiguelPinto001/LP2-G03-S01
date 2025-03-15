#include <iostream>
#include "Producto.h"
#include "Pedido.h"
#include <vector>
using namespace std;

int main()
{
    Producto prod1("Jean",99.90,20);
    prod1.mostrarInfo();
    Producto prod2("Casaca", 149.90,13);
    prod2.mostrarInfo();
    Producto prod3("Polo",39.90,16);
    prod3.mostrarInfo();
    Producto prod4("Calcetines",14.90,30);
    prod4.mostrarInfo();
    Producto prod5("Polera",89.90,23);
    prod5.mostrarInfo();

    vector<Producto> carrito= {prod1,prod2,prod3,prod4,prod5};
    vector<int> nroPrendas= {1,2,3,4,1};

    Pedido ped1(carrito,nroPrendas,"solicitado");
    ped1.mostrarInfoPedido();

    return 0;
}