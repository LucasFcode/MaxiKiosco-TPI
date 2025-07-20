#include <iostream>
#include "MENUcompras.h"
#include "Usuario_maestro.h"
using namespace std;

void MENUcompras::Mos(){

Usuario_maestro Cargacompra;
int Opcion;
 do{
        system("cls");
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Compras     "<<endl;
        cout << "1. Cargar nueva compra"<<endl;
        cout << "2. Listado de compras activas"<<endl;
        cout << "3. Eliminar Compra"<<endl;
        cout << "4. Modificar datos de la compra"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
          Cargacompra.cargarCompras();
    break;

   case 2:
///       Cargacompra.listarcompras();

    break;

   case 3:
     ///  Cargacompra.eliminarCompra();
    break;

   case 4:
     ///  Cargacompra.modificarCompra();
    break;

    default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);




}
