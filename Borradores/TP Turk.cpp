#include <iostream>
#include <array>
#include <cassert>
#include <string>

using namespace std;

using tTableRegion = array<array<array<int,12>,3>,4>; // region(vendedor(mes))

enum struct region{Norte=0,Sur,Este,Oeste,NoValido};

array <string,3> Vendedores{"CAMILO","ESTELA","TOMAS"};


int main(){
    tTableRegion leerDatos(void);
    bool validar(int codRegion,string vendedor,int mes);
    int getCodeVendedor(string vendedor);
    void mostrarTotales(tTableRegion Data);

    #ifndef NDEBUG
    {//TESTS
        {//TEST VALIDAR
            cout << "Probando Validar():";
            bool validar(string reg,string vend,int mes);
            assert(validar("Sur","Tomas"s,1));
            assert(validar("NORTE","Camilo"s,12));
            assert(validar("este","Estela"s,1));
            assert(validar("OeSTE","Tomas"s,1));
            assert(!validar("SUR","Pepe"s,1));
            assert(!validar("NORTE","Juan"s,1));
            assert(!validar("ESTE","Pepe"s,0));
            assert(!validar("SUR","Pepe"s,13));
            assert(!validar("SURe","Tomas"s,13));
            assert(!validar("ESTE","Jose"s,1));
            cout << "OK\n";
        }
        {//TEST GetCodeVendedor()
            assert(0 == getCodeVendedor("Camilo"));
            assert(1 == getCodeVendedor("Estela"));
            assert(2 == getCodeVendedor("Tomas"));
            assert(-1 == getCodeVendedor("Mauro"));
        }
    }
    #endif
    {//PROGRAM: 4º Modificacion - 100% referencia - call anidado
        tTableRegion& leerDatosRefB(tTableRegion&);
        void mostrarTotalesRef(const tTableRegion&);
        tTableRegion t{0};
        mostrarTotalesRef(leerDatosRefB(t));
    }
    /*{//PROGRAM: 3º modificacion - sin copiar/solo referencias
        void leerDatosRef(tTableRegion&);
        void mostrarTotalesRef(tTableRegion&);
        tTableRegion t{0};
        leerDatosRef(t);
        mostrarTotalesRef(t);
    }
    /*{//PROGRAM: 2º Modificacion - mostrartotales recibe referencia
        tTableRegion leerDatos(void);
        void mostrarTotalesRef(tTableRegion&);
        tTableRegion t{leerDatos()};
        mostrarTotalesRef(t);
    }

    {//PROGRAM: 1º Modificacion - variable receptora
        tTableRegion leerDatos(void);
        void mostrarTotales(tTableRegion);
        tTableRegion t{leerDatos()};
        mostrarTotales(t);
    }

    {//PROGRAM: original
        tTableRegion leerDatos(void);
        void mostrarTotales(tTableRegion);
        mostrarTotales(leerDatos());
    }*/

}

tTableRegion& leerDatosRefB(tTableRegion& ret){
    int Importe;
    string Vendedor, Region;
    int Mes;

    bool validar(string,string,int);
    int getCodeVendedor(string);
    region strToRegion(string Region);
    
    cout << "Por favor ingrese: \n- Importe correspondiente.\n- Mes (1 a 12) \n- Nombre del vendedor (Camilo, Estela o Tomas) \n- Region (Norte, Sur, Este, Oeste)  \n\n(ctrl+D + enter para finalizar)\n\n";      //TODO
   
    while(cin >> Importe >> Mes >> Vendedor >> Region){
       
        int codRegion = static_cast<int>(strToRegion(Region));
        int codVendedor = getCodeVendedor(Vendedor);

        if (validar(Region,Vendedor,Mes)){
            ret.at(codRegion).at(codVendedor).at(Mes-1) += Importe;
            cout << "\nImporte ingresado correctamente. Presione ctrl+D + enter para finalizar o siga ingresando datos:\n";
        }else {
            cout << "\nSe ha ingresado algun dato incorrectamente. Por favor, vuelva a ingresar: (ctrl+D + enter para finalizar)\n";
        }
    }
    return ret;
}

