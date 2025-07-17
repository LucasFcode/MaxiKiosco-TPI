#include "ProductosArchivo.h"
#include "Productos.h"
#include <iostream>
using namespace std;

ProductosArchivo::ProductosArchivo(){
 _nombreArchivo="ProductosArchivo.dat";
}

ProductosArchivo::ProductosArchivo(std::string nombreArchivo){
_nombreArchivo=nombreArchivo;

}
///**************************************************************************************************
bool ProductosArchivo::Guardar (Productos prodP){
 bool seguardo;
 FILE *pFile;

 pFile = fopen (_nombreArchivo.c_str(), "ab");

 if (pFile== nullptr){
    return false;
 }

 seguardo =fwrite(&prodP, sizeof(Productos), 1, pFile);

 fclose(pFile);

 return seguardo;
}

bool ProductosArchivo::Guardar (Productos prodP, int posicion){
 bool seguardo;
 FILE *pFile;

 pFile = fopen (_nombreArchivo.c_str(), "rb+");

 if (pFile== nullptr){
    return false;
 }

 fseek (pFile, sizeof(Productos)*posicion, SEEK_SET);
 seguardo =fwrite(&prodP, sizeof(Productos), 1, pFile);

 fclose(pFile);

 return seguardo;

 }

///**************************************************************************************************

int ProductosArchivo::cantidadTotalProductos (){

int tamRegistro, total, cantidad;

FILE *pFile;

pFile = fopen (_nombreArchivo.c_str(), "rb");

if (pFile==nullptr){

    return 0;
}

fseek (pFile, 0, SEEK_END);

total=ftell (pFile);

tamRegistro= sizeof(Productos);

cantidad = total / tamRegistro;

fclose (pFile);

return cantidad;


}

Productos ProductosArchivo::leer(int pos){

FILE *pFile;

 Productos reg;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }
 fseek (pFile, sizeof (Productos)*pos, SEEK_SET);

 fread(&reg, sizeof(Productos), 1 , pFile);

 fclose(pFile);
 return reg;

}

bool ProductosArchivo::leerMuchos(Productos reg[], int cantidad){
 FILE *pFile;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }

fread(reg, sizeof(Productos), cantidad, pFile);
fclose(pFile);
 return true;
}


///*************************************************************************************************
int ProductosArchivo::buscarProducto(std::string IDProducto){
 FILE *pFile;
 Productos prod;
 bool encontrado=false;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    return -1;
 }
 int posicion=0;
 while (fread (&prod,sizeof (Productos), 1, pFile)==1){

    if (prod.getIDProducto()==IDProducto){
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
 ///******************************************************************
 int ProductosArchivo::buscarNombreProducto(std::string Name){
 FILE *pFile;
 Productos prod;
 bool encontrado=false;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    return -1;
 }
 int posicion=0;
 while (fread (&prod,sizeof (Productos), 1, pFile)==1){

    if (prod.getnombreProducto()==Name){
        fclose (pFile);
        encontrado=true;
        return posicion;

    }
    else{
            cout << "este nombre NO EXISTE en el sistema" << endl;
    return posicion=-11;
    }


    posicion++;
 }
 fclose (pFile);

 if(encontrado==false){
    cout << "este nombre NO EXISTE en el sistema" << endl;
    return posicion=-11;
 }
 }
 ///*************************************************************************************************************************

int ProductosArchivo::buscarStock(std::string Producto){
FILE *pFile;
 Productos prod;
 bool encontrado=false;
 pFile= fopen (_nombreArchivo.c_str() , "rb");
 if (pFile==nullptr){

    return -1;
 }
 int posicion=0;
 while (fread (&prod,sizeof (Productos), 1, pFile)==1){

    if (prod.getIDProducto()==Producto){
        fclose (pFile);
        encontrado=true;
        return posicion;

    }
    else{
            cout << "este nombre NO EXISTE en el sistema" << endl;
    return posicion=-11;
    }


    posicion++;
 }
 fclose (pFile);

 if(encontrado==false){
    cout << "este nombre NO EXISTE en el sistema" << endl;
    return posicion=-11;
 }
}

 void ProductosArchivo::listarProductos(){

 ProductosArchivo pProductos;
 Productos registro;

 int cantidadRegistros;

  cantidadRegistros= pProductos.cantidadTotalProductos();
if (cantidadRegistros>0){
    for ( int i=0; i< cantidadRegistros; i++){

    registro=pProductos.leer(i);

   pProductos.mostrarProductosActivos(registro);


  }


}
 else {
        cout<<"No hay registros para mostrar..."<<endl;
    }

}


 void ProductosArchivo::mostrarProductosActivos(Productos registro){
 bool reg=registro.getEstado();

if(reg){
cout<<"**************************************************"<<endl;
cout << "ID Producto : " <<registro.getIDProducto() << endl;
cout << "Nombre Producto : " << registro.getnombreProducto() << endl;
cout << "Tipo Producto : " << registro.gettipoProducto() << endl;
cout << "Precio Unitario $: " << registro.getprecioUnitario() << endl;
cout << "Stock : " << registro.getstock()<< endl;
cout << "este Producto se encuentra habilitado en el sistema" << endl;
cout<<"**************************************************"<<endl;
}
else {
    cout<<"No hay registros activos para mostrar..."<<endl;
}


 }

 int ProductosArchivo::getNuevoID(){
 return cantidadTotalProductos()+1;

 }

///********************************************************************************************************************
/*
 bool ProductosArchivo::Modificar (Productos mod, int pos){
 Productos mode;

 FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");

 if(pFile==NULL){
        cout<<"No se pudo abrir el archivo";
    return false;
 }
 fseek(pFile,sizeof(ProductosArchivo)* pos,SEEK_SET);///seek_set en clases estaba el 0
 bool Modif = fwrite(&mod,sizeof(ProductosArchivo),1,pFile);
 fclose(pFile);
 return Modif;


 }

bool ProductosArchivo::Eliminar(std::string IDProducto){
    Productos reg;
    ProductosArchivo archi;
    int pos=archi.buscarProducto(IDProducto);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leer(pos);
    ///en reg tengo el registro a borrar
    reg.setEstado(false);

    return archi.Modificar (reg, pos);
}

*/

