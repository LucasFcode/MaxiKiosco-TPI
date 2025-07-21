#include <iostream>
#include "MENUProveedores.h"
#include "Usuario_maestro.h"
using namespace std;





void MENUproveedores::Mostrar(){

Usuario_maestro Cargaprov;
int Opcion;
 do{
        system("cls");
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Menu Proveedores     "<<endl;
        cout << "1. Cargar nuevo Proveedor"<<endl;
        cout << "2. Eliminar Proveedor"<<endl;
        cout << "3. Modificar datos del Proveedor"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
       system("cls");
          Cargaprov.cargarProveedor();
          system("pause");
    break;

   /*case 2:
       system("cls");
       Cargaprov.listarProveedores();
       system("pause");
    break;*/

   case 2:
       system("cls");
       Cargaprov.eliminarProveedores();
       system("pause");
    break;

   case 3:
       system("cls");
       Cargaprov.modificarProveedores();
       system("pause");
    break;

    default:
        cout << "Elija una opcion valida:" << endl;

   }

}while (Opcion != 0);




}
