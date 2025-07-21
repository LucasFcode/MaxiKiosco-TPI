#include <iostream>
using namespace std;
#include "ProveedorArchivo.h"


ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
_nombreArchivo=nombreArchivo;
}

ProveedorArchivo::ProveedorArchivo(){
_nombreArchivo="Proveedores.dat";
}

 Proveedores ProveedorArchivo::leerUno(int pos){
 FILE *ProvArchivo = fopen(_nombreArchivo.c_str(), "rb");
 if(ProvArchivo==NULL){
    cout << "FALLA en el ingreso al archivo" << endl;
 }
 Proveedores maxi;
 fseek(ProvArchivo,sizeof(Proveedores)*pos,SEEK_SET);
 fread(&maxi,sizeof(Proveedores),1,ProvArchivo);
 fclose(ProvArchivo);
 return maxi;
 }


 bool ProveedorArchivo::Guardar (Proveedores PROV, int Maxi){
 bool guardado;
 FILE *Provfile;

 Provfile = fopen (_nombreArchivo.c_str(), "rb+");

 if (Provfile== nullptr){
    return false;
 }

 fseek (Provfile, sizeof(Proveedores)*Maxi, SEEK_SET);
 guardado =fwrite(&PROV, sizeof(Proveedores), 1, Provfile);

 fclose(Provfile);

 return guardado;
 }



bool ProveedorArchivo::Guardar(Proveedores maxi){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"ab");
if(ProvArchivo==NULL){
        return false;
    }
bool Archi= fwrite(&maxi,sizeof(Proveedores),1, ProvArchivo);
fclose(ProvArchivo);
return Archi;
    }


bool ProveedorArchivo::Modificar(Proveedores maxi, int pos){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb+");
if(ProvArchivo==NULL){
    return false;
}
fseek(ProvArchivo,sizeof(Proveedores)* pos,SEEK_SET);
bool Modif = fwrite(&maxi,sizeof(Proveedores),1,ProvArchivo);
fclose(ProvArchivo);
return Modif;
    }



void ProveedorArchivo::setregActivo(bool estado){
_registroActivo=estado;
}
bool ProveedorArchivo::getregActivo(){
return _registroActivo;
}


int ProveedorArchivo::listarTodos() {
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");
    int TotalActivos=0;
    if (archivo == nullptr) return 0;
    Proveedores maxi;
    while (fread(&maxi, sizeof(Proveedores), 1, archivo)) {
        if (maxi.getEstado()) {
           cout << "======================================" << endl<<endl;
            maxi.Mostrar();
            TotalActivos++;
        }
    }
    fclose(archivo);
    return TotalActivos;
}



int ProveedorArchivo::getCantidadRegistros(){
FILE *ProvArchivo = fopen(_nombreArchivo.c_str(),"rb");
if(ProvArchivo==NULL){
    return 0;
}
fseek(ProvArchivo,0,SEEK_END);
int cantRegistros= ftell(ProvArchivo) / sizeof(Proveedores);
fclose(ProvArchivo);
return cantRegistros;
}


int ProveedorArchivo::buscarProveedor(std::string IDproveedor){
 FILE *ProvArchivo;
 Proveedores Prov;
 bool encontrado=false;
 ProvArchivo= fopen (_nombreArchivo.c_str() , "rb");
 if (ProvArchivo==nullptr){

    cout << "hubo un error al ingresar a buscarProveedor/ProveedorArchivo" << endl;
 }
 int pos=0;
 while (fread (&Prov,sizeof (Proveedores), 1, ProvArchivo)==1){

    if (Prov.getidProveedor()==IDproveedor){
        fclose (ProvArchivo);
        encontrado=true;
        return pos;

    }

    pos++;
 }
 fclose (ProvArchivo);

 if(encontrado==false){
    cout << "este ID NO EXISTE en el sistema" << endl;
    return pos=-11;
 }

 }

 int ProveedorArchivo::buscarProveedornombre(std::string nombreProveedor){
 FILE *ProvArchivo;
 Proveedores Prov;
 bool encontrado=false;
 ProvArchivo= fopen (_nombreArchivo.c_str() , "rb");
 if (ProvArchivo==nullptr){

    cout << "hubo un error al ingresar a buscarProveedor/ProveedorArchivo" << endl;
 }
 int pos=0;
 while (fread (&Prov,sizeof (Proveedores), 1, ProvArchivo)==1){

    if (Prov.getNombre()==nombreProveedor){
        fclose (ProvArchivo);
        encontrado=true;
        return pos;

    }

    pos++;
 }
 fclose (ProvArchivo);

 if(encontrado==false){
    cout << "este Nombre NO EXISTE en el sistema" << endl;
    return pos=-11;
 }

 }


 bool ProveedorArchivo::leerMuchos(Proveedores reg[], int cantidad){
 FILE *pFile;

 pFile= fopen (_nombreArchivo.c_str(), "rb");

 if (pFile == nullptr){

    return reg;
 }

fread(reg, sizeof(Proveedores), cantidad, pFile);
fclose(pFile);
 return true;
}
