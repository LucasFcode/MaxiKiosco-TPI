#include <cstring>
#include <iostream>
using namespace std;
#include "Compras.h"

// Constructor por defecto
Compras::Compras() {
    strcpy(idProveedor, "");
    strcpy(idCompra, "");
    importe = 0.0f;
    activo = true;
}

Compras::Compras(std::string IDcompra,std::string idPROV,Fecha fecha,float Importe, int estado){  /// agrego para informes
    strcpy (idCompra, IDcompra.c_str());
    strcpy (idProveedor, idPROV.c_str());
    _fecha= fecha;
    importe=Importe;
    activo=estado;
 }

// Getters
 std::string Compras::getIdProveedor() {
    return idProveedor;
}

 std::string Compras::getIdCompra() {
    return idCompra;
}

Fecha Compras::getFecha(){
    return _fecha;
}

float Compras::getImporte() {
    return importe;
}

bool Compras::getActivo(){
    return activo;
}

// Setters
void Compras::setIdProveedor( std::string id) {
    strcpy(idProveedor, id.c_str());
}

void Compras::setIdCompra( std::string id) {
    strcpy(idCompra, id.c_str());
}

void Compras::setFecha(const Fecha& nuevaFecha) {
    _fecha = nuevaFecha;
}

void Compras::setImporte(float nuevoImporte) {
    importe = nuevoImporte;
}

void Compras::setActivo(bool estado) {
    activo = estado;
}

// Mostrar datos
void Compras::mostrar() {
    cout << "ID Compra: " << idCompra << endl;
    cout << "ID Proveedor: " << idProveedor << endl;
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << endl;
    cout << "Importe: $" << importe << endl;
    cout << "Activo: ";
        if (activo) {
            cout << "compra habilitada en el sistema";
        } else {
            cout << "compra inhabilitada en el sistema";
        }
        cout << endl;
    cout << "-----------------------------" << endl;
}


