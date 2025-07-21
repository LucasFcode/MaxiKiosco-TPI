#pragma once
#include <string>


class Proveedores{

private:
    char _idProveedor[30];
    char _CUIT[30];
    char _Nombre[30];
    char _Telefono[30];
    char _email[30];
    char _direccion[30];
    bool _estado;



public:

Proveedores();
Proveedores(std::string idProveedor, std::string CUIT, std::string Nombre, std::string Telefono, std::string Email, std::string Direccion, bool estado);
std::string getidProveedor();
std::string getCUIT();
std::string getNombre();
std::string getTelefono();
std::string getemail();
std::string getDireccion();
bool getEstado();
bool setidProveedor( std::string Proveedor);
bool setCUIT(std::string CUIT);
bool setNombre(std::string Nombre);
bool setTelefono(std::string Telefono);
bool setEmail(std::string Email);
bool setDireccion(std::string Direccion);
void setEstado(bool estado);


void Cargar();
void Mostrar();

};


