#include <iostream>
#include <cstring>
using namespace std;
#include "Proveedores.h"

Proveedores::Proveedores(){
strcpy (_idProveedor, "");
strcpy (_CUIT, "");
strcpy (_Nombre, "");
strcpy (_Telefono, "");
strcpy (_email, "");
strcpy (_direccion, "");
 _estado=true;


}

Proveedores::Proveedores(std::string idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado){
/*strcpy (_idProveedor, idProveedor.c_str());
strcpy (_CUIT, CUIT.c_str());
strcpy (_Nombre, Nombre.c_str());
strcpy (_Telefono, Telefono.c_str());
strcpy (_email, Email.c_str());
strcpy (_direccion, Direccion.c_str());*/

setidProveedor(idProveedor);
 setCUIT(CUIT);
 setNombre(Nombre);
 setTelefono(Telefono);
 setEmail(Email);
 setDireccion(Direccion);
 setEstado(estado);
}


std::string Proveedores::getidProveedor(){
return _idProveedor;
}

std::string Proveedores::getCUIT(){
return _CUIT;
}

std::string Proveedores::getNombre(){
return _Nombre;
}

std::string Proveedores::getTelefono(){
return _Telefono;
}

std::string Proveedores::getemail(){
return _email;
}

std::string Proveedores::getDireccion(){
return _direccion;
}

bool Proveedores::getEstado(){
return _estado;
}



bool Proveedores::setidProveedor( std::string Proveedor){
    if(Proveedor.size()>30){
            return false;

       } else {strcpy (_idProveedor, Proveedor.c_str());

       return true;}
    }

bool Proveedores::setCUIT(std::string CUIT){
    if(CUIT.size()>30){
            return false;

       } else {strcpy (_CUIT, CUIT.c_str());

       return true;}

}

bool Proveedores::setNombre(std::string Nombre){

    if(Nombre.size()>30){
            return false;

       } else {strcpy (_Nombre, Nombre.c_str());

       return true;}

}

bool Proveedores::setTelefono(std::string Telefono){
    if(Telefono.size()>30){
            return false;

       } else {strcpy (_Telefono, Telefono.c_str());

       return true;}

}

bool Proveedores::setEmail(std::string Email){
    if(Email.size()>30){
            return false;

       } else {strcpy (_email, Email.c_str());

       return true;}

}

bool Proveedores::setDireccion(std::string Direccion){
    if(Direccion.size()>30){
            return false;

       } else {strcpy (_direccion, Direccion.c_str());

       return true;}


}

void Proveedores::setEstado(bool estado){
_estado=estado;
}



void Proveedores::Mostrar(){

if(_estado){

cout << "ID del Proveedor: " << getidProveedor() << endl;
cout << "Cuit del proveedor: " << getCUIT() << endl;
cout << "Nombre: " << getNombre() << endl;
cout << "Telefono: " << getTelefono() << endl;
cout << "Email: " << getemail() << endl;
cout << "Direccion: " << getDireccion() << endl;
if(getEstado()){
cout << "-------------------------------" << endl;
cout << "Proveedor habilitado en el sistema" << endl;
cout << "-------------------------------" << endl;
}
else{
        cout << "-------------------------------" << endl;
    cout << "Proveedor ihabilitado en el sistema o no existe" << endl;
    cout << "-------------------------------" << endl;
}

}

}


