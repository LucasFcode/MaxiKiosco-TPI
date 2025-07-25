#pragma once

class informes {
public:
    void mostrarMenu();
    void productosConMasStock();
    void productosConMenosStock();
    //void comprasPorMes();
    void productosStockBajo(int umbral = 5);
    void cantidadProductosActivosInactivos();
    //void totalGastadoPorMes();
    //void proveedorMasCompras();
    //void top3ProveedoresMasFrecuentes();
    //void cantidadProveedoresActivosInactivos();
    int ingreseUmbral();
    //void Listardatos();  // sacar despues
};
