#pragma once
#include <cstring>
#include "Productos.h"
#include <iostream>
using namespace std;

Productos::Productos(){
strcpy(_IDProducto, "");
strcpy (_nombreProducto, "");
strcpy (_tipoProducto, "");
 _precioUnitario=0;
 _stock=0;
 _estado=true;


};
 Productos::Productos(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock){
setIDProducto(IDProducto);
setnombreProducto(nombreProducto);
settipoProducto (tipoProducto);
setprecioUnitario(precio);
setstock (stock);


 };
 ///--------------------------------------------------------------------------------------------------
bool Productos::setIDProducto(std::string IDProducto) {
    if(IDProducto.size()>11){
            return false;

       } else {strcpy (_IDProducto, IDProducto.c_str());
       return true;}


}

bool Productos::setnombreProducto(std::string nombre) {
    if(nombre.size()>16){
            return false;

       } else {strcpy (_nombreProducto, nombre.c_str());
       return true;}

   }

bool Productos::settipoProducto(std::string tipo) {
    if(tipo.size()>16){
            return false;

       } else {strcpy (_tipoProducto, tipo.c_str());
       return true;}

    }

bool Productos::setprecioUnitario(float precio) {

    if (precio < 0) {
            cout << "Error: el precio no puede ser negativo..." << endl;
            return 0;
        }
        _precioUnitario = precio;
    }



bool Productos::setstock(int stock) {
    if (stock < 0) {
            cout << "Error: el precio no puede ser negativo..." << endl;
            return 0;
        }
     _stock = stock;
}

void Productos::setEstado (bool estado){

 _estado= estado;
 }

std::string Productos::getIDProducto() {

    return _IDProducto;
}

std::string Productos::getnombreProducto() {
    return _nombreProducto;
}

std::string Productos::gettipoProducto() {
    return _tipoProducto;
}

float Productos::getprecioUnitario() {
    return _precioUnitario;
}

int Productos::getstock() {
    return _stock;
}
bool Productos::getEstado (){
return _estado;
}

void Productos::mostrarProd(){

if(_estado){

cout << "ID del Producto: " << getIDProducto() << endl;
cout << "Nombre del producto: " << getnombreProducto() << endl;
cout << "Tipo de producto: " << gettipoProducto() << endl;
cout << "Precio Unitario: " << getprecioUnitario() << endl;
cout << "Stock: " << getstock() << endl;
if(getEstado()){
cout << "-------------------------------" << endl;
cout << "Producto habilitado en el sistema" << endl;
cout << "-------------------------------" << endl;
}
else{
        cout << "-------------------------------" << endl;
    cout << "Producto ihabilitado en el sistema o no existe" << endl;
    cout << "-------------------------------" << endl;
}

}

}

