#include <iostream>
using namespace std;
#include "Proveedores.h"

Proveedores::Proveedores(){
/*strcpy (_idProveedor, "");
strcpy (_CUIT, "");
strcpy (_Nombre, "");
strcpy (_Telefono, "");
strcpy (_email, "");
strcpy (_direccion, "");*/
 _estado=true;

 _idProveedor= "";
_CUIT= "";
_Nombre= "";
_Telefono= "";
_email= "";
_direccion= "";

}

Proveedores::Proveedores(std::string idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado){
/*strcpy (_idProveedor, idProveedor.c_str());
strcpy (_CUIT, CUIT.c_str());
strcpy (_Nombre, Nombre.c_str());
strcpy (_Telefono, Telefono.c_str());
strcpy (_email, Email.c_str());
strcpy (_direccion, Direccion.c_str());*/
 _estado= estado;

setidProveedor(idProveedor);
 setCUIT(CUIT);
 setNombre(Nombre);
 setTelefono(Telefono);
 setEmail(Email);
 setDireccion(Direccion);

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

       } else {_idProveedor=Proveedor;
       return true;}
    }

bool Proveedores::setCUIT(std::string CUIT){
_CUIT=CUIT;
}

bool Proveedores::setNombre(std::string Nombre){
_Nombre=Nombre;
}

bool Proveedores::setTelefono(std::string Telefono){
_Telefono=Telefono;
}

bool Proveedores::setEmail(std::string Email){
_email=Email;
}

bool Proveedores::setDireccion(std::string Direccion){
_direccion=Direccion;
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


