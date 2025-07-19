#pragma once
#include <string>
#include "Compras.h"
#include "Fecha.h"

class ComprasArchivo {
private:
    std::string _nombreArchivo;

public:
    ComprasArchivo(std::string nombreArchivo);

    ComprasArchivo();
    Compras leerUno(int pos);
    bool guardar(Compras maxi);
    bool modificar(Compras maxi, int pos);
    bool eliminar(Compras maxi, int pos);
    int listarTodos();
    int getCantidadRegistros();
    //int buscarProveedor(std::string nombreProveedor); --> revisar es lo mismo que proveedores
    int  buscarFechadecompra(int fechadia, int fechaMes, int fechaAnio);
    int buscaridCompra(std::string idCompra);
    float buscarImportecompra(float importeCompra);
    bool leerMuchos(Compras reg[], int cantidad);

};
