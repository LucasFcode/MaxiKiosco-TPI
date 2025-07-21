#pragma once
#include <string>


class Proveedores{

private:
    std::string _idProveedor;
    std::string _CUIT;
    std::string _Nombre;
    std::string _Telefono;
    std::string _email;
    std::string _direccion;
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


