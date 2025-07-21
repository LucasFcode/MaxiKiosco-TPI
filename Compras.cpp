#include <cstring>
#include <iostream>
using namespace std;
#include "Compras.h"

// Constructor por defecto
Compras::Compras() {
    strcpy(idProveedor, "");
    strcpy(idProd, "");
    importe = 0.0f;
    _stock=0;
    activo = true;
}

Compras::Compras(std::string idProd,std::string idPROV,Fecha fecha,float Importe, int stock, bool estado){
    setIdProd(idProd);
    setIdProveedor(idPROV);
    setFecha(fecha);
    setImporte(Importe);
    setstock(stock);
    setActivo(estado);

    }

 // Setters
bool Compras::setIdProveedor( std::string id) {
    if(id.size()>30){
            return false;

       } else {strcpy (idProveedor, id.c_str());
       return true;}


}

bool Compras::setIdProd( std::string id) {
    if(id.size()>30){
            return false;

       } else {strcpy (idProd, id.c_str());
       return true;}


    }

bool Compras::setFecha(const Fecha& fecha) {
    if (fecha.esValida()) {
        _fecha = fecha;
        return true;
    } else {
        return false;
    }
}


bool Compras::setImporte(float nuevoImporte) {
    if (nuevoImporte < 0) {
            cout << "Error: el precio no puede ser negativo..." << endl;
            return 0;
        }
    importe = nuevoImporte;
}

bool  Compras::setstock(int stock) {
    if (stock < 0) {
            cout << "Error: el precio no puede ser negativo..." << endl;
            return 0;
        }
     _stock = stock;
}
bool Compras::setActivo(bool estado) {
    activo = estado;
}


// Getters
 std::string Compras::getIdProveedor() {

    return idProveedor;
}

 std::string Compras::getIDProd() {
    return idProd;
}

Fecha Compras::getFecha(){
    return _fecha;
}

float Compras::getImporte() {
    return importe;
}

int Compras::getstock() {
    return _stock;
}

bool Compras::getActivo(){
    return activo;
}

// Mostrar datos
void Compras::mostrar() {
    cout << "ID Compra: " << idProd << endl;
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


