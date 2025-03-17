#include <iostream>
#include "Abarrote.h"
#include "Orden.h"
#include "InventarioAbarrotes.h"
#include "ReportesAbarrotes.h"
#include <vector>
using namespace std;

void mostrarMenu() {
    cout << "\n______________________________" << endl;
    cout << "   SISTEMA DE ABARROTES" << endl;
    cout << "______________________________" << endl;
    cout << "1. Registrar un nuevo producto" << endl;
    cout << "2. Crear y procesar un nuevo pedido" << endl;
    cout << "3. Generar reportes de ventas/inventario" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    vector<Abarrote> inventario;
    vector<Orden> historial;
    InventarioAbarrotes gestor(inventario, {}, {}, "");
    ReportesAbarrotes reportes(historial, 15);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
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

                Abarrote nuevoAbarrote(nombre, precio, stock, codigo);
                gestor.agregarProducto(nuevoAbarrote);
                gestor.mostrarInventario();
                break;
            }
            case 2: {
                vector<Abarrote> carrito;
                vector<int> cantidades;
                string cliente;
                int cantidadProductos;

                cout << "\nIngrese el nombre del cliente: ";
                cin >> cliente;
                cout << "Ingrese la cantidad de productos en el pedido: ";
                cin >> cantidadProductos;

                for (int i = 0; i < cantidadProductos; i++) {
                    int codigo, cantidad;
                    cout << "Ingrese el código del producto #" << i + 1 << ": ";
                    cin >> codigo;
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;

                    while (!cantidadProductos) {
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
                                    cantidadProductos = true;
                                }
                                break;
                            }
                        }

                        if (!encontrado) {
                            cout << "Error: Producto con código " << codigo << " no encontrado." << endl;
                        }
                    }
                }

                Orden nuevaOrden(carrito, cantidades, "procesado", cliente);
                historial.push_back(nuevaOrden);
                nuevaOrden.notificarCliente();
                gestor.actualizarInventario(nuevaOrden);
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