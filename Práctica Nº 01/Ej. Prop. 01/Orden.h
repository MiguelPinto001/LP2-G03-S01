#ifndef ORDEN_H
#define ORDEN_H

#include "Abarrote.h"
#include <iostream>
#include <vector>
using namespace std;

class Orden {
private:
    vector<Abarrote> listaOrden;
    vector<int> cantXprod;
    string estadoOrden;
    string cliente;

public:
    Orden(vector<Abarrote> _listaOrden, vector<int> _cantXprod, string _estadoOrden, string _cliente);

    vector<Abarrote>& getListaOrden();
    vector<int> getCantXprod();
    string getEstadoOrden();
    string getCliente();

    void setListaOrden(vector<Abarrote> _listaOrden);
    void setCantXprod(vector<int> _cantXprod);
    void setEstadoOrden(string _estadoOrden);
    void setCliente(string _cliente);

    void mostrarInfoOrden();
    void notificarCliente();
    ~Orden();
};

#endif
