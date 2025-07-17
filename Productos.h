#pragma once
#include <string>

class Productos {

private:
    char _IDProducto[10];
    char _nombreProducto[15];
    char _tipoProducto[15];
    float _precioUnitario;
    int _stock;
    bool _estado;

public:
    Productos ();
    Productos(std::string IDProducto, std::string nombreProducto, std::string tipoProducto, float precio, int stock);

    std::string getIDProducto();
    std::string getnombreProducto();
    std::string gettipoProducto();
    float getprecioUnitario();
    int getstock();
    bool getEstado();

    bool setIDProducto(std::string IDProducto);
    bool setnombreProducto(std::string nombre);
    bool settipoProducto(std::string tipo);
    bool setprecioUnitario(float precio);
    bool setstock(int stock);
    void setEstado (bool estado);


    void cargar();
    void mostrarProd();
    void eliminar();
};

