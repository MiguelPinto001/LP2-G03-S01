#include <iostream>
#include <string>
using namespace std;
//Definimos la estrucutra
struct datosProducto
    {   string nombre;
        float precio;
        int cantidadDisponible;
        int cantidadSolicitada;
        bool solicitado;
    };
//Funcion para añadir porductos al arreglo
//Recibe la direccion y la cantidad de productos elegida por el usuario en el main()
void registrarProductos(datosProducto *producto, int cant)
{   for (int i=0;i<cant;i++) 
    {   cout<<"PRODUCTO "<<i+1<<endl;
        cout<<"Ingrese el NOMBRE "<< i+1 <<" a REGISTRAR"<<endl;
        cin>>producto[i].nombre;
        cout<<"Ingrese el PRECIO "<< i+1 <<" a REGISTRAR"<<endl;
        cin>>producto[i].precio;
        cout<<"Ingrese el STOCK "<< i+1 <<" a REGISTRAR"<<endl;
        cin>>producto[i].cantidadDisponible;
    }
}
//Funcion para seleccionar productos para el pedido
//Recibe la direccion y la cantidad de productos del inventario (numero de elementos del areglo)
void registrarPedido(datosProducto *producto, int cant)
{   int codigo=-1;
    int cantProd=0;
    //IMPRIME un menu de caracteristicas de los productos
    for (int i=0;i<cant;i++)
    {   cout<<"/n PRODUCTO "<<producto[i].nombre<<endl;
        cout<<"Codigo: "<<i+1<<endl;
        cout<<"Nombre: "<<producto[i].nombre<<endl;
        cout<<"Precio: S/."<<producto[i].precio<<endl;
        cout<<"Stock: "<<producto[i].cantidadDisponible<<endl;
        cout<<"__________________________"<<endl;
    }
    //registra producto y cantidad que desea el usuario
    while (codigo!=0)
    {   cout<<"Ingrese el código del porducto que desea PEDIR: "<< "(Ingrese 0 para finalizar)"<<endl;
        cin>>codigo;
        cout<<"Ingrese la cantidad que desea PEDIR: "<<endl;
        cin>>cantProd;
        for(int j=0;j<cant;j++)
        {   if (j==codigo-1) //cambia el valor del atributo "salicitado" y "cantidadSolicitada"para el reporte
            {   
                producto[j].solicitado=true;
                producto[j].cantidadSolicitada=cantProd;
            }
            
        }
    }
}

//Función para mostrar por pantalla los productos elegidos, su cantidad y su precio total
void imprimirReporte(datosProducto *producto, int cant)
{   cout<<"REPORTE DEL PEDIDO:"<<endl;
    cout<<"codigo   descripción     cant.   total"<<endl;
    cout<<" "<<endl;
    for(int i=0;i<cant;i++)
    {   if (producto[i].solicitado==true)
        {   
            cout<<"0"<<i+1<<"       "<<producto[i].nombre<<"            "<<producto[i].cantidadSolicitada<<"        "<<producto[i].precio*producto[i].cantidadSolicitada<<endl;
        }
    }
}

int main()
{   int cant=0;
    //Inicia con el registro de productos al inventario
    cout<<"Ingrese la cantidad de productos a REGISTRAR"<<endl;
    cin>>cant;
    datosProducto *producto = new datosProducto[cant]; //asigna a un puntero un arreglo de elementos de tipo datosProducto con "cant" de elementos
    registrarProductos(producto, cant); //llamamos a la funcion para ingresar los productos
    registrarPedido(producto, cant); //llamamos a la funcoin para hacer un pedido
    imprimirReporte(producto, cant); //mostramos por pantalla el reporte del pedido
    return 0;
}