void leerDatosRef(tTableRegion& ret){
    int Importe;
    string Vendedor, Region;
    int Mes;

    bool validar(string,string,int);
    int getCodeVendedor(string);
    region strToRegion(string Region);
    
    cout << "Por favor ingrese: \n- Importe correspondiente.\n- Mes (1 a 12) \n- Nombre del vendedor (Camilo, Estela o Tomas) \n- Region (Norte, Sur, Este, Oeste)  \n\n(ctrl+D + enter para finalizar)\n\n";      //TODO
   
    while(cin >> Importe >> Mes >> Vendedor >> Region){
       
        int codRegion = static_cast<int>(strToRegion(Region));
        int codVendedor = getCodeVendedor(Vendedor);

        if (validar(Region,Vendedor,Mes)){
            ret.at(codRegion).at(codVendedor).at(Mes-1) += Importe;
            cout << "\nImporte ingresado correctamente. Presione ctrl+D + enter para finalizar o siga ingresando datos:\n";
        }else {
            cout << "\nSe ha ingresado algun dato incorrectamente. Por favor, vuelva a ingresar: (ctrl+D + enter para finalizar)\n";
        }
    }
}

tTableRegion leerDatos(){
    int Importe;
    string Vendedor, Region;
    int Mes;
    tTableRegion ret{0};

    bool validar(string,string,int);
    int getCodeVendedor(string);
    region strToRegion(string Region);
    
    cout << "Por favor ingrese: \n- Importe correspondiente.\n- Mes (1 a 12) \n- Nombre del vendedor (Camilo, Estela o Tomas) \n- Region (Norte, Sur, Este, Oeste)  \n\n(ctrl+D + enter para finalizar)\n\n";      //TODO
   
    while(cin >> Importe >> Mes >> Vendedor >> Region){
       
        int codRegion = static_cast<int>(strToRegion(Region));
        int codVendedor = getCodeVendedor(Vendedor);

        if (validar(Region,Vendedor,Mes)){
            ret.at(codRegion).at(codVendedor).at(Mes-1) += Importe;
            cout << "\nImporte ingresado correctamente. Presione ctrl+D + enter para finalizar o siga ingresando datos:\n";
        }else {
            cout << "\nSe ha ingresado algun dato incorrectamente. Por favor, vuelva a ingresar: (ctrl+D + enter para finalizar)\n";
        }
    }
    return ret;
}

int getIndex(string str, array<string, 3> arr){
    for (long unsigned i = 0; i < arr.size() ; i++) {
        if (arr.at(i) == str) return i;
    }
    return -1;
}

int getCodeVendedor(string vendedor) {
    
    string toUpper(string);

    return getIndex(toUpper(vendedor), Vendedores);
}

bool validar(string reg,string vendedor,int mes){
    /**********************************************************
     * INPUT: Codigo de region [0~3]                          *
     *        vendedor string {elementos de array vendedores} *
     *        mes [1~12]                                      *
     * OUTPUT: True si se cumplen las condiciones del input   *
     **********************************************************/
    region strToRegion(string reg);
    int codReg = static_cast<int>(strToRegion(reg));
    int getCodeVendedor(string vendedor);

    return  (codReg >= 0) and (codReg <= 3) and
            (mes > 0 and mes < 13) and (getCodeVendedor(vendedor) >= 0 and getCodeVendedor(vendedor) <= 2);
}   

