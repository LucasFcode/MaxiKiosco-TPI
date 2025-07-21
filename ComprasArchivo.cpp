#include <iostream>
#include <cstdio>
using namespace std;
#include "ComprasArchivo.h"

ComprasArchivo::ComprasArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}


ComprasArchivo::ComprasArchivo() {
    _nombreArchivo = "compras.dat";
}

Compras ComprasArchivo::leerUno(int pos) {
    Compras maxi;
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) {
        cout << "Error al abrir archivo para lectura" << endl;
        return maxi;
    }
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    fread(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return maxi;
}

bool ComprasArchivo::guardar(Compras maxi) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "ab");
    if (archivo == nullptr) return false;
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

bool ComprasArchivo::modificar(Compras maxi, int pos) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (archivo == nullptr) return false;
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

bool ComprasArchivo::eliminar(Compras maxi, int pos) {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (archivo == nullptr) return false;
    // Se supone que Compras tiene un m‚todo setActivo(false);
    maxi.setActivo(false);
    fseek(archivo, sizeof(Compras) * pos, SEEK_SET);
    bool exito = fwrite(&maxi, sizeof(Compras), 1, archivo);
    fclose(archivo);
    return exito;
}

int ComprasArchivo::listarTodos() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) return 0;
    int Comprascargadas=0;
    Compras maxi;
    while (fread(&maxi, sizeof(Compras), 1, archivo)) {
        if (maxi.getActivo()) {
            maxi.mostrar();  // Suponiendo que tiene un m‚todo mostrar()
            Comprascargadas++;
        }
    }
    fclose(archivo);
    return Comprascargadas;
}

int ComprasArchivo::getCantidadRegistros() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    if (archivo == nullptr) return 0;
    fseek(archivo, 0, SEEK_END);
    int cant = ftell(archivo) / sizeof(Compras);
    fclose(archivo);
    return cant;
}





int ComprasArchivo::buscarFechadecompra(int fechadia, int fechaMes, int fechaAnio){
FILE *archivo;
 Compras Com;
 archivo= fopen (_nombreArchivo.c_str() , "rb");
 bool encontrado=false;
 if (archivo==nullptr){
    return -1;
 }


 int posicion=0;
 while (fread (&Com,sizeof (Compras), 1, archivo)==1){

    if (Com.getFecha().getDia()==fechadia && Com.getFecha().getMes()==fechaMes && Com.getFecha().getAnio()==fechaAnio){


        fclose (archivo);
        encontrado=true;


        return posicion;
    }

    posicion++;
 }
 fclose (archivo);

 if(encontrado==false){
 cout << "Esta fecha NO EXISTE en el sistema" << endl;
 return -11;
 }


}



int ComprasArchivo::buscaridCompra(std::string idCompra){
 FILE *pFile;
 Compras Com;
 bool encontrado=false;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    return -1;
 }
 int posicion=0;
 while (fread (&Com,sizeof (Compras), 1, pFile)==1){

    if (Com.getIDProd()==idCompra){
        fclose (pFile);
        encontrado=true;
        return posicion;

    }

    posicion++;
 }
 fclose (pFile);

 if(encontrado==false){
    cout << "este ID NO EXISTE en el sistema" << endl;
    return posicion=-11;
 }

 }



 float ComprasArchivo::buscarImportecompra(float importeCompra){
 FILE *pFile;
 Compras Com;
 bool encontrado=false;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    return -1;
 }
 int posicion=0;
 while (fread (&Com,sizeof (Compras), 1, pFile)==1){

    if (Com.getImporte()==importeCompra){
        fclose (pFile);
        encontrado=true;
        return posicion;

    }

    posicion++;
 }
 fclose (pFile);

 if(encontrado==false){
    cout << "este ID NO EXISTE en el sistema" << endl;
    return posicion=-11;
 }
 }


bool ComprasArchivo::leerMuchos(Compras reg[], int cantidad){
 FILE *pFile;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }

fread(reg, sizeof(Compras), cantidad, pFile);
fclose(pFile);
 return true;
}
