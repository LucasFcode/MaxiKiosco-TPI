#include <iostream>
#include "Listados.h"
#include "Proveedores.h"
#include "Productos.h"
#include "ProductosArchivo.h"
#include "Compras.h"
#include "ComprasArchivo.h"
#include "Fecha.h"
#include "ProveedorArchivo.h"
using namespace std;



void Listados::MENUlistados(){


int Opcion;
 do{
        system("cls");
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Listados     "<<endl;
        cout << "1. Listar productos agrupados"<<endl;
        cout << "2. Busquedas de Productos"<<endl;
        cout << "3. Busquedas de Compras"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
       system("cls");
          listarProductosAgrupados();
    break;

   case 2:
       system("cls");
///       Menu2Productos();
    break;

   case 3:
       system("cls");
      /// Menu3Compras();
    break;

   case 0:

    break;

    default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);

}


void Listados::listarProductosAgrupados() {
    ProductosArchivo archivo;
    int total = archivo.cantidadTotalProductos();
    Productos productos[100]; // suponemos que no hay m s de 100 productos
    string tipos[20];        // suponemos hasta 20 tipos distintos
    int cantProductos = 0;
    int cantTipos = 0;

    // Leer todos los productos y guardarlos en el arreglo
    for (int i = 0; i < total; i++) {
        Productos p = archivo.leer(i);
        productos[cantProductos] = p;
        cantProductos++;
    }

    // Buscar tipos £nicos
    for (int i = 0; i < cantProductos; i++) {
        string tipoActual = productos[i].gettipoProducto();
        bool repetido = false;

        for (int j = 0; j < cantTipos; j++) {
            if (tipos[j] == tipoActual) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            tipos[cantTipos] = tipoActual;
            cantTipos++;
        }
    }

    // Mostrar productos agrupados por tipo
    cout << "\n--- Productos agrupados por tipo ---\n";

    for (int i = 0; i < cantTipos; i++) {
        cout << "Tipo: " << tipos[i] << endl;
        cout << "--------------------------" << endl;

        for (int j = 0; j < cantProductos; j++) {
            if (productos[j].gettipoProducto() == tipos[i]) {
                productos[j].mostrarProd();
            }
        }
    }
    system ("pause");
        system("cls");
}




