#pragma once

///DECLARACION DE METODO

class Fecha{
  private:
    int _dia, _mes, _anio;
  public:

    ///constructor
    Fecha();
    Fecha(int dia,int mes,int anio);


    int getDia();
    void setDia(int dia);

    int getMes();
    void setMes(int mes);

    int getAnio();
    void setAnio(int anio);

    void Cargar();
    void Mostrar();
    std::string toString(); /// agrego para Usuario_maestro.cpp

    bool esBisiesto(int anio);
    bool validarFecha(int dia, int mes, int anio);
    bool esValida() const;


};