void mostrarTotales(tTableRegion Data){
    
    array <string,12> nombresMeses{"ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"};
    array <string, 4> nombresRegiones{"Norte", "Sur", "Este", "Oeste"};
    
    cout << "\n\n******************************************* INFORMACION INGRESADA *******************************************";
    int numReg{0};
    for(auto region:Data){
        int numVen{0};
        cout << "\n\nRegion: " << nombresRegiones.at(numReg++) << "\n";  
            cout << "\t\t"; 
            for (auto nombreMes:nombresMeses)
                cout << nombreMes << "\t";        
            for(auto vendedor:region){
                cout << '\n' << Vendedores.at(numVen++) << "\t\t";
                for(auto totalPorMes:vendedor){ 
                cout << totalPorMes << '\t';
            }
        }
    }
    cout << "\n\n**********************************************  ESTADISTICAS  ***********************************************\n";
    string getPeorMes(tTableRegion Data);
    string getMejorMes(tTableRegion Data);
    string getVendedorConMasVentas(tTableRegion tabla);
    array<double,4> getPromedioVentasPorRegion(tTableRegion tabla);
    double getPromedioVentasTotales(tTableRegion);
    string regionToStr(region reg);
    
    cout<< "\nPromedio de ventas por region: \n\t";
    for (int i=0; auto prom:getPromedioVentasPorRegion(Data)){
        cout << regionToStr(region(i++)) << ": " << prom << "\n\t";
    }

    cout << "\nEl importe promedio de ventas en un anio es de pesos: " << getPromedioVentasTotales(Data);
    cout << "\nPEOR mes:\n\t" << getPeorMes(Data)<< "\t\t (Sin separar por zonas ni vendedores)";
    cout << "\nMEJOR mes:\n\t" << getMejorMes(Data)<< "\t (Sin separar por zonas ni vendedores)";
    cout << "\nEl Vendedor con mas ventas totales fue:\n\t" << getVendedorConMasVentas(Data);
    cout << "\n\n*********************************************  FIN DE INFORME  **********************************************\n\n";
}

void mostrarTotalesRef(const tTableRegion& Data){
    
    array <string,12> nombresMeses{"ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"};
    array <string, 4> nombresRegiones{"Norte", "Sur", "Este", "Oeste"};
    cout << "\n\n******************************************* INFORMACION INGRESADA *******************************************";
    int numReg{0};
    for(auto region:Data){
        int numVen{0};
        cout << "\n\nRegion: " << nombresRegiones.at(numReg++) << "\n";  
            cout << "\t\t"; 
            for (auto nombreMes:nombresMeses)
                cout << nombreMes << "\t";        
            for(auto vendedor:region){
                cout << '\n' << Vendedores.at(numVen++) << "\t\t";
                for(auto totalPorMes:vendedor){ 
                cout << totalPorMes << '\t';
            }
        }
    }
    cout << "\n\n**********************************************  ESTADISTICAS  ***********************************************\n";
    string getPeorMes(tTableRegion Data);
    string getMejorMes(tTableRegion Data);
    string getVendedorConMasVentas(tTableRegion tabla);
    array<double,4> getPromedioVentasPorRegion(tTableRegion tabla);
    double getPromedioVentasTotales(tTableRegion);
    string regionToStr(region reg);
    
    cout<< "\nPromedio de ventas por region: \n\t";
    for (int i=0; auto prom:getPromedioVentasPorRegion(Data)){
        cout << regionToStr(region(i++)) << ": " << prom << "\n\t";
    }


    cout << "\nEl importe promedio de ventas en un anio es de pesos: " << getPromedioVentasTotales(Data);
    cout << "\nPEOR mes:\n\t" << getPeorMes(Data)<< "\t\t (Sin separar por zonas ni vendedores)";
    cout << "\nMEJOR mes:\n\t" << getMejorMes(Data)<< "\t (Sin separar por zonas ni vendedores)";
    cout << "\nEl Vendedor con mas ventas totales fue:\n\t" << getVendedorConMasVentas(Data);
    cout << "\n\n*********************************************  FIN DE INFORME  **********************************************\n\n";
    
}

region strToRegion(string reg){
    /*  PASA DE CADENA A ENUM REGION - NO CASE SENSITIVE !! 
     ************************************************************************
     *  INPUT: Nombre de region en mayusculas o minusculas como string      *
     * OUTPUT: Region como enum struc - NoValido para no identificados      *
     * **********************************************************************/
    string toUpper(string);
    reg = toUpper(reg);
    return
        reg=="NORTE" or reg =="0"? region::Norte :
        reg=="SUR" or reg =="1"? region::Sur :
        reg=="ESTE" or reg =="2"? region::Este :
        reg=="OESTE" or reg =="3"? region::Oeste : region::NoValido;
}