/*

void Listados::Menu1Proveedores(){
int Opc;
do{
cout << "---------- Listados de Proveedores ----------" << endl;
cout << "1- Busqueda por ID" << endl;
cout << "2- Busqueda por Nombre" << endl;
cout << "0- Salir" << endl;
cin >> Opc;

switch(Opc){
case 1:
        Orden_ProveedoresID();
    break;
case 2:
        Orden_ProveedoresNombre();
    break;

case 3:
    cout << "Saliendo" << endl;

    break;

default:
    cout << "Elija una opcion valida:" << endl;

}

}while(Opc!=0);


}


void Listados::Menu2Productos(){
int Opc;
do{
cout << "---------- Listados de Productos ----------" << endl;
cout << "1- Busqueda por ID del producto" << endl;
cout << "2- Busqueda por Nombre del producto" << endl;
cout << "3- Mostrar orden de stock de menor a mayor" << endl;
cout << "0- Salir" << endl;
cin >> Opc;

switch(Opc){
case 1:
        Ordenid_Productos();
    break;
case 2:
        OrdenNombre_Productos();
    break;

case 3:
        OrdenCantidad_Productos();

    break;

case 0:
    cout << "Saliendo" << endl;

    break;

default:
    cout << "Elija una opcion valida:" << endl;

}

}while(Opc!=0);

}



void Listados::Menu3Compras(){
    system("cls");
int Opc;
do{
cout << "---------- Listados de Compras ----------" << endl;
cout << "1- Busqueda por fecha de Compra" << endl;
cout << "2- listado en orden por fecha de Compra" << endl;
cout << "3- Mostrar orden de compras de menor a mayor" << endl;
cout << "0- Salir" << endl;
cin >> Opc;

switch(Opc){
case 1:
        Fecha_Compras();
    break;
case 2:
        Fecha_ComprasOrden();
    break;

case 3:
        OrdenImporte_Compras();
    break;

case 0:
        cout << "Saliendo" << endl;
    break;

default:
    cout << "Elija una opcion valida:" << endl;

}

}while(Opc!=0);

}



///Listado Proveedores*****************************************
void Listados::Orden_ProveedoresID(){
system("cls");
Proveedores Usu;
ProveedorArchivo Archi;
string ID;
int Pos=0;

cout << "ingrese ID del Proveedor: ";
cin >> ID;

int Totalreg= Archi.getCantidadRegistros();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(Usu.getEstado()){

        Pos=Archi.buscarProveedor(ID);
        if(Pos>0){
          Archi.leerUno(Pos).Mostrar();
        }

return;

}

}

}


void Listados::Orden_ProveedoresNombre(){
system("cls");
Proveedores Usu;
ProveedorArchivo Archi;
string Nombre;
int Pos=0;

cout << "ingrese Nombre del Proveedor: ";
cin.ignore();
getline(cin, Nombre);

int Totalreg= Archi.getCantidadRegistros();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(Usu.getEstado()){




  Pos=Archi.buscarProveedornombre(Nombre);
        if(Pos>0){
          Archi.leerUno(Pos).Mostrar();
        }

return;

}

}



}

///Listado Productos*********************************************
void Listados::Ordenid_Productos(){
    system("cls");
Productos prod;
ProductosArchivo Archi;
string ID;
int Pos=0;

cout << "ingrese ID del Producto: ";
cin >> ID;

int Totalreg= Archi.cantidadTotalProductos();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(prod.getEstado()){

        Pos=Archi.buscarProducto(ID);

if(Pos>0){
          Archi.leer(Pos).mostrarProd();
}

return;

}

}

}


void Listados::OrdenNombre_Productos(){
    system("cls");
Productos prod;
ProductosArchivo Archi;
string Name;
int Pos=0;

cout << "ingrese nombre del Producto: ";
cin >> Name;

int Totalreg= Archi.cantidadTotalProductos();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(prod.getEstado()){

        Pos=Archi.buscarNombreProducto(Name);
        if(Pos>0){

          Archi.leer(Pos).mostrarProd();
        }

return;

}

}

}

void Listados::OrdenCantidad_Productos(){
 system("cls");
Productos prod;
ProductosArchivo Archi;

int Aux;
int Pos[50]={};
int *listastock=new int [50];


int Totalreg= Archi.cantidadTotalProductos();

for(int i=0;i<Totalreg;i++){
    listastock[i]=Archi.leer(i).getstock();
    Pos[i]=i;

}


for(int j=0;j<Totalreg-1;j++){
for(int i=0;i<Totalreg-1;i++){

if(listastock[i]>listastock[i+1]){
Aux=listastock[i];
listastock[i]=listastock[i+1];
listastock[i+1]=Aux;

Aux=Pos[i];
Pos[i]=Pos[i+1];
Pos[i+1]=Aux;

}
}

}

for(int i=0;i<Totalreg;i++){

cout << "lista stock: " << listastock[i] <<endl;

Archi.leer(Pos[i]).mostrarProd();

}

delete[] listastock;
}


///Listado Compras*********************************************

/*void OrdenProv_Compras(){ /// para revisar es lo mismo que proveedores
Compras Com;
ComprasArchivo Archi;
string Proveedor;
int Pos=0;

cout << "ingrese el Proveedor: ";
cin >> Proveedor;

int Totalreg= Archi.getCantidadRegistros();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(Com.getActivo()){

        Pos=Archi.buscarProveedornombre(Nombre);
        if(Pos>0){
          Archi.leerUno(Pos).Mostrar();
        }

return;

}

}
}


void Listados::Fecha_Compras(){
    system("cls");
Compras Com;
ComprasArchivo Archi;
int fechdia, fechmes, fechanio;
int Pos=0;

cout << "ingrese el dia de la compra: ";
cin >> fechdia;
cout << "ingrese el mes de la compra: ";
cin >> fechmes;
cout << "ingrese el anio de la compra: ";
cin >> fechanio;

int Totalreg= Archi.getCantidadRegistros();
cout << endl;
for(int i=0 ; i<Totalreg; i++){
if(Com.getActivo()){

        Pos=Archi.buscarFechadecompra(fechdia,fechmes,fechanio);
        if(Pos>0){

          Archi.leerUno(Pos).mostrar();
        }

return;

}

}
}



void Listados::Fecha_ComprasOrden(){
    system("cls");
Compras Com;
ComprasArchivo Archi;
Fecha fechas;

int Opc, Aux;



int Totalreg= Archi.getCantidadRegistros();

int *Puntdia= new int[100];
int *Puntmes= new int[100];
int *Puntanio= new int[100];
int regSINbasura=0;

int *fechasordenadas= new int[100];

do{
cout << endl;
cout << "1-Listado desde la ultima fecha " << endl;
cout << "0-Salir " << endl;
cin >> Opc;

switch(Opc){
case 1:

for(int i=0 ; i<Totalreg; i++){

if(Com.getActivo()){

if(Archi.leerUno(i).getFecha().getDia()!=0){
        Puntdia[i]=Archi.leerUno(i).getFecha().getDia();
}

if(Archi.leerUno(i).getFecha().getMes()!=0){
        Puntmes[i]=Archi.leerUno(i).getFecha().getMes();
}

if(Archi.leerUno(i).getFecha().getAnio()!=0){
        Puntanio[i]=Archi.leerUno(i).getFecha().getAnio();
}

        if(Puntanio[i]>0){
        fechasordenadas[i]=Archi.buscarFechadecompra(Puntdia[i],Puntmes[i],Puntanio[i]);

        }

        if(fechasordenadas[i]!=0){
            regSINbasura++;
        }

}

}



int anioAUX,mesAUX,diaAUX;
for(int j=0 ; j<regSINbasura; j++){
for(int i=0 ; i<regSINbasura; i++){


 if(Puntanio[i]<=Puntanio[i+1] && Puntanio[i]>0){/// ordeno años del ultimo a los primeros

Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+1];
 fechasordenadas[i+1]=Aux;

 anioAUX=Puntanio[i];
Puntanio[i]=Puntanio[i+1];
Puntanio[i+1]=anioAUX;

mesAUX=Puntmes[i];
Puntmes[i]=Puntmes[i+1];
Puntmes[i+1]=mesAUX;

diaAUX=Puntdia[i];
Puntdia[i]=Puntdia[i+1];
Puntdia[i+1]=diaAUX;


 }

 if(fechasordenadas[i]==0){
    Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+10];
 fechasordenadas[i+10]=Aux;
 }

}


}



for(int j=0 ; j<regSINbasura; j++){
for(int i=0 ; i<regSINbasura; i++){

 if(Puntmes[i]<=Puntmes[i+1] && Puntmes[i]>0 && Puntanio[i]==Puntanio[i+1]){  /// ordeno meses del ultimo a los primeros
Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+1];
 fechasordenadas[i+1]=Aux;


 anioAUX=Puntanio[i];
Puntanio[i]=Puntanio[i+1];
Puntanio[i+1]=anioAUX;

mesAUX=Puntmes[i];
Puntmes[i]=Puntmes[i+1];
Puntmes[i+1]=mesAUX;

diaAUX=Puntdia[i];
Puntdia[i]=Puntdia[i+1];
Puntdia[i+1]=diaAUX;

if(fechasordenadas[i]==0){
    Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+10];
 fechasordenadas[i+10]=Aux;
 }

 }
}


}


for(int j=0 ; j<regSINbasura; j++){
for(int i=0 ; i<regSINbasura; i++){

if(Puntdia[i]<Puntdia[i+1] && Puntdia[i]>0 && Puntmes[i]==Puntmes[i+1] && Puntanio[i]==Puntanio[i+1]){  /// ordeno dias del ultimo a los primeros
Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+1];
 fechasordenadas[i+1]=Aux;

 anioAUX=Puntanio[i];
Puntanio[i]=Puntanio[i+1];
Puntanio[i+1]=anioAUX;

mesAUX=Puntmes[i];
Puntmes[i]=Puntmes[i+1];
Puntmes[i+1]=mesAUX;

diaAUX=Puntdia[i];
Puntdia[i]=Puntdia[i+1];
Puntdia[i+1]=diaAUX;

if(fechasordenadas[i]==0){
    Aux=fechasordenadas[i];
 fechasordenadas[i]=fechasordenadas[i+10];
 fechasordenadas[i+10]=Aux;
 }


 }
}

 }







for(int i=0 ; i<regSINbasura; i++){ /// muestro todos los datos por fecha
if(Com.getActivo()>0){



        if(fechasordenadas[i]>0){

          Archi.leerUno(fechasordenadas[i]).mostrar();

        }

}
}

///***************************************************************

delete[] Puntdia;
delete[] Puntmes;
delete[] Puntanio;
delete[] fechasordenadas;
    break;

case 0:
        cout << "Saliendo" << endl;
    break;

    default:
    cout << "Elija una opcion valida:" << endl;

}

}while(Opc!=0);


///*******************************


}



void Listados::OrdenImporte_Compras(){
system("cls");
Compras com;
ComprasArchivo Archi;

int Aux;
int Pos[50]={};
int *Importes=new int [50];


int Totalreg= Archi.getCantidadRegistros();

for(int i=0;i<Totalreg;i++){
    Importes[i]=Archi.leerUno(i).getImporte();
    Pos[i]=i;

}


for(int j=0;j<Totalreg-1;j++){
for(int i=0;i<Totalreg-1;i++){

if(Importes[i]<Importes[i+1]){
Aux=Importes[i];
Importes[i]=Importes[i+1];
Importes[i+1]=Aux;

Aux=Pos[i];
Pos[i]=Pos[i+1];
Pos[i+1]=Aux;

}
}

}

for(int i=0;i<Totalreg;i++){

if(Importes[i]>0){

cout << "Importe de la compra: " << Importes[i] <<endl;

Archi.leerUno(Pos[i]).mostrar();
}

}

delete[] Importes;

}
*/

