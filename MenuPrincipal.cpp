#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "MENUProducto.h"
#include "informes.h"
#include "Consultas.h"
#include "Usuario_maestro.h"
#include "MENUproveedores.h"
#include "MENUcompras.h"
#include "Listados.h"




void MenuPrincipal::mostrar(){

    int opcion;
    MENUProducto cargas;
    MENUproveedores carga2;
    MENUcompras Carga3;
    Listados listas;
    informes inf;
    Consultas con;



    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Productos" << endl;
        cout << "2. Proveedor" << endl;
        cout << "3. Compras" << endl;
        cout << "4. Listados" << endl;
        cout << "5. Consultas" << endl;
        cout << "6. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargas.mostrar();

                break;
            case 2:
                carga2.Mostrar();
                ;
                break;
            case 3:
                Carga3.Mos();
                break;
            case 4:
                listas.MENUlistados();
                break;
            case 5:
                con.menuconsultas();
                break;
            case 6:
                inf.mostrarMenu();
                ;
                break;
            case 0:
                cout<<endl;
                cout << "Adios..." << endl;
                break;

            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 0);

    }