string regionToStr(region reg){/*   Obtiene un string equivalente al enum region
    INPUT:  enum{Norte,Sur,Este,Oeste,NoValido}
    OUTPUT: String
    */
   
    return
        reg==region::Norte?  "Norte" :
        reg==region::Sur?  "Sur" :
        reg==region::Este?  "Este" :
        reg==region::Oeste?  "Oeste" :  "Error" ;
}

string toUpper(string str){   /* DEVUELVE LA CADENA DADA COMO UPPERCASE
    ************************************************************
    INPUT: Cadena de texto general
    OUTPUT: Cadena de texto en mayusculas
    ***********************************************************/
    string out="";
    for (auto c:str)
        out += toupper(c);
    return out;
}

// --------- FUNCIONES ESTADISTICAS ----------

string getPeorMes(tTableRegion Data){  /* Computa y analiza cual fue el peor mes sin importar la region ni el vendedor
        INPUT: Datos como arrays anidados [ region(vendedor(mes)) ]
        OUTPUT: String con el peor mes y monto en formato:
                "mes: monto_total"
    */   
    array <int,12> accumuladoPorMes(tTableRegion Data);
    array <string,12> nombresMeses{"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    int minMesID=0, minMesAcc=2147483647;  // Se podria usar limits.h para no hardcodear?
    for(int i=0;int monto:accumuladoPorMes(Data))
        if (monto < minMesAcc){
            minMesID = i++;
            minMesAcc = monto;
        }
    
    return nombresMeses.at(minMesID) + ": $" + to_string(minMesAcc);
    
}
string getMejorMes(tTableRegion Data){  /* Computa y analiza cual fue el peor mes sin importar la region ni el vendedor
        INPUT: Datos como arrays anidados [ region(vendedor(mes)) ]
        OUTPUT: String con el mejor mes y monto en formato:
                "mes: monto_total"
    */
    array <int,12> accumuladoPorMes(tTableRegion Data);
    array <string,12> nombresMeses{"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    int maxMesID=0, maxMesAcc=0; 
    for(int i=0;int monto:accumuladoPorMes(Data))
        if (monto > maxMesAcc){
            maxMesID = i++;
            maxMesAcc = monto;
        }
    
    return nombresMeses.at(maxMesID) + ": $" + to_string(maxMesAcc);
}

array <int,12> accumuladoPorMes(tTableRegion Data){ /*Calcula el acomulado para todos los meses sin discriminar region ni vendedor
    INPUT: 
*/
    array <int,12> accMes{0};
    for (auto region:Data)
        for (auto vendedor:region)
            for (int i=0; auto ventaMes:vendedor)
                accMes.at(i++)+=ventaMes;
    return accMes;
}

void getPromedioVendedorPorRegion(tTableRegion tabla){  
    array<array<int, 3>, 4> getTotalesVendedorPorRegion(tTableRegion tablaTotales);
    array<int, 3> totalPorVendedor{0};
    for(auto totalesPorVendedor:getTotalesVendedorPorRegion(tabla)){
        for(int i1=0; auto total:totalesPorVendedor){
            totalPorVendedor.at(i1) += total;
            ++i1;
        };
    };
    for(int i2=0; auto total:totalPorVendedor){
       cout << "\nPromedio del vendedor " << Vendedores.at(i2) << " por region es: " << (total /4) << "\n";
       ++i2;
    };
}
string getVendedorConMasVentas(tTableRegion tabla){ // Retorna quien vendio, en total entre meses y regiones, el monto mayor
    /*
        INPUT: Datos como arrays anidados [ region(vendedor(mes)) ]
        OUTPUT:  Vendedor con mejor ventas totales en formato:
                "vendedor: monto"
    */
    int maxNumVend=0;
    int maxAccVend=0;
    int nVend=0;
    for (auto region:tabla ){
        int CurrAccVend=0;
        for (auto vendedor:region)
            for (auto ventaMes:vendedor)
                CurrAccVend += ventaMes;    

        if (CurrAccVend>maxAccVend){
            maxAccVend=CurrAccVend;
            maxNumVend=nVend;
        }
        nVend++;
    }
    return Vendedores.at(maxNumVend) + ": "s + to_string(maxAccVend);
}

void getVendedorConMasVentas2(tTableRegion tabla){    
    array<array<int, 3>, 4> getTotalesVendedorPorRegion(tTableRegion tablaTotales);
    array<int, 3> totalPorVendedor{0};
    for( auto totalesPorVendedor:getTotalesVendedorPorRegion(tabla)){
        for(int i1=0; auto total:totalesPorVendedor){
            totalPorVendedor.at(i1) += total;
            ++i1;
        };
    };
    int maxVentasVendedor=0, maxVendedorIndex=0; 
    for (int i2=0; auto total:totalPorVendedor){
        if(maxVentasVendedor < total){
            maxVendedorIndex = i2;
            maxVentasVendedor = total;
        }
        ++i2;

    }
    cout << "\n\nEl vendedor con mas ventas es: " << Vendedores.at(maxVendedorIndex) << "\n";
}

void getMejorRegion(tTableRegion tabla){    
    array <string, 4> nombresRegiones{"Norte", "Sur", "Este", "Oeste"};
    array<array<int, 3>, 4> getTotalesVendedorPorRegion(tTableRegion tablaTotales);
    int maxRegionVentas=0;
    int maxRegionIndex=0;
    for(int i=0; auto totalesPorVendedor:getTotalesVendedorPorRegion(tabla)){
    int totalRegion=0;
        for(auto total:totalesPorVendedor){
            totalRegion += total;
        };
        if(maxRegionVentas < totalRegion){
            maxRegionIndex = i;
            maxRegionVentas = totalRegion;
        }
        ++i;
    };
    cout << "\nLa mejor region es: " << nombresRegiones.at(maxRegionIndex) << "\n";
}

array<array<int, 3>, 4> getTotalesVendedorPorRegion(tTableRegion tablaTotales){ 
    array<array<int, 3>, 4> totalesVendedorPorRegion{0};
    for(int i1=0; auto totalesPorRegiones:tablaTotales){
        for(int i2=0; auto totalesPorVendedores:totalesPorRegiones){
            int totalPorVendedor=0;
            for(auto totalesPorMes:totalesPorVendedores){
                totalPorVendedor+=totalesPorMes;
            };
            totalesVendedorPorRegion.at(i1).at(i2) = totalPorVendedor;
            ++i2;
        }
        ++i1;
    }
    return totalesVendedorPorRegion;
}

array<double,4>  getPromedioVentasPorRegion(tTableRegion tabla){    /* Retorna un array con los promedios por region
        INPUT: Datos como arrays anidados [ region(vendedor(mes)) ]
        OUTPUT: Array con los promedios para cada region
    */
    array<int,4>totalesVentasPorRegion{0};

    for (int NumReg=0; auto region:tabla){ 
        for (auto vendedor:region)
            for (auto ventaMes:vendedor)
                totalesVentasPorRegion.at(NumReg) += ventaMes;
        NumReg++;
    }
    array<double,4>promedios{0};
    for(int i=0; auto tot:totalesVentasPorRegion){
        promedios.at(i++) = tot/36.;
    }
    return promedios;
}

double getPromedioVentasTotales(tTableRegion tabla){    /* Retorna el promedio de todas las ventas para todos los meses
        INPUT: Datos como arrays anidados [ region(vendedor(mes)) ]
        OUTPUT: double con el promedio
    */
    double acumuladoMesVendedorRegion{0};
    for (auto region:tabla){ 
        for (auto vendedor:region){
            for (auto ventaMes:vendedor)
                acumuladoMesVendedorRegion += ventaMes;
        }
    }   
    return (acumuladoMesVendedorRegion/144.0);
}
