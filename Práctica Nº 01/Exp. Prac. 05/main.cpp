#include <iostream>
#include "Producto.h"
#include "Pedido.h"
#include "GestionarInventario.h"
#include "GeneradorDeReportes.h"
#include <vector>
using namespace std;

void mostrarMenu() {
    cout << "\n______________________________" << endl;
    cout << "   SISTEMA DE INVENTARIO" << endl;
    cout << "______________________________" << endl;
    cout << "1. Registrar un nuevo producto" << endl;
    cout << "2. Crear y procesar un nuevo pedido" << endl;
    cout << "3. Generar reportes de ventas/inventario" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    vector<Producto> inventario;
    vector<Pedido> historial;
    GestionarInventario gestor(inventario, {}, {}, "");
    GeneradorDeReportes reportes(historial, 15);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Registrar un nuevo producto
                string nombre;
                float precio;
                int stock, codigo;

                cout << "\nIngrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese la cantidad en stock: ";
                cin >> stock;
                cout << "Ingrese el código del producto: ";
                cin >> codigo;

                Producto nuevoProducto(nombre, precio, stock, codigo);
                gestor.agregarProducto(nuevoProducto);
                cout << "\nProducto registrado con éxito." << endl;
                gestor.mostrarInventario();
                break;
            }
            case 2: {
                // Crear y procesar un nuevo pedido
                vector<Producto> carrito;
                vector<int> cantidades;
                int cantidadProductos;

                cout << "\nIngrese la cantidad de productos en el pedido: ";
                cin >> cantidadProductos;

                for (int i = 0; i < cantidadProductos; i++) {
                    int codigo, cantidad;
                    bool cantidadValida = false;

                    while (!cantidadValida) {
                        cout << "Ingrese el código del producto #" << i + 1 << ": ";
                        cin >> codigo;

                        // Buscar producto en el inventario
                        bool encontrado = false;
                        for (int j = 0; j < inventario.size(); j++) {
                            if (inventario[j].getCodigo() == codigo) {
                                encontrado = true;

                                cout << "Ingrese la cantidad: ";
                                cin >> cantidad;

                                // Verificar si hay suficiente stock
                                if (cantidad > inventario[j].getStock()) {
                                    cout << "Error: Solo hay " << inventario[j].getStock() << " unidades disponibles." << endl;
                                    cout << "Ingrese una cantidad menor o igual a la disponible." << endl;
                                } else {
                                    carrito.push_back(inventario[j]);
                                    cantidades.push_back(cantidad);
                                    cantidadValida = true;
                                }
                                break;
                            }
                        }

                        if (!encontrado) {
                            cout << "Error: Producto con código " << codigo << " no encontrado." << endl;
                        }
                    }
                }

                Pedido nuevoPedido(carrito, cantidades, "solicitado");
                historial.push_back(nuevoPedido);
                gestor.actualizarInventario(nuevoPedido);
                cout << "\nPedido procesado con éxito." << endl;
                gestor.mostrarInventario();
                break;
            }
            case 3: {
                // Generar reportes de ventas/inventario
                cout << "\nGENERANDO REPORTE GENERAL..." << endl;
                reportes.setHistorial(historial);
                reportes.reporteGeneral(inventario, 15);
                break;
            }
            case 4:
                cout << "\nSaliendo del sistema..." << endl;
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}