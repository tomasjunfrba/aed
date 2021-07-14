#include <iostream>
#include <cassert>
using namespace std;

int IngresoMes();
int IngresoAno();
void ValidacionMesAno(int mes, int ano);
bool IsBisiesto(int ano);
int GetCantidadDeDias(int mes, int ano);

int main()
    {
    
    assert (GetCantidadDeDias(2, 1900) == 28);
    assert (GetCantidadDeDias(2, 2000) == 29);
    assert (GetCantidadDeDias(3, 1995) == 31);
    assert (GetCantidadDeDias(9, 2021) == 30);
    assert (IsBisiesto(1904));
    assert (IsBisiesto(2196));
    assert (IsBisiesto(2100) == false);
    assert (IsBisiesto(2200) == false);

    int mes = IngresoMes();
    int ano = mes == 2? IngresoAno(): 1995;
    ValidacionMesAno(mes, ano);
    }

    int IngresoMes()
            {
            cout << "Ingrese un mes: ";
            int mes;
            cin >> mes;
            return mes;
            }

    int IngresoAno()
            {
            cout << "Ingrese un anio: ";
            int ano;
            cin >> ano;
            return ano;
            }

    void ValidacionMesAno(int mes, int ano)
            {
            mes < 1 or mes > 12 ? cout << "El mes ingresado es invalido, ingrese un mes entre 1 y 12.":
            ano < 1583 or ano > 3021 ? cout << "El anio ingresado no cumple con los parametros, ingrese un anio entre 1583 y 3021.":
            cout << "La cantidad de dias que tiene el mes ingresado es de: " << GetCantidadDeDias(mes, ano);
            }

    bool IsBisiesto (int ano)
            {
            return (ano % 4 == 0) and (ano % 100 != 0 or ano % 400 == 0);
            }   

    int GetCantidadDeDias(int mes, int ano)
            {
            return 
            mes == 2 and IsBisiesto(ano)? 29:
            mes == 2 and not IsBisiesto(ano)? 28:
            mes == 4 or mes == 6 or mes == 9 or mes == 11? 30:
            31;
            }