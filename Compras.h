#pragma once
#include "Fecha.h"
#include <iostream>

class Compras {
private:
    char idProveedor[30];
    char idProd[30];
    Fecha _fecha;
    float importe;
    bool activo;

public:
    // Constructor por defecto
    Compras();
    Compras(std::string idProd,std::string idPROV,Fecha fecha,float Importe, int estado);   /// para informes

    // Getters
     std::string getIdProveedor();
     std::string getIDProd();
    Fecha getFecha();
    float getImporte();
    bool getActivo();

    // Setters
    bool setIdProveedor( std::string id);
    bool setIdProd( std::string id);
    bool setFecha(const Fecha& fecha);
    bool setImporte(float importe);
    bool setActivo(bool estado);


    void mostrar();

};
