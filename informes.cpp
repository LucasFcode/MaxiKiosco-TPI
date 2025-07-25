#include <iostream>
#include <cstring>
using namespace std;

#include "informes.h"
#include "Productos.h"
#include "ProductosArchivo.h"
#include "Compras.h"
#include "ComprasArchivo.h"
#include "ProveedorArchivo.h"

void informes::mostrarMenu() {
    int opcion;

    do {
        cout << "--- Menu Informes ---" << endl;
        cout << "1. Producto con mas stock" << endl;
        cout << "2. Producto con menos stock" << endl;
        //cout << "3. Compras por anio y mes" << endl;
        cout << "3. Productos con stock bajo" << endl;
        cout << "4. Cantidad productos activos/inactivos" << endl;
        //cout << "5. Total gastado por anio y mes" << endl;
        //cout << "6. Proveedor con mas compras por cantidad y monto" << endl;
        //cout << "7. Top 3 proveedores mas frecuentes" << endl;
        //cout << "9. Cantidad proveedores activos/inactivos" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: productosConMasStock(); break;
            case 2: productosConMenosStock(); break;
            case 3: {
                int umbral= ingreseUmbral();
                productosStockBajo(umbral);
                break;
            } //comprasPorMes(); break;
            case 4: cantidadProductosActivosInactivos(); break;
            //case 5: totalGastadoPorMes(); break;
            //case 6: proveedorMasCompras(); break;
            //case 7: top3ProveedoresMasFrecuentes(); break;
            /*case 8: cantidadProveedoresActivosInactivos(); break;
            case 9: */
            case 0:
            cout << "Saliendo del menu Informes..." << endl;
            break;
            default: cout << "Opcion invalida.\n";
        }
        cout << "\nPresione ENTER para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (opcion != 0);
}


void informes::productosConMasStock() { /// opcion 1
    ProductosArchivo arch;
    Productos prod;
    int cant = arch.cantidadTotalProductos();
    int maxStock = -1;
    string nombreMax;

    for (int i = 0; i < cant; i++) {
        prod = arch.leer(i);
        if (prod.getEstado() && prod.getstock() > maxStock) {
            maxStock = prod.getstock();
            nombreMax = prod.getnombreProducto();
        }
    }
    cout << "Producto con mas stock: " << nombreMax << " y tiene: " << maxStock << " unidades" << endl;
}

void informes::productosConMenosStock() { /// opcion 2
    ProductosArchivo arch;
    Productos prod;
    int cant = arch.cantidadTotalProductos();
    int minStock = -1;
    string nombreMin;
    bool primero = true;

    for (int i = 0; i < cant; i++) {
        prod = arch.leer(i);
        if (prod.getEstado()) {
            if (primero) {
                minStock = prod.getstock();
                nombreMin = prod.getnombreProducto();
                primero = false;
            } else if (prod.getstock() < minStock) {
                minStock = prod.getstock();
                nombreMin = prod.getnombreProducto();
            }
        }
    }
    cout << "Producto con menos stock: " << nombreMin << " y tiene: " << minStock << " unidades" << endl;
}

/*
void informes::comprasPorMes() { /// opcion 3
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    Compras comp;

    // Primero: armar arrays para guardar año y mes únicos
    const int MAX = 12;
    int anios[MAX], meses[MAX];
    int count = 0;

    // Recorrer todas las compras y guardar año y mes si no estaban antes
    for (int i = 0; i < cant; i++) {
        comp = arch.leerUno(i);
        if (!comp.getActivo()) continue;

        int anio = comp.getFecha().getAnio();
        int mes = comp.getFecha().getMes();

        // Verificar si ya existe
        bool existe = false;
        for (int j = 0; j < count; j++) {
            if (anios[j] == anio && meses[j] == mes) {
                existe = true;
                break;
            }
        }
        if (!existe) {
            anios[count] = anio;
            meses[count] = mes;
            count++;
        }
    }

    // Mostrar al usuario
    if (count > 0) {
        cout << "Anios y meses con compras registradas:" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Anio: " << anios[i] << ", Mes: " << meses[i] << endl;
        }
    } else {
        cout << "No hay compras registradas." << endl;
        return;
    }

    int anioConsulta, mesConsulta;
    cout << "Ingrese anio: ";
    cin >> anioConsulta;
    cout << "Ingrese mes: ";
    cin >> mesConsulta;
    cout<<endl;
    cout << "------------------------" ;

    bool hay = false;
    for (int i = 0; i < cant; i++) {
        comp = arch.leerUno(i);
        if (comp.getActivo() && comp.getFecha().getAnio() == anioConsulta && comp.getFecha().getMes() == mesConsulta) {
            comp.mostrar();
            hay = true;
        }
    }

    if (!hay) {
        cout << "No hay compras registradas en " << mesConsulta << "/" << anioConsulta << endl;
    }
}

*/
int informes::ingreseUmbral(){ // opcion 4
    int umbral=1;
    do {
        cout << "Ingrese el umbral para consultar(debe ser mayor a 0): ";
        cin >> umbral;
        if (umbral <= 0) {
            cout << "ERROR: El umbral debe ser mayor a 0."<<endl;
        }
    } while(umbral<=0);
    return umbral;

}
void informes::productosStockBajo(int umbral) { // opcion 4

    ProductosArchivo arch;
    Productos prod;
    int cant = arch.cantidadTotalProductos();
    cout << "Productos con stock menor a " << umbral << ":" << endl;

    for (int i = 0; i < cant; i++) {
        prod = arch.leer(i);
        if (prod.getEstado() && prod.getstock() <= umbral) {
            arch.mostrarProductosActivos(prod);
        }
    }
}

