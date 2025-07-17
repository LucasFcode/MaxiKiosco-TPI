#pragma once
#include "Productos.h"
#include <string>


class ProductosArchivo {


 private:
     std::string _nombreArchivo;

 public:
    ProductosArchivo();
    ProductosArchivo(std::string nombreArchivo);
    bool Guardar (Productos prodP);
    bool Guardar (Productos prodP, int posicion);
    bool Modificar (Productos mod, int pos);
    bool Eliminar (std::string IDProducto);
    int cantidadTotalProductos ();
    int buscarProducto(std::string IDProducto);
    int buscarNombreProducto(std::string Name);
    int buscarStock(std::string Producto);
    Productos leer(int pos);
    bool leerMuchos(Productos reg[], int cantidad);
    void mostrarProductosActivos(Productos registro);
    void listarProductos();
    int getNuevoID();

};
