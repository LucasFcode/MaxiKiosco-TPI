#pragma once
#include <string>

class Productos {

private:
    char _IDProducto[10];
    char _nombreProducto[30];
    char _tipoProducto[30];
    float _precioUnitario;
    bool _estado;

public:
    Productos ();
    Productos(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio);

    std::string getIDProducto();
    std::string getnombreProducto();
    std::string gettipoProducto();
    float getprecioUnitario();
    bool getEstado();

    bool setIDProducto(std::string IDProducto);
    bool setnombreProducto(std::string nombre);
    bool settipoProducto(std::string tipo);
    bool setprecioUnitario(float precio);

    void setEstado (bool estado);


    void cargar();
    void mostrarProd();
    void eliminar();
};

