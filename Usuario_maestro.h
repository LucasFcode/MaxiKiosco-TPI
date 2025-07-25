#pragma once
#include "Productos.h"
#include "Proveedores.h"
#include "Compras.h"

class Usuario_maestro {

private:

public:
    ///Productos
    void cargarProducto ();
    void listarProductos();
    void eliminarProducto ();
    void modificarProducto ();


    ///Proveedores
    void cargarProveedor ();
    void mostrarProveedoresActivos(Proveedores reg);
    void eliminarProveedores ();
    void modificarProveedores ();
    void listarProveedores();

    ///Compras
    void cargarCompras();
    void mostrarcomprasActivas(Compras reg);
    void eliminarCompra ();
    void modificarCompra ();
    void listarcompras();


};
