#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include "Usuario_maestro.h"
#include "Productos.h"
#include "ProductosArchivo.h"
#include "ProveedorArchivo.h"
#include "ComprasArchivo.h"
#include "Fecha.h"
#include "Compras.h"
#include "ComprasArchivo.h"

void Usuario_maestro::cargarProducto (){

    Productos prodCarga;
    ProductosArchivo registro;

string IDProducto, nombreProducto, tipoProducto;
float precioUnitario;
bool caso1, caso2, caso3, caso4, caso5;

 cout <<"Ingrese ID Producto"<<endl;
 cin.ignore();
 getline(cin, IDProducto);
 caso1=prodCarga.setIDProducto(IDProducto);

cout << "Ingrese Nombre Producto"<< endl;
getline(cin, nombreProducto);
caso2=prodCarga.setnombreProducto(nombreProducto);

cout <<"Ingrese tipo de producto"<< endl;
getline(cin, tipoProducto);
caso3=prodCarga.settipoProducto(tipoProducto);



cout << "Ingrese precio Unitario"<< endl;
while (!(cin >> precioUnitario)) {
        cout << "Entrada no valida. Por favor ingresa un numero: "<<endl;
        cin.clear();
        cin.ignore();
    }
caso4=prodCarga.setprecioUnitario(precioUnitario);



if (caso1 && caso2 && caso3 && caso4){

    if (registro.Guardar(prodCarga)){

    cout<< "Se guardo correctamente!"<<endl;
}

}

else {
        cout<<"Error al ingresar datos, intenta realizar la carga nuevamente..."<<endl;
        }
        system ("pause");
        system("cls");
}

