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
strcpy (_idProveedor, idProveedor.c_str());
strcpy (_CUIT, CUIT.c_str());
strcpy (_Nombre, Nombre.c_str());
strcpy (_Telefono, Telefono.c_str());
strcpy (_email, Email.c_str());
strcpy (_direccion, Direccion.c_str());
 _estado= estado;


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

void Proveedores::setCUIT(std::string CUIT){
strcpy(_CUIT, CUIT.c_str());
}

void Proveedores::setNombre(std::string Nombre){
strcpy(_Nombre, Nombre.c_str());
}

void Proveedores::setTelefono(std::string Telefono){
strcpy(_Telefono, Telefono.c_str());
}

void Proveedores::setEmail(std::string Email){
strcpy(_email, Email.c_str());
}

void Proveedores::setDireccion(std::string Direccion){
strcpy(_direccion, Direccion.c_str());
}

void Proveedores::setEstado(bool estado){
_estado=estado;
}


/*  -----------------------------------------------------------> POSIBLEMENTE BORRAR POR MANAGER
void Proveedores::Cargar(){
string CUIT_str, Nombre_str, Telefono_str, Email_str, Direccion_str;
int idProv;

cout << "Carga de IDProveedor" << endl;
cin >> idProv;
setidProveedor(idProv);
cin.ignore();
cout << "Carga de CUIT" << endl;
getline(cin,CUIT_str);
setCUIT(CUIT_str.c_str());
cout << "Carga de Nombre" << endl;
getline(cin,Nombre_str);
setNombre(Nombre_str.c_str());
cout << "Carga de Telefono" << endl;
getline(cin,Telefono_str);
setTelefono(Telefono_str.c_str());
cout << "Carga de Email" << endl;
getline(cin,Email_str);
setEmail(Email_str.c_str());
cout << "Carga de Direccion" << endl;
getline(cin,Direccion_str);
setDireccion(Direccion_str.c_str());
_estado=true;

}
*/

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



void Proveedores::Opcmenu(){
int Opcs;
bool Salida=true;
while(Salida==true){
cout << "=================================" << endl;
cout << "1- Cargar proveedor" << endl;
cout << "2- Mostrar proveedor" << endl;
cout << "3- Borrar proveedor" << endl;
cout << "4- regresar al menu anterior" << endl;
cin >> Opcs;
cin.ignore();
switch(Opcs){
case 1:
  // Cargar();
    break;

case 2:
    Mostrar();
    break;

case 3:
   // Eliminar();
    break;

 case 4:
    Salida=false;
    break;

    default:
    exit(0);
    break;
}

}
}