void informes::cantidadProductosActivosInactivos() { // opcion 5
    ProductosArchivo arch;
    Productos prod;
    int cant = arch.cantidadTotalProductos();
    int act = 0, inact = 0;

    for (int i = 0; i < cant; i++) {
        prod = arch.leer(i);
        if (prod.getEstado()) act++;
        else inact++;
    }

    cout << "Productos activos: " << act << endl;
    cout << "Productos dados de baja: " << inact << endl;
}
/*
void informes::totalGastadoPorMes() { // opcoin 6
    ComprasArchivo arch;
    int anio, mes;
    cout << "Ingrese anio: ";
    cin >> anio;
    cout << "Ingrese mes: ";
    cin >> mes;

    int cant = arch.getCantidadRegistros();
    Compras comp;
    float total = 0;

    for (int i = 0; i < cant; i++) {
        comp = arch.leerUno(i);
        if (comp.getActivo() && comp.getFecha().getAnio() == anio && comp.getFecha().getMes() == mes) {
            total += comp.getImporte();
        }
    }

    cout << "Total gastado en " << mes << "/" << anio << ": $" << total << endl;
}
*/

/*
void informes::proveedorMasCompras() { // opcion 7
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay compras registradas.\n";
        return;
    }

    string* ids = new string[cant];
    int* cantidades = new int[cant];
    float* montos = new float[cant];
    int n = 0;

    Compras comp;

    for (int i = 0; i < cant; i++) {
        comp = arch.leerUno(i);
        if (!comp.getActivo()) continue;
        string id = comp.getIdProveedor();
        bool encontrado = false;
        for (int j = 0; j < n; j++) {
            if (ids[j] == id) {
                cantidades[j]++;
                montos[j] += comp.getImporte();
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            ids[n] = id;
            cantidades[n] = 1;
            montos[n] = comp.getImporte();
            n++;
        }
    }

    int maxCant = -1;
    string idMaxCant;
    float maxMonto = -1;
    string idMaxMonto;

    for (int i = 0; i < n; i++) {
        if (cantidades[i] > maxCant) {
            maxCant = cantidades[i];
            idMaxCant = ids[i];
        }
        if (montos[i] > maxMonto) {
            maxMonto = montos[i];
            idMaxMonto = ids[i];
        }
    }

    cout << "Proveedor con mas compras por cantidad - ID: " << idMaxCant << " - Cantidad: " << maxCant << endl;
    cout << "Proveedor con mas compras por monto - ID: " << idMaxMonto << " - Monto: $ " << maxMonto << endl;

    delete[] ids;
    delete[] cantidades;
    delete[] montos;
}

void informes::top3ProveedoresMasFrecuentes() { /// opcion 8
    ComprasArchivo arch;
    int cant = arch.getCantidadRegistros();
    if (cant == 0) {
        cout << "No hay compras registradas.\n";
        return;
    }

    string* ids = new string[cant];
    int* cantidades = new int[cant];
    int n = 0;

    Compras comp;

    for (int i = 0; i < cant; i++) {
        comp = arch.leerUno(i);
        if (!comp.getActivo()) continue;
        string id = comp.getIdProveedor();
        bool encontrado = false;
        for (int j = 0; j < n; j++) {
            if (ids[j] == id) {
                cantidades[j]++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            ids[n] = id;
            cantidades[n] = 1;
            n++;
        }
    }

    // aplico metodo burbuja descendente
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cantidades[j] < cantidades[j + 1]) {
                int auxCant = cantidades[j];
                cantidades[j] = cantidades[j + 1];
                cantidades[j + 1] = auxCant;

                string auxId = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = auxId;
            }
        }
    }

    cout << "Top 3 proveedores mas frecuentes de mayor a menor:" << endl;
    for (int i = 0; i < n && i < 3; i++) {
        cout << i + 1 << ". " << "ID: "<< ids[i] << " - Pedidos: " << cantidades[i] << " compras" << endl;
    }

    delete[] ids;
    delete[] cantidades;
}
/*
void informes::cantidadProveedoresActivosInactivos() { //opcion 9
    FILE* archivo = fopen("Proveedores.dat", "rb");
    if (archivo == nullptr) {
        cout << "No se pudo abrir el archivo de proveedores" << endl;
        return;
    }
    Proveedores prov;
    int act = 0, inact = 0;
    while (fread(&prov, sizeof(Proveedores), 1, archivo) == 1) {
        if (prov.getEstado()) act++;
        else inact++;
    }
    fclose(archivo);

    cout << "Proveedores activos: " << act << endl;
    cout << "Proveedores inactivos: " << inact << endl;
}


void informes::Listardatos(){
    cout<<"aun no implementado";
};
*/