void Usuario_maestro::eliminarProducto (){

    Usuario_maestro cargas;
    ProductosArchivo registro;
    Productos setter;

    string idProducto;


 int posicion1;
cout<<"Ingrese ID Producto a eliminar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion1=registro.buscarProducto(idProducto);

    if (posicion1>=0){
        setter.setEstado(false);
        if (registro.Guardar(setter, posicion1)){
            cout<<"Registro eliminado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al eliminar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado... vuelva prontos"<<endl;
    }
    }


void Usuario_maestro::modificarProducto (){

    ProductosArchivo registro;

   string idProducto, nombreProducto, tipoProducto;
    float precioUnitario;
    int stock;



int Opcion;

 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Que registro desea modificar     "<<endl;
        cout << "1. ID Producto"<<endl;
        cout << "2. Nombre Producto"<<endl;
        cout << "3. Tipo Producto"<<endl;
        cout << "4. Precio unitario"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opci¢n:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
        int posicion;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion=registro.buscarProducto(idProducto);

    if (posicion>=0){
            Productos setter= registro.leer(posicion);
            cout<<"Ingrese el nuevo ID :"<<endl;
            getline(cin, idProducto);
            setter.setIDProducto(idProducto);

        if (registro.Guardar(setter, posicion)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }



    break;

   case 2:

         int posicion2;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion2=registro.buscarProducto(idProducto);

    if (posicion2>=0){
            Productos setter= registro.leer(posicion2);
            cout<<"Ingrese el nuevo nombre :"<<endl;
            getline(cin, nombreProducto);
            setter.setnombreProducto(nombreProducto);

        if (registro.Guardar(setter, posicion2)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }



    break;

   case 3:
        int posicion3;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion3=registro.buscarProducto(idProducto);

    if (posicion3>=0){
            Productos setter= registro.leer(posicion3);
            cout<<"Ingrese el nuevo tipo de producto :"<<endl;
            getline(cin, tipoProducto);
            setter.settipoProducto(tipoProducto);

        if (registro.Guardar(setter, posicion)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }


    break;

   case 4:
        int posicion4;
cout<<"Ingrese ID Producto a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProducto);
    posicion4=registro.buscarProducto(idProducto);

    if (posicion4>=0){
            Productos setter= registro.leer(posicion4);
            cout<<"Ingrese el nuevo precio unitario :"<<endl;
            cin>>precioUnitario;
            setter.setprecioUnitario(precioUnitario);

        if (registro.Guardar(setter, posicion4)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado..."<<endl;
    }


    break;

   case 5:

    break;

    default:
        cout << "Elija una opcion valida:" << endl;


}

}while (Opcion != 0);

}



///********************************************************************************************************************************************************


void Usuario_maestro::cargarProveedor(){
    Proveedores proveedor;
    ProveedorArchivo ArchivodeProveedores;
char CUIT_str[30], Nombre_str[30], Telefono_str[30], Email_str[30],Direccion_str[30];
char idProv_str[30];
bool Estado=true;

cout << "Carga de IDProveedor" << endl;
cin >> idProv_str;
proveedor.setidProveedor(idProv_str);
cin.ignore();

cout << "Carga de CUIT" << endl;
cin >> CUIT_str;
proveedor.setCUIT(CUIT_str);

cout << "Carga de Nombre" << endl;
cin >> Nombre_str;
proveedor.setNombre(Nombre_str);

cout << "Carga de Telefono" << endl;
cin >> Telefono_str;
proveedor.setTelefono(Telefono_str);

cout << "Carga de Email" << endl;
cin >> Email_str;
proveedor.setEmail(Email_str);

cout << "Carga de Direccion" << endl;
cin >> Direccion_str;
proveedor.setDireccion(Direccion_str);
proveedor.setEstado(Estado);

proveedor= Proveedores (idProv_str, CUIT_str, Nombre_str, Telefono_str, Email_str, Direccion_str,Estado);


if (ArchivodeProveedores.Guardar(proveedor)){       /// guardo los datos en Proveedores.dat

    cout<< "Se guardo correctamente!" << endl;
}
else{
    cout<<"Hubo un error al realizar la carga" << endl;

}

}

void Usuario_maestro::mostrarProveedoresActivos(Proveedores reg){
bool registro=reg.getEstado();

if(registro==1){
cout<<"**************************************************"<<endl;
cout << "ID Proveedor: " <<reg.getidProveedor() << endl;
cout << "CUIT: " <<reg.getCUIT() << endl;
cout << "Nombre del Proveedor: " << reg.getNombre() << endl;
cout << "Telefono: " << reg.getTelefono() << endl;
cout << "Email: " << reg.getemail() << endl;
cout << "Direccion: " << reg.getDireccion()<< endl;
cout<<"**************************************************"<<endl;
}
else {
    cout<<"No hay registros activos para mostrar..."<<endl;

}

}

void Usuario_maestro::listarProveedores(){
Usuario_maestro mostrarEnLista;
 ProveedorArchivo pProveedores;
 Proveedores registro;

 int cantidadRegistros;

  cantidadRegistros= pProveedores.getCantidadRegistros();
if (cantidadRegistros>0){
    for ( int i=0; i< cantidadRegistros; i++){

    registro=pProveedores.leerUno(i);

mostrarEnLista.mostrarProveedoresActivos(registro);

  }

}
 else {
        cout<<"No hay registros para mostrar"<<endl;

    }

}


void Usuario_maestro::eliminarProveedores (){

    Usuario_maestro Carga;
    ProveedorArchivo reg;
    Proveedores setter;

    std::string ID_Proveedor;


 int pos1;
cout<<"Ingrese ID del Proveedor a eliminar :"<<endl;
    cin.ignore();
    cin >> ID_Proveedor;
    pos1=reg.buscarProveedor(ID_Proveedor);

    if (pos1>=0){
        setter.setEstado(false);
        if (reg.Guardar(setter, pos1)){
            cout<<"Registro eliminado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al eliminar el registro..."<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado... vuelva prontos"<<endl;
    }
    }


void Usuario_maestro::modificarProveedores (){

    ProveedorArchivo reg;

   string Tel, nombreProveedor, CUIT, e_mail, Direccion,ID_Proveedor;



int Opcion;

 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Que registro desea modificar     "<<endl;
        cout << "1. ID Proveedor"<<endl;
        cout << "2. CUIT"<<endl;
        cout << "3. Nombre del Proveedor"<<endl;
        cout << "4. Telefono"<<endl;
        cout << "5. Email"<<endl;
        cout << "5. Direccion"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
        int Pos;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    cin >> ID_Proveedor;
    Pos=reg.buscarProveedor(ID_Proveedor);

    if (Pos>=0){
            Proveedores setter= reg.leerUno(Pos);
            cout<<"Ingrese el nuevo ID :"<<endl;
            cin >> ID_Proveedor;
            setter.setidProveedor(ID_Proveedor);

        if (reg.Guardar(setter, Pos)){
            cout<<"Registro modificado correctamente..."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado"<<endl;
    }

    break;

   case 2:

         int pos2;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, CUIT);
    pos2=reg.buscarProveedor(CUIT);

    if (pos2>=0){
            Proveedores setter= reg.leerUno(pos2);
            cout<<"Ingrese el nuevo CUIT :"<<endl;
            getline(cin, CUIT);
            setter.setCUIT(CUIT);

        if (reg.Guardar(setter, pos2)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado"<<endl;
    }

    break;

   case 3:
        int pos3;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, nombreProveedor);
    pos3=reg.buscarProveedor(nombreProveedor);

    if (pos3>=0){
            Proveedores setter= reg.leerUno(pos3);
            cout<<"Ingrese el nuevo nombre del proveedor :"<<endl;
            getline(cin, nombreProveedor);
            setter.setNombre(nombreProveedor);

        if (reg.Guardar(setter, pos3)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }

}
    else {
        cout<<"No existe el ID buscado"<<endl;
    }


    break;

   case 4:
        int pos4;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, Tel);
    pos4=reg.buscarProveedor(Tel);

    if (pos4>=0){
            Proveedores setter= reg.leerUno(pos4);
            cout<<"Ingrese el nuevo telefono :"<<endl;
            getline(cin, Tel);
            setter.setTelefono(Tel);

        if (reg.Guardar(setter, pos4)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado"<<endl;
    }


    break;

   case 5:
         int pos5;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, e_mail);
    pos5=reg.buscarProveedor(e_mail);

    if (pos5>=0){
            Proveedores setter= reg.leerUno(pos5);
            cout<<"Ingrese el nuevo email :"<<endl;
            getline(cin, e_mail);
            setter.setEmail(e_mail);

        if (reg.Guardar(setter, pos5)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado"<<endl;
    }


    break;

    case 6:
         int pos6;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, Direccion);
    pos6=reg.buscarProveedor(Direccion);

    if (pos6>=0){
            Proveedores setter= reg.leerUno(pos6);
            cout<<"Ingrese la nueva direccion :"<<endl;
            getline(cin, Direccion);
            setter.setDireccion(Direccion);

        if (reg.Guardar(setter, pos6)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
    }
    else {
        cout<<"No existe el ID buscado"<<endl;
    }


    break;

    default:
        cout << "Elija una opcion valida:" << endl;


}

}while (Opcion != 0);

}

///****************************************************************************************************************
void Usuario_maestro::cargarCompras(){


string idProd, idProv;
Fecha Hfecha;
int estado, cantidad1, cantidad2, cantidadCompra;
float Importe, Importetotal;

ProductosArchivo cant;
Compras compra;
ComprasArchivo Arch;
ProveedorArchivo reg;

cantidad1=cant.cantidadTotalProductos();
Productos *vecProductos;

vecProductos = new Productos [cantidad1];

cant.leerMuchos(vecProductos, cantidad1);

cout << "Carga ID del producto" << endl;
cin.ignore();
getline(cin,idProd);

for (int o=0; o<cantidad1; o++){

        if(vecProductos[o].getIDProducto()==idProd){


    cout<<"El producto es  : "<<vecProductos[o].getnombreProducto()<<endl;


}
}


cout << "Carga ID de Proveedor" << endl;
getline(cin,idProv);

cantidad2=reg.getCantidadRegistros();
Proveedores *vecProveedores;

vecProveedores = new Proveedores [cantidad2];

reg.leerMuchos(vecProveedores, cantidad2);
for (int o=0; o<cantidad2; o++){

        if(vecProveedores[o].getidProveedor()==idProv){


    cout<<"El proveedor es  : "<<vecProveedores[o].getNombre()<<endl;


}
}


cout << "Carga de Fecha" << endl;
Hfecha.Cargar();

cout << "Cargar cantidad" << endl;
while (!(cin >> cantidadCompra)) {
        cout << "Entrada no valida. Por favor ingresa un numero: "<<endl;
        cin.clear();
        cin.ignore();
    }


for (int o=0; o<cantidad1; o++){

        if(vecProductos[o].getIDProducto()==idProd){


    Importe= vecProductos[o].getprecioUnitario();


}
}
Importetotal=Importe*cantidadCompra;

cout<<"El importe total es "<<Importetotal<<endl;


cout<<"Ingresar OK=1, NO=0"<< endl;
cin>>estado;

compra= Compras (idProd, idProv, Hfecha, Importetotal, estado);


if (Arch.guardar(compra)){

    cout<< "Se guardo correctamente!"<<endl;
}


else {
        cout<<"Error al ingresar datos, intenta realizar la carga nuevamente..."<<endl;
        }
        system ("pause");
        system("cls");


delete [] vecProductos;
delete [] vecProveedores;
}

void Usuario_maestro::mostrarcomprasActivas(Compras reg){
bool registro=reg.getActivo();

if(registro==1){
cout<<"**************************************************"<<endl;
cout << "ID de Compra: " <<reg.getIDProd() << endl;
cout << "ID de Proveedor: " <<reg.getIdProveedor() << endl;
cout << "Fecha de la compra: " << reg.getFecha().toString() << endl;
cout << "Importe: " << reg.getImporte() << endl;
cout<<"**************************************************"<<endl;
}
else {
    cout<<"No hay registros activos para mostrar..."<<endl;
}

}

/*
void Usuario_maestro::eliminarCompra (){
Usuario_maestro cargas;
    ComprasArchivo registro;
    Compras setter;

    string idCompra;


 int posicion1;
cout<<"Ingrese ID de compra a eliminar :"<<endl;
    cin.ignore();
    getline(cin, idCompra);
    posicion1=registro.buscaridCompra(idCompra);

    if (posicion1>=0){
        setter.setActivo(false);
        if (registro.guardar(setter)){
            cout<<"Registro eliminado correctamente..."<<endl;
            system("pause");
        }
        else{
            cout<<"Hubo un error al eliminar el registro..."<<endl;
            system("pause");
        }
    }
}

void Usuario_maestro::modificarCompra (){

    ComprasArchivo reg;

   string idCompra, idProv;
    float Importe;
    Fecha fec;


int Opcion;

 do{
  cout<<"---------------------------------------------------"<<endl;
        cout << "      Que registro desea modificar     "<<endl;
        cout << "1. ID de Compra"<<endl;
        cout << "2. id de Proveedor"<<endl;
        cout << "3. Importe"<<endl;
        cout << "4. Fecha de ingreso"<<endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion:  ";
  cin >> Opcion;

      switch(Opcion){
   case 1:
        int Pos;
cout<<"Ingrese ID de la compra a modificar :"<<endl;
    cin.ignore();
    cin >> idCompra;
    Pos=reg.buscaridCompra(idCompra);

    if (Pos>=0){
            Compras setter= reg.leerUno(Pos);
            cout<<"Ingrese el nuevo ID :"<<endl;
            cin >> idCompra;
            setter.setIdProd(idCompra);

        if (reg.guardar(setter)){
            cout<<"Registro modificado correctamente..."<<endl;
            system("pause");
        }
        else{
            cout<<"Hubo un error al modificar el registro..."<<endl;
        system("pause");
        }

}

    break;

   case 2:

         int pos2;
cout<<"Ingrese ID del proveedor a modificar :"<<endl;
    cin.ignore();
    getline(cin, idProv);
    pos2=reg.buscaridCompra(idProv);

    if (pos2>=0){
            Compras setter= reg.leerUno(pos2);
            cout<<"Ingrese el id del proveedor :"<<endl;
            getline(cin, idProv);
            setter.setIdProveedor(idProv);

        if (reg.guardar(setter)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
system("pause");
}

    break;

   case 3:
        int pos3;
cout<<"Ingrese importe a modificar :"<<endl;
    cin.ignore();
    cin >> Importe;
    pos3=reg.buscarImportecompra(Importe);

    if (pos3>=0){
            Compras setter= reg.leerUno(pos3);
            cout<<"Ingrese el nuevo Importe :"<<endl;
            cin >> Importe;
            setter.setImporte(Importe);

        if (reg.guardar(setter)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
}
system("pause");

    break;

   case 4:
        int pos4;
        int dia, mes,anio;
cout<<"Ingrese fecha a modificar :"<<endl;
    cin.ignore();
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    pos4=reg.buscarFechadecompra(dia,mes,anio);

    if (pos4>=0){
            Compras setter= reg.leerUno(pos4);
            cout<<"Ingrese la nueva fecha :"<<endl;

    fec.Cargar();

            setter.setFecha(fec);

        if (reg.guardar(setter)){
            cout<<"Registro modificado correctamente"<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro"<<endl;
        }
        system("pause");
    }

    break;


    default:
        cout << "Elija una opcion valida:" << endl;

system("pause");
}

}while (Opcion != 0);
}*/

void Usuario_maestro::listarcompras(){
Usuario_maestro mostrarEnLista;
 ComprasArchivo Archicom;
 Compras registro;

 int cantidadRegistros;

  cantidadRegistros= Archicom.getCantidadRegistros();
if (cantidadRegistros>0){
    for ( int i=0; i< cantidadRegistros; i++){

    registro=Archicom.leerUno(i);

mostrarEnLista.mostrarcomprasActivas(registro);

  }

}
 else {
        cout<<"No hay registros para mostrar"<<endl;
    }
system("pause");
}
