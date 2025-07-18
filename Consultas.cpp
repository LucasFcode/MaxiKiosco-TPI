#include <iostream>
using namespace std;
#include "Consultas.h"
#include "ProductosArchivo.h"
#include "ProveedorArchivo.h"
#include "ComprasArchivo.h"



Consultas::Consultas(){
};

float precioUnitario;
void Consultas::menuconsultas(){

    int opcion;

    do {
        cout << "\n--- Menu Consultas ---" << endl;
        cout << "1. Productos con precio menor a " << endl;
        cout << "2. Stock Productos menores a " << endl;
        cout << "3. Proveedores " << endl;
        cout << "4. Buscar compras entre fechas " << endl;
        cout << "5. Ver compras de un producto " << endl;
        cout << "6. Ver compras de un proveedor " << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
               mostrarProductosprecios();

                break;
            case 2:
               mostrarstockProductos();

                break;
            case 3:
                ;
                break;
            case 4:
                ;
                break;
            case 5:
                ;
                break;
            case 6:
                ;
                break;

            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);

    }

void Consultas::mostrarProductosprecios(){
ProductosArchivo dat;
int cantidad = dat.cantidadTotalProductos();

Productos *vecProductos;

vecProductos = new Productos [cantidad];

dat.leerMuchos(vecProductos, cantidad);

cout << "Ingrese precio Unitario"<< endl;
while (!(cin >> precioUnitario)) {
        cout << "Entrada no v lida. Por favor ingresa un n£mero: "<<endl;
        cin.clear();
        cin.ignore();
    }

for (int o=0; o<cantidad; o++){

        if(vecProductos[o].getprecioUnitario()<precioUnitario){

    cout<< "*************************************************"<<endl;
    cout<<" Productos menores al precio unitario ingresado :"<<vecProductos[o].getnombreProducto()<<endl;


}
}
delete [] vecProductos;
}

void Consultas::mostrarstockProductos(){
int stockMenor;
ProductosArchivo dat;
int cantidad = dat.cantidadTotalProductos();

Productos *vecProductos;

vecProductos = new Productos [cantidad];

dat.leerMuchos(vecProductos, cantidad);

cout<<"Ingrese stock"<< endl;
while (!(cin >> stockMenor)) {
        cout << "Entrada no v lida. Por favor ingresa un n£mero: "<<endl;
        cin.clear();
        cin.ignore();
    }
cout<<" Productos menores al numero de stock ingresado :"<<endl;
for (int o=0; o<cantidad; o++){

        if(vecProductos[o].getstock()<stockMenor){


    cout<<vecProductos[o].getnombreProducto()<<endl<<endl;


}
}

 cout<< "*************************************************"<<endl;
delete [] vecProductos;
}
/*
void Consultas::mostrarProveedoresActivos(){
ProveedorArchivo dat;
int cantidad = dat.getCantidadRegistros();

Proveedores *vecProveedores;

vecProveedores = new Proveedores [cantidad];

dat.leerMuchos(vecProveedores, cantidad);

for (int o=0; o<cantidad; o++){
if(vecProveedores[o].getEstado()==true){
    cout<< "=================================="<<endl;
    cout<<" PROVEEDOR ACTIVO :   "<<vecProveedores[o].getNombre()<<"||   TELEFONO    "<<vecProveedores[o].getTelefono()<<endl;

}

}
}
///****************************************************************************************************************************

void Consultas::mostrarProductosActivos(){
ProductosArchivo dat;
int cantidad = dat.cantidadTotalProductos();

Productos *vecProductos;

vecProductos = new Productos [cantidad];

dat.leerMuchos(vecProductos, cantidad);

for (int o=0; o<cantidad; o++){

        if(vecProductos[o].getEstado()==true){

    cout<< "=================================="<<endl;
    cout<<" PRODUCTO ACTIVO :"<<vecProductos[o].getnombreProducto()<<" STOCK "<<vecProductos[o].getstock()<<endl;


}
}
delete [] vecProductos;
}

*/
