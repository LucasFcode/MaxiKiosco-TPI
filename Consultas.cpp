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
        cout << "3. Buscar compras en el mes " << endl;
        cout << "4. Ver compras a un proveedor " << endl;
        cout << "5. Proveedores activos " << endl;
        cout << "6. Productos activos " << endl;
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
                mostrarComprasdelmes();
                break;
            case 4:
                mostrarComprasaunProveedor();
                break;
            case 5:
                mostrarProveedoresActivos();
                break;
            case 6:
                mostrarProductosActivos();
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



void Consultas::mostrarComprasdelmes(){
int mes;
ComprasArchivo dat;
int cantidad = dat.getCantidadRegistros();

Compras *vecCompras;

vecCompras = new Compras [cantidad];

dat.leerMuchos(vecCompras, cantidad);

cout<<"Ingrese numero de mes"<< endl;

cin >> mes;

cout<<" Compras realizadas del mes :"<< mes <<endl;

for (int o=0; o<cantidad; o++){

        if(vecCompras[o].getFecha().getMes()==mes){


    cout<<vecCompras[o].getIdCompra()<<endl<<endl;


}
}

 cout<< "*************************************************"<<endl;
delete [] vecCompras;
}

void Consultas::mostrarComprasaunProveedor(){
string prov;
ComprasArchivo dat;
int cantidad = dat.getCantidadRegistros();

Compras *vecCompras;

vecCompras = new Compras [cantidad];

dat.leerMuchos(vecCompras, cantidad);

cout<<"Ingrese proveedor"<< endl;

 cin.ignore();
 getline(cin, prov);


for (int o=0; o<cantidad; o++){

        if(vecCompras[o].getIdProveedor()==prov){


    cout<<vecCompras[o].getIdCompra()<<endl<<endl;

    cout<<vecCompras[o].getImporte()<<endl<<endl;


}
}

 cout<< "*************************************************"<<endl;
delete [] vecCompras;
}




void Consultas::mostrarProveedoresActivos(){
ProveedorArchivo dat;
int cantidad = dat.getCantidadRegistros();

Proveedores *vecProveedores;

vecProveedores = new Proveedores [cantidad];

dat.leerMuchos(vecProveedores, cantidad);
 cout<< "=================================="<<endl;
for (int o=0; o<cantidad; o++){
if(vecProveedores[o].getEstado()==true){

    cout<<" PROVEEDOR ACTIVO :   "<<vecProveedores[o].getNombre()<<endl;

}

}
delete [] vecProveedores;
}
///****************************************************************************************************************************

void Consultas::mostrarProductosActivos(){
ProductosArchivo dat;
int cantidad = dat.cantidadTotalProductos();

Productos *vecProductos;

vecProductos = new Productos [cantidad];

dat.leerMuchos(vecProductos, cantidad);
cout<< "=================================="<<endl;

for (int o=0; o<cantidad; o++){

        if(vecProductos[o].getEstado()==true){


    cout<<" PRODUCTO ACTIVO :"<<vecProductos[o].getnombreProducto()<<endl;


}
}
delete [] vecProductos;
}

