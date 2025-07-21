#include <iostream>
using namespace std;
#include "Fecha.h"

///Establecimiento o implementacion de los metodos

///Constructores
 Fecha::Fecha(){
  _dia = 0;
  _mes = 0;
  _anio = 0;
 }

 Fecha::Fecha(int dia,int mes,int anio){
   setDia(dia);
   setMes(mes);
   setAnio(anio);
 }

 ///getters y setters

 int Fecha::getDia(){
   return _dia;
 }
 int Fecha::getMes(){
   return _mes;
 }
 int Fecha::getAnio(){
   return _anio;
 }
 void Fecha::setDia(int dia){
   _dia = dia;
 }
 void Fecha::setMes(int mes){
   _mes = mes;
 }
 void Fecha::setAnio(int anio){
  _anio = anio;
 }

 bool Fecha::esValida() const {
    int dia = _dia;
    int mes = _mes;
    int anio = _anio;

    if (anio < 1900 || mes < 1 || mes > 12 || dia < 1)
        return false;

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };

    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasPorMes[1] = 29;
    }

    return dia <= diasPorMes[mes - 1];
}



bool Fecha::esBisiesto(int anio) {
 return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}




bool Fecha::validarFecha(int dia, int mes, int anio) {
 if (anio < 1900) return false;
 if (mes < 1 || mes > 12) return false;

 int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

 if (mes == 2 && esBisiesto(anio)) {
     diasEnMes[1] = 29;
 }

 return dia >= 1 && dia <= diasEnMes[mes - 1];
}



void Fecha::Cargar() {
 int dia, mes, anio;

 while (true) {
     cout << "DIA: ";
     cin >> dia;
     cout << "MES: ";
     cin >> mes;
     cout << "ANIO: ";
     cin >> anio;

     if (validarFecha(dia, mes, anio)) {
         _dia = dia;
         _mes = mes;
         _anio = anio;
         break;
     } else {
         cout << "Fecha invalida. Por favor, ingrese una fecha valida." << endl;
     }
 }
}

void Fecha::Mostrar(){
cout<<_dia<<"/"<<_mes<<"/"<<_anio;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
