#pragma once
#include "Fecha.h"
#include <iostream>

class Compras {
private:
    char idProveedor[30];
    char idCompra[30];
    Fecha _fecha;
    float importe;
    bool activo;

public:
    // Constructor por defecto
    Compras();
    Compras(std::string IDcompra,std::string idPROV,Fecha fecha,float Importe, int estado);   /// para informes

    // Getters
     std::string getIdProveedor();
     std::string getIdCompra();
    Fecha getFecha();
    float getImporte();
    bool getActivo();

    // Setters
    void setIdProveedor( std::string id);
    void setIdCompra( std::string id);
    void setFecha(const Fecha& fecha);
    void setImporte(float importe);
    void setActivo(bool estado);


    void mostrar();

};
