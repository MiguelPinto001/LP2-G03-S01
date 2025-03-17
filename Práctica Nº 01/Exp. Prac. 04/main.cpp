#include <iostream>
#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include "GeneradorDeReportes.h"
#include <vector>
using namespace std;

int main()
{   //Instanciamos objetos de la clase Producto
    Producto prod1("Jean",99.90,20,101);
    prod1.mostrarInfo();
    Producto prod2("Casaca", 149.90,13,202);
    prod2.mostrarInfo();
    Producto prod3("Polo",39.90,16,303);
    prod3.mostrarInfo();
    Producto prod4("Medias",14.90,30,404);
    prod4.mostrarInfo();
    Producto prod5("Polera",89.90,23,505);
    prod5.mostrarInfo();
    
    //Datos del pedido
    vector<Producto> inventario= {prod1,prod2,prod3,prod4,prod5};
    vector<Producto> carrito= {prod1,prod2,prod3,prod4,prod5};
    vector<int> nroPrendas= {1,2,3,4,1};
    
    //Datos del pedido 2
    vector<Producto> carrito2= {prod1,prod5};
    vector<int> nroPrendas2= {1,8};

    //Instanciamos objetos de la clase Pedido
    Pedido ped1(carrito,nroPrendas,"solicitado");
    ped1.mostrarInfoPedido();
    
    Pedido ped2(carrito2,nroPrendas2,"solicitado");
    ped2.mostrarInfoPedido();

    //INstanciamos objetos de la clase GestionarInventario
    GestionarInventario actu(inventario,carrito,nroPrendas,"solicitado");
    cout<<"\n         INVENTARIO ORIGINAL"<<endl;
    actu.mostrarInventario();
    actu.actualizarInventario(ped1);
    actu.actualizarInventario(ped2);
    actu.mostrarInventario();

    //Instanciasmos objetos de la clase GeneradorDeReportes
    vector<Pedido> historial={ped1,ped2};
    GeneradorDeReportes repo(historial);
    repo.reporteVentas(inventario);
    repo.reporteInventarioBajo(inventario, 15);
    
    repo.reporteGeneral(inventario, 15);
    
    return 0;
}